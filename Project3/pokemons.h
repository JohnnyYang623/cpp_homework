#pragma once
#include"base.h"


//���ڻ���Ļ����ϼ��ϸ����������


class Pokemon:public PokemonBase
{
private:
	int upgrade_data[4], miss, grade, exp, interval, offense, defense, speed, health, type1, type2;

public:
	//���캯��������type1������ֻ��������࣬1~4���������ͣ��߹����� ����ͣ�������ֵ�������ͣ��߷����������ͣ��͹�����������ٶ�
	//type2������ֻ�����Ǹ����е���һֻ
	//������Щ��ֵ����ʼ����ͬ����������������upgrade_data�������ӵ����Էֱ�Ϊ�������������������ٶ�
	Pokemon(int type1_, int type2_)
	{
		//�Ȱѻ������Գ�ʼ��
		miss = miss_base; grade = grade_base; exp = exp_base; offense = offense_base;
		defense = defense_base; speed = speed_base; health = health_base; interval = interval_base;

		//���������ݾ�������ཫ�������ֵ���г�ʼ����ÿֻ���鲻һ���ĵط����ڹ���������������ƣ��������ơ�
		if (1 == type1_)//������
		{
			if (1 == type2_)//�����
			{
				type1 = 1; type2 = 1;
				upgrade_data[0] = 6; upgrade_data[1] = 2; upgrade_data[2] = 4; upgrade_data[3] = 2;
				name = { "�����" };
				move1 = { "��" }; move2 = { "�������" };
			}
		}

		
		if (2 == type1_)//������
		{
			if (1 == type2_)//ˮ����
			{
				type1 = 2; type2 = 1;
				upgrade_data[0] = 2; upgrade_data[1] = 6; upgrade_data[2] = 4; upgrade_data[3] = 2;
				name = { "ˮ����" };
				move1 = { "ˮǹ" }; move2 = { "���ͷ�" };
			}
		}

		if (3 == type1_)//�����
		{
			if (1 == type2_)//����
			{
				type1 = 3; type2 = 1;
				upgrade_data[0] = 3; upgrade_data[1] = 3; upgrade_data[2] = 8; upgrade_data[3] = 1;
				name = { "����" };
				move1 = { "ˮ֮����" }; move2 = { "��������" };
			}
		}

		if (4 == type1_)//�ٶ���
		{
			if (1 == type2_)//�ȵ�
			{
				type1 = 4; type2 = 1;
				upgrade_data[0] = 2; upgrade_data[1] = 2; upgrade_data[2] = 3; upgrade_data[3] = 3;
				name = { "�ȵ�" };
				//�ٶ��͵Ĺ�������٣�����Ҫ�����һ�¹��������
				interval = 1;
				move1 = { "�෵" }; move2 = { "����" };
			}
		}
	}

	//��ȡ����
	string get_name()
	{
		return name;
	}

	//��ȡ��������
	string get_move1()
	{
		return move1;
	}

	string get_move2()
	{
		return move2;
	}

	int get_type1()
	{
		return type1;
	}

	int get_type2()
	{
		return type2;
	}

	//setter
	void set_offense(int offense_)
	{
		offense = offense_;
	}
	void set_defense(int defense_)
	{
		defense = defense_;
	}
	void set_health(int health_)
	{
		health = health_;
	}
	void set_speed(int speed_)
	{
		speed = speed_;
	}


	void print_info()
	{
		cout << name << "��";
		cout << "�ȼ�Ϊ" << grade;
		cout << " ����Ϊ" << exp;
		cout << " ������Ϊ" << miss <<"%";
		cout << " �������Ϊ" << interval << endl;
		cout << "����Ϊ" << offense;
		cout << " ����Ϊ" << defense;
		cout << " �ٶ�Ϊ" << speed;
		cout << " ����Ϊ" << health << endl;
	}


	//��ȡһֻ�������Ϣ
	void get_info(int* info)
	{
		info[0] = grade; info[1] = exp; info[2] = miss; info[3] = interval;
		info[4] = offense; info[5] = defense; info[6] = speed; info[7] = health;
	}

	//��ȡ��������
	int get_exps(int level)
	{
		return exps[level];
	}


