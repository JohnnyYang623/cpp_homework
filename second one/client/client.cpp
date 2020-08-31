#include"client.h"


void Client::start()
{
	//初始化
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata))
	{
		cout << "未能完成网络初始化！\n";
		system("pause");
		return;
	}
	cout << "网络初始化成功\n";

	//调用socket初始化套接字
	serv_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serv_socket == INVALID_SOCKET)
	{
		cout << "未能初始化套接字！\n";
		closesocket(serv_socket);
		WSACleanup();
		system("pause");
		return;
	}
	cout << "初始化套接字成功！\n";

	//初始化sock_addr
	sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	serv_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	//进行bind操作绑定套接字
	if (::bind(serv_socket, (sockaddr*)& serv_addr, sizeof(serv_addr)) == SOCKET_ERROR)
	{
		cout << "绑定套接字失败！\n";
		closesocket(serv_socket);
		WSACleanup();
		system("pause");
		return;
	}
	cout << "套接字绑定成功！\n";

	//进入监听状态
	listen(serv_socket, 20);
	sockaddr_in clntAddr;
	int nSize = sizeof(clntAddr);
	cli_socket = accept(serv_socket, (SOCKADDR*)& clntAddr, &nSize);
	

	//连接成功
	if (cli_socket == INVALID_SOCKET)
	{
		cout << "未能连接服务器端！\n";
		closesocket(cli_socket);
	}
	cout << "已连接" << inet_ntoa(clntAddr.sin_addr) << endl;

	//先用循环进入登录状态
	while (1)
	{
		int choose;
		cout << "若要注册请输入1，若要登录请输入2\n";
		cin >> choose;

		if (choose == 1)
			regist();

		else if (choose == 2)
		{
			new_port= login();
			break;
		}

		else
			cout << "输入错误\n";

	}

	//此时已经登录完成，与新端口号进行连接
	//调用socket初始化套接字
	serv1_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serv1_socket == INVALID_SOCKET)
	{
		cout << "未能初始化套接字！\n";
		closesocket(serv1_socket);
		WSACleanup();
		system("pause");
		return;
	}
	cout << "初始化套接字成功！\n";

	//初始化sock_addr
	sockaddr_in serv1_addr;
	serv1_addr.sin_family = AF_INET;
	serv1_addr.sin_port = htons(new_port);
	serv1_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	//进行bind操作绑定套接字
	if (::bind(serv1_socket, (sockaddr*)& serv1_addr, sizeof(serv1_addr)) == SOCKET_ERROR)
	{
		cout << "绑定套接字失败！\n";
		closesocket(serv1_socket);
		WSACleanup();
		system("pause");
		return;
	}
	cout << "套接字绑定成功！\n";

	//进入监听状态
	listen(serv1_socket, 20);
	sockaddr_in clntAddr1;
	nSize = sizeof(clntAddr1);
	cli1_socket = accept(serv1_socket, (SOCKADDR*)& clntAddr1, &nSize);


	//连接成功
	if (cli1_socket == INVALID_SOCKET)
	{
		cout << "未能连接服务器端！\n";
		closesocket(cli1_socket);
	}
	cout << "已连接" << inet_ntoa(clntAddr1.sin_addr) << endl;


	//先分配精灵
	//发送请求报文
	strcpy(buf, "assign_pokemon");
	send(cli1_socket, buf, BUF_MAX, 0);

	//接收信息并打印，告知用户已经有精灵了
	recv(cli1_socket, buf, BUF_MAX, 0);
	cout << buf << endl;
	

	//登出信息要发给cli_socket而不是cli1_socket
	//用循环来让用户选择信息。包括：查看所有用户及在线情况，查看自己的精灵，查看所有用户的精灵，登出，分配精灵
	while (1)
	{
		int input;
		cout << "查看所有用户及在线情况请输入1\n查看自己精灵请输入2\n查看所有用户的精灵请输入3\n修改密码请输入4\n登出请输入5\n";
		cin >> input;

		//查看所有用户及在线情况请输入1
		if (input == 1)
		{
			strcpy(buf, "check_users");
			send(cli1_socket, buf, BUF_MAX, 0);
			recv(cli1_socket, buf, BUF_MAX, 0);
			cout << buf;
		}

		//查看自己精灵请输入2
		else if (input == 2)
		{
			strcpy(buf, "check_my_pokemon");
			send(cli1_socket, buf, BUF_MAX, 0);
			recv(cli1_socket, buf, BUF_MAX, 0);
			cout << buf;
		}

		//查看所有用户的精灵请输入3
		else if (input == 3)
		{
			strcpy(buf, "check_all_pokemons");
			send(cli1_socket, buf, BUF_MAX, 0);
			recv(cli1_socket, buf, BUF_MAX, 0);
			cout << buf;
		}

		//修改密码请输入4
		else if (input == 4)
		{
			string pass_input;
			string pass_pass;
			


			while (1)
			{
				cout << "请输入您之前的密码:";
				cin >> pass_pass;


				cout << "\n请输入您的新密码:";
				cin >> pass_input;
				//先判断密码格式
				while (pass_input.length() > 10 || pass_input.length() < 6)
				{
					cout << "\n密码格式错误！\n";
					cout << "请输入密码（要求为英文、数字或符号，不得包括换行符、制表符或空格，长度在6~10位）:";
					cin >> pass_input;
				}
				//再判断是不是和旧密码一致
				while (pass_input == pass_pass)
				{
					cout << "\n旧密码和新密码重复！\n";
					cout << "请输入密码（要求为英文、数字或符号，不得包括换行符、制表符或空格，长度在6~10位）:";
					cin >> pass_input;
				}

				string pass_again;
				cout << "请再次输入密码:";
				cin >> pass_again;

				//检测两次密码输入是否一致
				if (pass_again != pass_input)
				{
					cout << "\n两次密码不一致！请重新输入密码！\n";
					continue;
				}


				char temp_buf[BUF_MAX];
				//如果输入成功就发送报文
				sprintf(temp_buf, "reset %s %s", pass_pass.data(),pass_input.data());
				memcpy(buf, temp_buf, BUF_MAX);
				send(cli1_socket, buf, BUF_MAX, 0);

				//接收报文
				recv(cli1_socket, buf, BUF_MAX, 0);
				auto buf_done = split(buf, ' ');

				//旧密码错误
				if (buf_done[0] == "error12")
				{
					cout << "输入的旧密码错误！\n";
					continue;
				}

				else if (buf_done[0] == "done")
				{
					cout << "修改密码成功！\n";
					break;
				}

				//让用户有退出的机会
				cout << "退出请输入1，继续请输入其他任意键\n";
				int input;
				cin >> input;
				if (input == 1)
					break;


				break;
			}
			
		}

		//登出请输入5
		else if (input == 5)
		{
			strcpy(buf, "logout");
			send(cli1_socket, buf, BUF_MAX, 0);
			recv(cli1_socket, buf, BUF_MAX, 0);
			cout << buf;
		}
	}
	
}


