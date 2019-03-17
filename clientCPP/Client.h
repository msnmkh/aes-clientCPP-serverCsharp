#pragma once
#ifndef CLIENT_CLASS
#define CLIENT_CLASS

#include <winsock2.h>
#include <iostream>
#pragma warning(disable:4996)

class Client
{
public:
	WSADATA WSAData;
	SOCKET server;
	SOCKADDR_IN addr;

	void configServerInfo();
	void connetToServer();
	void sendMessage();
};

#endif