	//���ܺ�������Ӧ�þ�����������ܡ�
	//��ͬ���ܵĲ�֮ͬ�����ڼ��ܵ�������һ����ͬʱ���ܾ��в��ȶ��ԡ��еļ��ܾ���һ���ĸ���ӵ�и�������������������򽵵��Լ������ԡ�
	//����Ϊ�Է���������ԡ�
	int skill(int* info)
	{
		int move_num,temp;
		cout << "��Ϊ" << name << "ѡȡҪ���ֵļ���:" << endl;
		//�����
		if (1 == type1 && 1 == type2)
		{
			cout << "����1Ϊ�𻨣�����60\n";
			cout << "����2Ϊ������棬����90��������20%�������Լ������½�10��\n";
			cout << "��ѡ��Ҫ���ֵļ���\n";
			cin >> move_num;
			while (move_num > 2 || move_num < 1)
			{
				cout << "�����������ٴ�����\n";
				cin >> move_num;
			}
			if (1 == move_num)
				return (60);
			else
			{
				temp = 10 * (rand() % 100 >= 80);
				if (temp == 10)
				{
					if (offense > 10)
						offense -= 10;
					else
						offense = 1;
					cout << "������Ĺ��������ˣ�\n";
				}
				return (90);
			}
		}
		//ˮ����
		else if (2 == type1 && 1 == type2)
		{
			cout << "����1Ϊˮǹ������60\n";
			cout << "����2Ϊ���ͷ鳣�����90��������20%�������Լ������½�10��\n";
			cout << "��ѡ��Ҫ���ֵļ���\n";
			cin >> move_num;
			while (move_num > 2 || move_num < 1)
			{
				cout << "�����������ٴ�����\n";
				cin >> move_num;
			}
			if (1 == move_num)
				return (60);
			else
			{
				temp = 10 * (rand() % 100 >= 80);
				if (temp == 10)
				{
					if (defense > 10)
						defense -= 10;
					else
						defense = 1;
					cout << "ˮ����ķ���������!\n";
				}
				return (90);
			}
		}
		//����
		else if (3 == type1 && 1 == type2)
		{
			cout << "����1Ϊˮ֮����������60\n" ;
			cout << "����2Ϊ������������������40���Լ������ȶԷ�Խ�ߣ��˼�������Խ��\n" ;
			cout << "��ѡ��Ҫ���ֵļ���\n";
			cin >> move_num;
			while (move_num > 2 || move_num < 1)
			{
				cout << "�����������ٴ�����\n";
				cin >> move_num;
			}
			if (1 == move_num)
				return (60);
			else
			{
				temp = int(40 * (float(health / info[7])));
				cout << "������������Ϊ" << temp <<"!"<< endl;
				return temp;
			}
		}
		//�ȵ�
		else if (4 == type1 && 1 == type2)
		{
			cout << "����1Ϊ�෵������30\n" ;
			cout << "����2Ϊ���ݣ�����60�����������Լ��ٶ��½�6�㡣\n";
			cout << "��ѡ��Ҫ���ֵļ���\n";
			cin >> move_num;
			while (move_num > 2 || move_num < 1)
			{
				cout << "�����������ٴ�����\n";
				cin >> move_num;
			}
			if (1 == move_num)
				return (30);
			else
			{
				if (speed > 6)
					speed -= 6;
				else
					speed = 1;
				cout << "�ȵ���ٶȽ����ˣ�\n";
				return (60);
			}
		}
	}


