#ifndef _CLIENT_H_
#define _CLIENT_H_

#define WIN32_LEAN_AND_MEAN

#include<WinSock2.h>
#include <ws2tcpip.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<iostream>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define PORT "0601"
#define DEFAULT_BUFLEN 1201
#define Size 10

using namespace std;

bool LogIn(SOCKET ConnectServer);
void registration(SOCKET ConnectSocket);
void DoSomeThing(SOCKET ConnectServer);

#endif // !_CLIENT_H_

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