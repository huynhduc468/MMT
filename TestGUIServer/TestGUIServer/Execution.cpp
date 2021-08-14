#include"MyForm.h"

using namespace System;;
using namespace System::Windows::Forms;

bool CheckSame(string A, string B) {
	return(A == B);
}
bool LognIn(SOCKET ClientSocket) {
		char acc[100] = { "0" }, pass[100] = { "0" };
		fstream fCheck("User.txt", ios_base::in);
		int isResult = recv(ClientSocket, acc, 100, 0);
		if (isResult != 0) {
			int temp = 0;

			stringstream line;
			string tmp, uNameTmp, PassTmp;

			while (getline(fCheck, tmp)) {
				line.clear();
				line.str(tmp);
				getline(line, uNameTmp, ',');
				getline(line, PassTmp, '\n');
				if (CheckSame((string)acc, uNameTmp) == 1) {
					temp = 1;
					send(ClientSocket, "1", 1, 0);
					isResult = recv(ClientSocket, pass, 100, 0);
					if (isResult != 0) {
						if (CheckSame((string)pass, PassTmp) == 1) {
							send(ClientSocket, "1", 1, 0);
							fCheck.close();
							return 1;
						}
						else {
							send(ClientSocket, "0", 1, 0);
							fCheck.close();
							return 0;
						}
					}
					else {
						send(ClientSocket, "0", 1, 0);
						fCheck.close();
						return 0;
					}
				}
			}
			if (temp == 0) {
				send(ClientSocket, "0", 1, 0);
				fCheck.close();
				return 0;
			}
		}
		else {
			send(ClientSocket, "0", 1, 0);
			fCheck.close();
			return 0;
		}

		fCheck.close();
		return 0;
	}
void WriteToFile(string path, string username, string password) {
		ofstream fout;
		fout.open(path, ios::app);
		if (fout.is_open() == true) {
			fout << username << "," << password;
			fout << endl;
		}
		fout.close();
	}
bool checkInformation(string path, string username, string password) {
	ifstream fin;
	fin.open(path);
	stringstream s;
	string str;
	string temp;

	//flag true if username, password exist.
	bool flag = false;

	if (fin.is_open() == true) {
		while (getline(fin, str)) {
			if (str != "") {
				s.clear();
				s.str(str);

				getline(s, temp, ',');
				if (temp == username) {
					flag = true;
					break;
				}
			}
		}
	}
	fin.close();
	return flag;
}
void registration(SOCKET ClientSocket) {
		char acc[DEFAULT_BUFLEN] = { "0" }, pass[DEFAULT_BUFLEN] = { "0" };
		int iResult = 0;
		string username = "", password = "";

		recv(ClientSocket, acc, DEFAULT_BUFLEN, 0);
		username = string(acc);
		recv(ClientSocket, pass, DEFAULT_BUFLEN, 0);
		password = string(pass);

		string path = "User.txt";

		if (checkInformation(path, username, password) == false) {
			//Send message true to client to announce that the account existed.
			iResult = send(ClientSocket, "1", 1, 0);
			WriteToFile(path, username, password);
			return;
		}
		else {
			iResult = send(ClientSocket, "0", 1, 0);
			return;
		}
	}

void Execution() {
	WSADATA wsaData;
	DWORD threadID;
	HANDLE threadStatus;
	int iResult;
	ifstream fCheck("User.txt");
	fCheck.close();
	TakeData();
	struct addrinfo* result = NULL;
	struct addrinfo hints;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		MessageBox::Show("WSAStartup failed with error: " + System::Convert::ToString(iResult), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		Application::Exit();
	}

	do {
		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		hints.ai_flags = AI_PASSIVE;

		if (getaddrinfo(NULL, PORT, &hints, &result) != 0) {
			MessageBox::Show("Getaddrinfo failed: ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			WSACleanup();
			Application::Exit();
		}

		ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
		if (ListenSocket == INVALID_SOCKET) {
			MessageBox::Show("Error at socket(): " + System::Convert::ToString(WSAGetLastError()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			WSACleanup();
			Application::Exit();
		}

		iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			MessageBox::Show("Bind failed with error: " + System::Convert::ToString(WSAGetLastError()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			freeaddrinfo(result);
			closesocket(ListenSocket);
			WSACleanup();
			Application::Exit();
		}

		freeaddrinfo(result);

		if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
			MessageBox::Show("Listen failed with error: " + System::Convert::ToString(WSAGetLastError()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			closesocket(ListenSocket);
			WSACleanup();
			Application::Exit();
		}

		ClientSocket = accept(ListenSocket, NULL, NULL);
		if (ClientSocket == INVALID_SOCKET) {
			MessageBox::Show("Accept failed: " + System::Convert::ToString(WSAGetLastError()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			closesocket(ListenSocket);
			WSACleanup();
			Application::Exit();
		}

		closesocket(ListenSocket);

		/*ListViewItem^ listClient = gcnew ListViewItem;
		listClient->Text = "Client " + System::Convert::ToString(++i);
		listClient->SubItems->Add("Connected");
		time_t now = time(0);
		char* timeNow = ctime(&now);
		listClient->SubItems->Add(System::Convert::ToString(gcnew String(timeNow)));
		view->Items->Add(listClient);*/

		SOCKET* hConnected = new SOCKET();
		*hConnected = ClientSocket;
		threadStatus = CreateThread(NULL, 0, function, hConnected, 0, &threadID);
	} while (true);
}

DWORD WINAPI function(LPVOID arg) {
	SOCKET* hConnected = (SOCKET*)arg;
	SOCKET ClientSocket = *hConnected;
	
	char tmp[1] = { '0' };
	recv(ClientSocket, tmp, 1, 0);
	do {
		switch (tmp[0]) {
		case '1':
			if (LognIn(ClientSocket) == 1) {
				char isContinue[1] = { '0' };
				recv(ClientSocket, isContinue, 1, 0);
				do {
					if (isContinue[0] == '1') {
						char country[50] = { "0" };
						recv(ClientSocket, country, 50, 0);
						if (country[0] == '0') break;
						else {
							string CountryTmp = string(country);
							exportCovidInfo(ClientSocket, CountryTmp);
						}
					}
					else break;
					recv(ClientSocket, isContinue, 1, 0);
				} while (isContinue[0] != '0');
			}
			break;
		case '2':
			registration(ClientSocket);
			break;
		case '0':break;
		}
		recv(ClientSocket, tmp, 1, 0);
	} while ((tmp[0] != '0'));

	return 0;
}