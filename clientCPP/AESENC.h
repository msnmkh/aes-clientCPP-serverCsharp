#pragma once
#ifndef AESENC_CLASS
#define AESENC_CLASS
#include <openssl/aes.h>
#include <iostream>

//extern unsigned char outdata[AES_BLOCK_SIZE];
//extern unsigned char IV[] = { 1, 64, 119, 95, 10, 132, 5, 137, 103, 8, 100, 14, 91, 34, 81, 197 };
//extern unsigned char userkey[] = { 182,131,35,156,149, 66, 53, 237, 238, 163, 214, 71, 31, 10, 30, 124, 156, 226, 105, 111, 253, 124, 38, 72, 234, 126,230 ,5 ,39 ,37 ,121 , 230 };
//extern AES_KEY key;

class AESENC
{
public:
	char *Encryption(char message[]);
	char *Decryption(char buffer[]);
};

#endif
