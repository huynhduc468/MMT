#pragma once

#include "resource.h"
#ifndef _CLIENT_H_
#define _CLIENT_H_

#define WIN32_LEAN_AND_MEAN

#endif

#include "pch.h"
#include "Client.h"
#include<WinSock2.h>
#include <ws2tcpip.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<iostream>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

using namespace std;



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
void registration(SOCKET ConnectSocket);
bool closeConnection(SOCKET& ConnectSocket);
