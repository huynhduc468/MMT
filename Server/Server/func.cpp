#include"Server.h"

//Login
bool CheckSame(string A, string B) {
	return(A == B);
}
bool CheckLogIn(SOCKET ClientSocket) {
	int uNameSize = 100, passSize = 100, isStop;
	char iStop[1];
	do {
		char username[100] = { "0" }, password[100]{ "0" };
		iStop[0] = { '0' };
		cout << "\n1\n";
		int isRecv = recv(ClientSocket, username, uNameSize, 0);
		cout << username << endl;
		if (isRecv != 0) {
			cout << "\n2";
			cout << endl << username << endl;
			int temp = 0;
			fstream fCheck("User.txt");

			stringstream line;
			string tmp, uNameTmp, PassTmp;

			while (getline(fCheck, tmp)) {
				line.clear();
				line.str(tmp);
				getline(line, uNameTmp, ',');
				getline(line, PassTmp, '\n');
				if (CheckSame((string)username, uNameTmp) == 1) {
					temp = 1;
					send(ClientSocket, "1", 1, 0);
					isRecv = recv(ClientSocket, password, passSize, 0);
					cout << password << endl;
					if (isRecv != 0) {
						if (CheckSame((string)password, PassTmp) == 1) {
							send(ClientSocket, "1", 1, 0);
							isStop = recv(ClientSocket, iStop, 1, 0);
							return 1;
						}
						else {
							send(ClientSocket, "0", 1, 0);
							isStop = recv(ClientSocket, iStop, 1, 0);
							break;
						}
					}
					else {
						send(ClientSocket, "0", 1, 0);
						isStop = recv(ClientSocket, iStop, 1, 0);
						break;
					}
				}
			}
			if (temp == 1) {
				break;
			}
			else {
				send(ClientSocket, "0", 1, 0);
				isStop = recv(ClientSocket, iStop, 1, 0);
			}
		}
		else {
			send(ClientSocket, "0", 1, 0);
			isStop = recv(ClientSocket, iStop, 1, 0);
			cout << iStop;
		}
	} while (iStop[0] == '1');

	return 0;
}

// This function write new account to file.
void WriteToFile(string path, string username, string password)
{
	ofstream fout;
	fout.open(path, ios::end);
	if (fout.is_open() == false)
	{
		cout << "File User.txt cannot open" << endl;
	}
	else
	{
		fout << username << "," << password;
		fout << endl;
	}
	fout.close();
}
// This function send and receive account from client
void sendRecvacc(SOCKET ClientSocket, string& username, string& password)
{
	char msg[DEFAULT_BUFLEN];
	int iResult;

	// Send msg and receive username from client
	strcpy_s(msg, "Username: ");
	iResult = send(ClientSocket, msg, strlen(msg), 0);
	if (iResult == SOCKET_ERROR)
		cout << "send failed with error: " << WSAGetLastError() << endl;

	iResult = recv(ClientSocket, msg, DEFAULT_BUFLEN, 0);
	if (iResult < 0) cout << "receive message fail (username), error: " << WSAGetLastError();
	msg[iResult] = '\0';
	username = string(msg);


	// Send msg and receive password from client
	strcpy_s(msg, "Password: ");
	iResult = send(ClientSocket, msg, strlen(msg), 0);
	if (iResult == SOCKET_ERROR)
		cout << "send failed with error: " << WSAGetLastError() << endl;

	iResult = recv(ClientSocket, msg, DEFAULT_BUFLEN, 0);
	if (iResult < 0) cout << "receive message fail (password), error: " << WSAGetLastError();
	msg[iResult] = '\0';
	password = string(msg);

}
// Check if username & password registered existed (return true if existed)
bool checkInformation(string path, string username, string password)
{
	ifstream fin;
	fin.open(path);
	stringstream s;
	string str;
	string temp;

	//flag true if username, password exist.
	bool flag = false;
	if (fin.is_open() == false)
	{
		cout << "File User.txt cannot open" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			getline(fin, str);
			if (str != "")
			{
				s = stringstream(str);
				getline(s, temp, ',');
				if (temp == username)
				{
					flag = true; break;
				}
				getline(s, temp, ',');
				if (temp == password) {
					flag = true;
					break;
				}
			}

		}
	}
	fin.close();
	return flag;
}
// Registration function client.
void registration(SOCKET ClientSocket)
{
	//Send message to client
	char msg[DEFAULT_BUFLEN];
	int iResult = 0;
	string username = "", password = "";

	strcpy_s(msg, "Registration");
	iResult = send(ClientSocket, msg, strlen(msg), 0);
	if (iResult == SOCKET_ERROR)
		cout << "send failed with error: " << WSAGetLastError() << endl;

	sendRecvacc(ClientSocket, username, password);

	string path = "User.txt";

	if (checkInformation(path, username, password) == true)
	{//Send message true to client to announce that the account existed.
		strcpy_s(msg, "true");
		iResult = send(ClientSocket, msg, strlen(msg), 0);
		if (iResult == SOCKET_ERROR)
			cout << "send failed with error: " << WSAGetLastError() << endl;
	}


	//Check if the account exist if yes then resend the message until the account is new !!
	while (checkInformation(path, username, password) == true)
	{
		//Send message to client

		// Send message to client!
		strcpy_s(msg, "Someone registered this account. Please create again! \n");
		iResult = send(ClientSocket, msg, strlen(msg), 0);
		if (iResult == SOCKET_ERROR)
			cout << "send failed with error: " << WSAGetLastError() << endl;

		sendRecvacc(ClientSocket, username, password);


	}



	// Register successful. Write the new account into file User.txt
	strcpy_s(msg, "false");
	iResult = send(ClientSocket, msg, strlen(msg), 0);
	if (iResult == SOCKET_ERROR)
		cout << "send failed with error: " << WSAGetLastError() << endl;


	strcpy_s(msg, "Your registration is successful!");
	iResult = send(ClientSocket, msg, strlen(msg), 0);
	if (iResult == SOCKET_ERROR)
		cout << "send failed with error: " << WSAGetLastError() << endl;

	WriteToFile(path, username, password);

}

//TakeData
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
void TakeData() {
	CURL* curl;
	CURLcode res;
	std::string readBuffer;

	curl_global_init(CURL_GLOBAL_DEFAULT);

	curl = curl_easy_init();
	if (curl) {
		std::ofstream fout("output.json", std::ios_base::out);
		curl_easy_setopt(curl, CURLOPT_URL, "https://coronavirus-19-api.herokuapp.com/countries");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		fout << readBuffer << std::endl;

		fout.close();
	}
}

DWORD WINAPI function(LPVOID arg) {
	SOCKET* hConnected = (SOCKET*)arg;
	SOCKET ClientSocket = *hConnected;

	char dt[20] = { "0" };
	recv(ClientSocket, dt, 20, 0);

	if (dt[0] != '0') {
		TakeData();
		exportCovidInfo(ClientSocket, (string)dt);
	}
	else {
		send(ClientSocket, "0", 1, 0);
		cout << "\nFailed !!!";
	}

	return 0;
}