#ifndef _SERVER_H_
#define CURL_STATICLIB
#define _SERVER_H_
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include "curl/curl.h"
#include <fstream>
#include <thread>

#ifdef _DEBUG
#pragma comment (lib,"curl/libcurl_a_debug.lib")
#else
#pragma comment (lib,"curl/libcurl_a.lib")
#endif

#pragma comment (lib, "Normaliz.lib")
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Wldap32.lib")
#pragma comment (lib, "Crypt32.lib")
#pragma comment (lib, "advapi32.lib")

#define PORT "0601"
#define DEFAULT_BUFLEN 1201


using namespace std;

void exportCovidInfo(SOCKET ClientSocket, string path);

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

