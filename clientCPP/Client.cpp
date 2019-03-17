#include "pch.h"
#include "Client.h"
#include "AESENC.h"

void Client::configServerInfo()
{
	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	// Ininilize sServer IP address , port .
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(13000);
}

// Implement of connect to server.
void Client::connetToServer() {
	// Try to connect to server 
	connect(server, (SOCKADDR *)&addr, sizeof(addr));
	std::cout << "Connected to server!\n";
	char ad[] = { 's','f' };
}

//
void Client::sendMessage() {
	// Get object of AESENCRYPT class

	// Message to send server.
	char request[] = { 'w', 'o', 'r', 'd', '5', ' ', 'W', 'o', 'r', 'l', 'd', '.' , '.', '.', '.', '.' };
	//char af[] = { 'a', 'e', '4', '9', 'd', ' ', ' W', 'o', 'r', 'l', 'd', '.' , '.', '.', '.', '.' };
	char request2[] = { 'a' , 'v' , 's' , 'd' , 'a' , 'd' , 'g' , 'g' , 'h' , 'j' ,'l' ,'P' , 'j' , 'd' , 'q' ,'w' };
	char request4[] = { '1' , 'v' , 's' , '3' , 'a' , 'd' , 'g' , 'g' , 'h' , 'j' ,'l' ,'5' , 'j' , 'd' , 'q' ,'w' };

	// Copy message to indata
	unsigned char indata[16];
	strcpy((char*)indata, request);

	// Get size of message
	int byte_read = sizeof(indata);

	// Encrypt message
	AESENC aesenc;

	//unsigned char *out1 = aesenc.Encryption(indata);
	char *out = (char *)aesenc.Encryption((char*)request);

	// Send message request to server
	send(server, (char*)request, sizeof(request), 0);

	//cout << "sent request to server : ";
	for (int i = 0; i < 4; ++i)
	{
		std::cout << request[i] ;
	}
	std::cout << "\n";

	char buffer[AES_BLOCK_SIZE];
	char outdata[AES_BLOCK_SIZE];
	recv(server, buffer, sizeof(buffer), 0);

	char *res = (char *)aesenc.Decryption(request2);


	std::cout << "server response is : " << outdata << "\n";

	// Disconnect server.
	closesocket(server);
	WSACleanup();

	//	return 0;
}