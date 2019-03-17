
#include "pch.h"
#include "AESENC.h"
#include "Client.h"
#include <iostream>

int main()
{	// Create object of class client
	Client client;

	// Config server information
	client.configServerInfo();

	// Connect to server 
	client.connetToServer();

	// Send message to server and get response
	client.sendMessage();

	return 0;
  //  std::cout << "Hello World!\n"; 
}

