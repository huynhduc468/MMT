#include"Server.h"

int main() {
	WSADATA wsaData;
	int iResult;

	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;
	DWORD threadID;
	HANDLE threadStatus;

	struct addrinfo* result = NULL;
	struct addrinfo hints;

	int iSendResult;
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	do {
		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		hints.ai_flags = AI_PASSIVE;

		if (getaddrinfo(NULL, PORT, &hints, &result) != 0) {
			cout << "Getaddrinfo failed\n";
			WSACleanup();
			return 1;
		}

		ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
		if (ListenSocket == INVALID_SOCKET) {
			cout << "Error at socket(): " << WSAGetLastError();
			WSACleanup();
			return 1;
		}

		iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			cout << "Bind failed with error: " << WSAGetLastError();
			freeaddrinfo(result);
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
		}

		freeaddrinfo(result);

		if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
			cout << "Listen failed with error: " << WSAGetLastError();
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
		}

		ClientSocket = accept(ListenSocket, NULL, NULL);
		if (ClientSocket == INVALID_SOCKET) {
			cout << "Accept failed: " << WSAGetLastError();
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
		}

		closesocket(ListenSocket);

		SOCKET* hConnected = new SOCKET();
		*hConnected = ClientSocket;
		threadStatus = CreateThread(NULL, 0, function, hConnected, 0, &threadID);
	} while (1);

	// shutdown the connection since we're done
	iResult = shutdown(ClientSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		return 1;
	}

	// cleanup
	closesocket(ClientSocket);
	WSACleanup();

	return 0;
}