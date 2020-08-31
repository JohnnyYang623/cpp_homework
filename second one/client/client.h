#pragma once
#include"pokemons.h"
#include<winsock2.h>
#include"split.h"
#pragma comment(lib, "ws2_32.lib")

#define BUF_MAX 4096

#pragma warning(disable:4996)


class Client
{
private:
	SOCKET serv_socket;
	SOCKET cli_socket;

	SOCKET serv1_socket;
	SOCKET cli1_socket;
	int port = 2500;
	int new_port;
	char buf[BUF_MAX];

public:
	void start();
	void regist();
	int login();
};