// Server function
#include"pch.h"
#include"Server.h"
#include<Windows.h>
#include<WinSock2.h>
#include <Ws2tcpip.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>

using namespace std;


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


