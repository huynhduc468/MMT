#include"Client.h"

int main() {
	WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo* result = NULL, * ptr = NULL, hints;
	int iResult;
	int recvbuflen = DEFAULT_BUFLEN;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	iResult = getaddrinfo("127.0.0.1", PORT, &hints, &result);
	if (iResult != 0) {
		cout << "Getaddrinfo failed: " << iResult;
		WSACleanup();
		return 1;
	}

	// Attempt to connect to an address until one succeeds
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			printf("socket failed with error: %ld\n", WSAGetLastError());
			WSACleanup();
			return 1;
		}

		// Connect to server.
		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		return 1;
	}
	cout << "\t\tSEARCH INFORMATION ABOUT COVD-19 PASSION IN COUNTRIES IN THE WORLD\n";
	cout << "_________________________________________________________________________________\n";
	char choosen[2] = { '0' };
	char tmp[100] = { "0" };
	cout << "\t\t\t=============MENU=============\n";
	cout << "\t\t\t\t1.Log in\n";
	cout << "\t\t\t\t2.Registration\n";
	cout << "\t\t\t\t0. Exit\n";
	do {
		cout << "Enter yout opt: ";
		cin.getline(tmp, 100);
	} while (strlen(tmp) >= 2 && (tmp[0] != '0' || tmp[0] != '1' || tmp[0] != '2'));
	choosen[0] = tmp[0];
	choosen[1] = '\n';
	send(ConnectSocket, choosen, 2, 0);
	while (choosen[0] == '1' || choosen[0] == '2') {
		switch (choosen[0]) {
		case '1':
			if (LogIn(ConnectSocket) == 1) {
				char ch[2] = { "0" };
				cout << "\n\t\t\t=============MENU=============\n";
				cout << "\t\t\t\t1. Search information\n";
				cout << "\t\t\t\t0. Exit\n";
				do {
					cout << "Enter yout opt: ";
					cin.getline(tmp, 100);
				} while (strlen(tmp) >= 2 && (tmp[0] != '0' || tmp[0] != '1'));
				ch[0] = tmp[0];
				ch[1] = '\n';
				send(ConnectSocket, ch, 2, 0);
				switch (ch[0])
				{
				case '1':
					DoSomeThing(ConnectSocket);
					break;
				case '0':break;
				}
			}
			else cout << "Log in Failed !!!\n";
			break;
		case '2':
			registration(ConnectSocket);
			break;
		case '0':break;
		}
		cout << "\t\t\t=============MENU=============\n";
		cout << "\t\t\t\t1.Log in\n";
		cout << "\t\t\t\t2.Registration\n";
		cout << "\t\t\t\t0. Exit\n";
		do {
			cout << "Enter yout opt: ";
			cin.getline(tmp, 100);
		} while (strlen(tmp) >= 2 && (tmp[0] != '0' || tmp[0] != '1' || tmp[0] != '2'));
		choosen[0] = tmp[0];
		choosen[1] = '\n';
		send(ConnectSocket, choosen, 2, 0);
	}

	// shutdown the connection for sending since no more data will be sent
	// the client can still use the ConnectSocket for receiving data
	iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

}