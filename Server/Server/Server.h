#pragma once
#ifndef _SERVER_H_
#define _SERVER_H_
#define WIN32_LEAN_AND_MEAN

#include<Windows.h>
#include<WinSock2.h>
#include <Ws2tcpip.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

#pragma comment(lib,"Ws2_32.lib")

#define PORT "0601"
#define DEFAULT_BUFLEN 512

using namespace std;
#endif // !_SERVER_H_

#ifdef __cplusplus
extern "C" {
#endif
	void WSAAPI freeaddrinfo(struct addrinfo*);

	int WSAAPI getaddrinfo(const char*, const char*, const struct addrinfo*,
		struct addrinfo**);

	int WSAAPI getnameinfo(const struct sockaddr*, socklen_t, char*, DWORD,
		char*, DWORD, int);
	int WSAAPI inet_pton(INT, PCSTR, PVOID);
#ifdef __cplusplus
}
#endif

#include "resource.h"
bool checkInformation(string path, string username, string password);
void registration(SOCKET ClientSocket);
void WriteToFile(string path, string username, string password);
void sendRecvacc(SOCKET ClientSocket, string& username, string& password);


// This function find the covid information of a particular country
void exportCovidInfo(string file_name);