void Client::regist()
{
	

	string name, password;

	
	while (1)
	{
		char temp_buf[BUF_MAX];
		memset(temp_buf, 0, BUF_MAX);

		//要求输入用户名和密码
		cout << "请输入用户名（要求为英文、数字或符号，不得包括换行符、制表符或空格，长度在2~10位）：";
		cin >> name;
		while (name.length() < 2 || name.length() > 6)
		{
			cout << "用户名格式错误，请重新输入用户名！\n请输入用户名（要求为英文、数字或符号，不得包括换行符、制表符或空格，长度在2~10位）：";
			cin >> name;
		}
			
		cout << "\n请输入密码（要求为英文、数字或符号，不得包括换行符、制表符或空格，长度在6~10位）";
		cin >> password;
		while (password.length() < 6 || password.length() > 10)
		{
			cout << "密码格式错误，请重新输入密码！\n请输入密码（要求为英文、数字或符号，不得包括换行符、制表符或空格，长度在6~10位）：";
			cin >> password;
		}

		//准备报文并发送
		sprintf(temp_buf, "regist %s %s", name.data(), password.data());
		memcpy(buf, temp_buf, BUF_MAX);
		send(cli_socket, buf, BUF_MAX, 0);

		//接收报文并且进行分割
		recv(cli_socket, buf, BUF_MAX, 0);
		auto buf_done = split(buf, ' ');

		//分析内容

		//用户名已存在
		if (buf_done[0] == "error2")
		{
			cout << "用户名已存在，请更换用户名！\n";
		}

		else if (buf_done[0] == "error4")
		{
			cout << "用户已满，请等待管理员操作!\n";
			break;
		}

		else if (buf_done[0] == "done1")
		{
			cout << "注册成功！请进行登录~\n";
			break;
		}
	}
}


int Client::login()
{
	string name, password;


	while (1)
	{
		char temp_buf[BUF_MAX];
		memset(temp_buf, 0, BUF_MAX);

		//要求输入用户名和密码
		cout << "请输入用户名：";
		cin >> name;
		while (name.length() < 2 || name.length() > 6)
		{
			cout << "用户名格式错误，请重新输入用户名！\n请输入用户名（要求为英文、数字或符号，不得包括换行符、制表符或空格，长度在2~10位）：";
			cin >> name;
		}

		cout << "\n请输入密码";
		cin >> password;
		while (password.length() < 6 || password.length() > 10)
		{
			cout << "密码格式错误，请重新输入密码！\n请输入密码（要求为英文、数字或符号，不得包括换行符、制表符或空格，长度在6~10位）：";
			cin >> password;
		}

		//准备报文并发送
		sprintf(temp_buf, "login %s %s", name.data(), password.data());
		memcpy(buf, temp_buf, BUF_MAX);
		send(cli_socket, buf, BUF_MAX, 0);

		//接收报文并且进行分割
		recv(cli_socket, buf, BUF_MAX, 0);
		auto buf_done = split(buf, ' ');

		//用户名没有被注册
		if (buf_done[0] == "error5")
			cout << "用户名没有被注册！\n";
		
		//密码错误
		else if (buf_done[0] == "error6")
			cout << " 密码错误！\n";

		//用户已经登录
		else if (buf_done[0] == "error7")
			cout << "该用户已经登录！\n";

		//端口错误
		else if (buf_done[0] == "error8")
			cout << "端口错误!\n";

		//成功
		else if (buf_done[0] == "done2")
		{
			//获得新的端口号
			new_port = atoi(buf_done[1].data());
			//与端口号进行连接

			return new_port;
			
		}

	}
}
