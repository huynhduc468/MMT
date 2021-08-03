#ifndef _SERVER_H_
#define _SERVER_H_
#define WIN32_LEAN_AND_MEAN

#include<Windows.h>
#include<WinSock2.h>
#include <Ws2tcpip.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<sstream>

#pragma comment(lib,"Ws2_32.lib")

#define PORT "0601"
#define DEFAULT_BUFLEN 1201

using namespace std;

bool CheckLogIn(SOCKET ClientSocket);


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