	//��������������Ϊ�Է�����ͱ������еĻغ����������ж�ĳ�����Ƿ��ܳ��֣�
	//���������Ŀ���������öԷ��ķ���ֵ�������ʼ����ʵ���˺�
	int attack(Pokemon* pokemon, int turn)
	{
		//�Է��������Ϣ
		int info[8];
		pokemon->get_info(info);
		int other_grade = info[0], other_miss = info[2], other_interval = info[3], other_offense = info[4],
			other_defense = info[5], other_speed = info[6], other_health = info[7];
		string other_name = pokemon->get_name();

		//�˺���
		int damage;
		cout << "\n�غ�" << turn << "��ʼ��" << endl;

		//�ֱ�����ҵľ���ͶԷ�����ļ��ܺ���������м��ܵ�ѡȡ�������ļ���
		int my_power = skill(info);
		int my_info[8];
		get_info(my_info);
		int other_power = pokemon->skill(my_info);

		//���������ȳ���
		if (speed >= other_speed)
		{
			cout<< rand() % 100 - miss<<endl;
			//if���ж��Ƿ����Լ������ִ��Լ��Ƿ�������
			if ((turn - 1) % interval != 0)
				cout << name << "Ŀǰ���ܹ�����\n";
			else if(rand() % 100 - other_miss < 0)
				cout << name << "δ�����У�\n";
			else
			{
				damage = int(float(offense)/float(other_defense) * float(my_power) * float(grade)/15.0);
				other_health -= damage;
				cout << "�ҷ�"<<name<<"�ԶԷ����" << damage << "���˺����Է����ڵ�����ֵΪ" << other_health << endl;
			}
			if (other_health > 0)
			{
				if ((turn - 1) % other_interval != 0)
					cout << other_name << "Ŀǰ���ܹ�����\n";
				else if (rand() % 100 - miss < 0)
					cout << other_name << "δ�����У�\n";
				else if (other_health > 0)
				{
					damage = int(float(other_offense) / float(defense) * float(other_power) * float(other_grade) / 15.0);
					health -= damage;
					cout << "�Է�"<<other_name<<"���ҷ����" << damage << "���˺����ҷ����ڵ�����ֵΪ" << health << endl;
				}
			}
		}
		//�Է��ȳ���
		else
		{
			//�Է�����
			if (turn - 1 % other_interval == 0)
				cout << other_name << "Ŀǰ���ܹ�����\n";
			else if (rand() % 100 - miss < 0)
				cout << other_name << "δ�����У�\n";
			else
			{
				damage = int(float(other_offense) / float(defense) * float(other_power) * float(other_grade) / 15.0);
				health -= damage;
				cout << "�Է�"<<other_name<<"���ҷ����" << damage << "���˺����ҷ����ڵ�����ֵΪ" << health << endl;
			}

			//�ҷ�����
			if (health > 0)
			{
				if (turn - 1 % interval == 0)
					cout << name << "Ŀǰ���ܹ�����\n";
				else if (rand() % 100 - other_miss < 0)
					cout << name << "δ�����У�\n";
				else if (health > 0)
				{
					damage = int(float(offense) / float(other_defense) * float(my_power) * float(grade) / 15.0);
					other_health -= damage;
					cout << "�ҷ�"<<name<<"�ԶԷ����" << damage << "���˺����Է����ڵ�����ֵΪ" << other_health << endl;
				}
			}
			
		}
		return other_health;
	}

	//��������
	void upgrade(int exp_gain)
	{
		//���Ѿ������Ͳ���������
		if (grade < 15)
		{
			exp += exp_gain;
			//��þ��飬��ʼ����
			while (exp >= exps[grade - 1])
			{
				exp -= exps[grade - 1];
				grade++;

				//��ʼ����������
				offense += upgrade_data[0];
				defense += upgrade_data[1];
				speed += upgrade_data[2];
				health += upgrade_data[3];

				if (grade == 15)
				{
					exp = 0;
					break;
				}
			}
		}
	}

	//�򶷺���
	void fight(Pokemon* pokemon)
	{
		//��ʼ���ִ�,�Լ��Ͷ��ֵ�����ֵ
		int turn = 1;

		int info[8];
		//��ȡ���־�����Ϣ
		pokemon->get_info(info);
		int other_grade = info[0], other_exp = info[1],
			other_miss = info[2], other_interval = info[3], other_offense = info[4],
			other_defense = info[5], other_speed = info[6], other_health = info[7];
		string other_move1 = pokemon->get_move1(), other_move2 = pokemon->get_move2(),
			other_name = pokemon->get_name();

		//��¼�ҷ�������Ϣ
		int my_info[8];
		get_info(my_info);

		int total_my_health = health, total_other_health = other_health, pre_my_health, pre_other_health;

		//��������Ϣ
		cout << name << "�����ˣ�\n";
		cout << other_name << "�����ˣ�\n";

		for (;; turn++)
		{
			//��¼�ϻغϵ�Ѫ��
			pre_my_health = health; pre_other_health = other_health;

			print_info();
			pokemon->print_info();
			other_health = attack(pokemon, turn);
			pokemon->set_health(other_health);
			//�ж��Ƿ�����ս�ܣ�����еĻ��ͻظ�Ѫ�������㾭�������������break����
			if (health <= 0)
			{
				cout << "�ҷ�ս��!" << endl;
				restore(my_info);
				pokemon->restore(info);
				//��ʼ������սʤ�߻�ö��ֵȼ������ľ���ֵ��ս���߻�ö��ֵȼ�һ���ľ���ֵ��
				upgrade(other_grade);
				pokemon->upgrade(grade * 2);
				print_info();
				pokemon->print_info();
				break;
			}

			if (other_health <= 0)
			{
				cout << "�з�ս��!" << endl;
				restore(my_info);
				pokemon->restore(info);
				upgrade(other_grade * 2);
				pokemon->upgrade(grade);
				print_info();
				pokemon->print_info();
				break;
			}
		}
	}


	//ս�������о�����ܻ��һЩ����������������������潫�������лظ�
	void restore(int* info)
	{
		miss = info[2], interval = info[3], offense = info[4],
		defense = info[5], speed = info[6], health = info[7];
	}

};

