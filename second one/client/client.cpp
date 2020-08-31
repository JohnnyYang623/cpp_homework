#include"client.h"


void Client::start()
{
	//��ʼ��
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata))
	{
		cout << "δ����������ʼ����\n";
		system("pause");
		return;
	}
	cout << "�����ʼ���ɹ�\n";

	//����socket��ʼ���׽���
	serv_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serv_socket == INVALID_SOCKET)
	{
		cout << "δ�ܳ�ʼ���׽��֣�\n";
		closesocket(serv_socket);
		WSACleanup();
		system("pause");
		return;
	}
	cout << "��ʼ���׽��ֳɹ���\n";

	//��ʼ��sock_addr
	sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	serv_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	//����bind�������׽���
	if (::bind(serv_socket, (sockaddr*)& serv_addr, sizeof(serv_addr)) == SOCKET_ERROR)
	{
		cout << "���׽���ʧ�ܣ�\n";
		closesocket(serv_socket);
		WSACleanup();
		system("pause");
		return;
	}
	cout << "�׽��ְ󶨳ɹ���\n";

	//�������״̬
	listen(serv_socket, 20);
	sockaddr_in clntAddr;
	int nSize = sizeof(clntAddr);
	cli_socket = accept(serv_socket, (SOCKADDR*)& clntAddr, &nSize);
	

	//���ӳɹ�
	if (cli_socket == INVALID_SOCKET)
	{
		cout << "δ�����ӷ������ˣ�\n";
		closesocket(cli_socket);
	}
	cout << "������" << inet_ntoa(clntAddr.sin_addr) << endl;

	//����ѭ�������¼״̬
	while (1)
	{
		int choose;
		cout << "��Ҫע��������1����Ҫ��¼������2\n";
		cin >> choose;

		if (choose == 1)
			regist();

		else if (choose == 2)
		{
			new_port= login();
			break;
		}

		else
			cout << "�������\n";

	}

	//��ʱ�Ѿ���¼��ɣ����¶˿ںŽ�������
	//����socket��ʼ���׽���
	serv1_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serv1_socket == INVALID_SOCKET)
	{
		cout << "δ�ܳ�ʼ���׽��֣�\n";
		closesocket(serv1_socket);
		WSACleanup();
		system("pause");
		return;
	}
	cout << "��ʼ���׽��ֳɹ���\n";

	//��ʼ��sock_addr
	sockaddr_in serv1_addr;
	serv1_addr.sin_family = AF_INET;
	serv1_addr.sin_port = htons(new_port);
	serv1_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	//����bind�������׽���
	if (::bind(serv1_socket, (sockaddr*)& serv1_addr, sizeof(serv1_addr)) == SOCKET_ERROR)
	{
		cout << "���׽���ʧ�ܣ�\n";
		closesocket(serv1_socket);
		WSACleanup();
		system("pause");
		return;
	}
	cout << "�׽��ְ󶨳ɹ���\n";

	//�������״̬
	listen(serv1_socket, 20);
	sockaddr_in clntAddr1;
	nSize = sizeof(clntAddr1);
	cli1_socket = accept(serv1_socket, (SOCKADDR*)& clntAddr1, &nSize);


	//���ӳɹ�
	if (cli1_socket == INVALID_SOCKET)
	{
		cout << "δ�����ӷ������ˣ�\n";
		closesocket(cli1_socket);
	}
	cout << "������" << inet_ntoa(clntAddr1.sin_addr) << endl;


	//�ȷ��侫��
	//����������
	strcpy(buf, "assign_pokemon");
	send(cli1_socket, buf, BUF_MAX, 0);

	//������Ϣ����ӡ����֪�û��Ѿ��о�����
	recv(cli1_socket, buf, BUF_MAX, 0);
	cout << buf << endl;
	

	//�ǳ���ϢҪ����cli_socket������cli1_socket
	//��ѭ�������û�ѡ����Ϣ���������鿴�����û�������������鿴�Լ��ľ��飬�鿴�����û��ľ��飬�ǳ������侫��
	while (1)
	{
		int input;
		cout << "�鿴�����û����������������1\n�鿴�Լ�����������2\n�鿴�����û��ľ���������3\n�޸�����������4\n�ǳ�������5\n";
		cin >> input;

		//�鿴�����û����������������1
		if (input == 1)
		{
			strcpy(buf, "check_users");
			send(cli1_socket, buf, BUF_MAX, 0);
			recv(cli1_socket, buf, BUF_MAX, 0);
			cout << buf;
		}

		//�鿴�Լ�����������2
		else if (input == 2)
		{
			strcpy(buf, "check_my_pokemon");
			send(cli1_socket, buf, BUF_MAX, 0);
			recv(cli1_socket, buf, BUF_MAX, 0);
			cout << buf;
		}

		//�鿴�����û��ľ���������3
		else if (input == 3)
		{
			strcpy(buf, "check_all_pokemons");
			send(cli1_socket, buf, BUF_MAX, 0);
			recv(cli1_socket, buf, BUF_MAX, 0);
			cout << buf;
		}

		//�޸�����������4
		else if (input == 4)
		{
			string pass_input;
			string pass_pass;
			


			while (1)
			{
				cout << "��������֮ǰ������:";
				cin >> pass_pass;


				cout << "\n����������������:";
				cin >> pass_input;
				//���ж������ʽ
				while (pass_input.length() > 10 || pass_input.length() < 6)
				{
					cout << "\n�����ʽ����\n";
					cout << "���������루Ҫ��ΪӢ�ġ����ֻ���ţ����ð������з����Ʊ����ո񣬳�����6~10λ��:";
					cin >> pass_input;
				}
				//���ж��ǲ��Ǻ;�����һ��
				while (pass_input == pass_pass)
				{
					cout << "\n��������������ظ���\n";
					cout << "���������루Ҫ��ΪӢ�ġ����ֻ���ţ����ð������з����Ʊ����ո񣬳�����6~10λ��:";
					cin >> pass_input;
				}

				string pass_again;
				cout << "���ٴ���������:";
				cin >> pass_again;

				//����������������Ƿ�һ��
				if (pass_again != pass_input)
				{
					cout << "\n�������벻һ�£��������������룡\n";
					continue;
				}


				char temp_buf[BUF_MAX];
				//�������ɹ��ͷ��ͱ���
				sprintf(temp_buf, "reset %s %s", pass_pass.data(),pass_input.data());
				memcpy(buf, temp_buf, BUF_MAX);
				send(cli1_socket, buf, BUF_MAX, 0);

				//���ձ���
				recv(cli1_socket, buf, BUF_MAX, 0);
				auto buf_done = split(buf, ' ');

				//���������
				if (buf_done[0] == "error12")
				{
					cout << "����ľ��������\n";
					continue;
				}

				else if (buf_done[0] == "done")
				{
					cout << "�޸�����ɹ���\n";
					break;
				}

				//���û����˳��Ļ���
				cout << "�˳�������1���������������������\n";
				int input;
				cin >> input;
				if (input == 1)
					break;


				break;
			}
			
		}

		//�ǳ�������5
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

		//Ҫ�������û���������
		cout << "�������û�����Ҫ��ΪӢ�ġ����ֻ���ţ����ð������з����Ʊ����ո񣬳�����2~10λ����";
		cin >> name;
		while (name.length() < 2 || name.length() > 6)
		{
			cout << "�û�����ʽ���������������û�����\n�������û�����Ҫ��ΪӢ�ġ����ֻ���ţ����ð������з����Ʊ����ո񣬳�����2~10λ����";
			cin >> name;
		}
			
		cout << "\n���������루Ҫ��ΪӢ�ġ����ֻ���ţ����ð������з����Ʊ����ո񣬳�����6~10λ��";
		cin >> password;
		while (password.length() < 6 || password.length() > 10)
		{
			cout << "�����ʽ�����������������룡\n���������루Ҫ��ΪӢ�ġ����ֻ���ţ����ð������з����Ʊ����ո񣬳�����6~10λ����";
			cin >> password;
		}

		//׼�����Ĳ�����
		sprintf(temp_buf, "regist %s %s", name.data(), password.data());
		memcpy(buf, temp_buf, BUF_MAX);
		send(cli_socket, buf, BUF_MAX, 0);

		//���ձ��Ĳ��ҽ��зָ�
		recv(cli_socket, buf, BUF_MAX, 0);
		auto buf_done = split(buf, ' ');

		//��������

		//�û����Ѵ���
		if (buf_done[0] == "error2")
		{
			cout << "�û����Ѵ��ڣ�������û�����\n";
		}

		else if (buf_done[0] == "error4")
		{
			cout << "�û���������ȴ�����Ա����!\n";
			break;
		}

		else if (buf_done[0] == "done1")
		{
			cout << "ע��ɹ�������е�¼~\n";
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

		//Ҫ�������û���������
		cout << "�������û�����";
		cin >> name;
		while (name.length() < 2 || name.length() > 6)
		{
			cout << "�û�����ʽ���������������û�����\n�������û�����Ҫ��ΪӢ�ġ����ֻ���ţ����ð������з����Ʊ����ո񣬳�����2~10λ����";
			cin >> name;
		}

		cout << "\n����������";
		cin >> password;
		while (password.length() < 6 || password.length() > 10)
		{
			cout << "�����ʽ�����������������룡\n���������루Ҫ��ΪӢ�ġ����ֻ���ţ����ð������з����Ʊ����ո񣬳�����6~10λ����";
			cin >> password;
		}

		//׼�����Ĳ�����
		sprintf(temp_buf, "login %s %s", name.data(), password.data());
		memcpy(buf, temp_buf, BUF_MAX);
		send(cli_socket, buf, BUF_MAX, 0);

		//���ձ��Ĳ��ҽ��зָ�
		recv(cli_socket, buf, BUF_MAX, 0);
		auto buf_done = split(buf, ' ');

		//�û���û�б�ע��
		if (buf_done[0] == "error5")
			cout << "�û���û�б�ע�ᣡ\n";
		
		//�������
		else if (buf_done[0] == "error6")
			cout << " �������\n";

		//�û��Ѿ���¼
		else if (buf_done[0] == "error7")
			cout << "���û��Ѿ���¼��\n";

		//�˿ڴ���
		else if (buf_done[0] == "error8")
			cout << "�˿ڴ���!\n";

		//�ɹ�
		else if (buf_done[0] == "done2")
		{
			//����µĶ˿ں�
			new_port = atoi(buf_done[1].data());
			//��˿ںŽ�������

			return new_port;
			
		}

	}
}
