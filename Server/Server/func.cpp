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