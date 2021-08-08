#include "pch.h"
#include "Client.h"
#include<WinSock2.h>
#include <ws2tcpip.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string>
#include<iostream>

using namespace std;

void registration(SOCKET ConnectSocket)
{
	char msg[DEFAULT_BUFLEN];
	int msgLen;
	int iResult = 0;

	// Receive message from server: 1."Registration" 2."Username" 3."Password"
	iResult = recv(ConnectSocket, msg, DEFAULT_BUFLEN, 0);
	if (iResult < 0) cout << "fail to receive, error: " << WSAGetLastError() << endl;
	msg[iResult] = '\0';
	cout << msg << endl;

	// Receive and send again username & password
	for (int i = 0;i < 2;i++)
	{
		iResult = recv(ConnectSocket, msg, DEFAULT_BUFLEN, 0);
		if (iResult < 0) cout << "fail to receive, error: " << WSAGetLastError() << endl;
		msg[iResult] = '\0';
		cout << msg;

		cin.getline(msg, 100);
		iResult = send(ConnectSocket, msg, strlen(msg), 0);
		if (iResult == SOCKET_ERROR) cout << "fail to send msg" << endl;
	}

	
	// Receive announcement from server if account exist, msg="true" means yes.
	iResult = recv(ConnectSocket, msg, DEFAULT_BUFLEN, 0);
	if (iResult < 0) cout << "fail to receive, error: " << WSAGetLastError() << endl;
	msg[iResult] = '\0';
	cout << msg;
	cout << endl;

	return;
}