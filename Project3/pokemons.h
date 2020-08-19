#pragma once
#include"base.h"


//基于基类的基础上加上各项独有属性


class Pokemon:public PokemonBase
{
private:
	int upgrade_data[4], miss, grade, exp, interval, offense, defense, speed, health, type1, type2;

public:
	//构造函数，参数type1代表这只精灵的种类，1~4代表力量型：高攻击； 肉盾型：高生命值；防御型：高防御；敏捷型：低攻击间隔，高速度
	//type2代表这只精灵是该型中的哪一只
	//根据这些数值来初始化不同的升级加属性数组upgrade_data。升级加的属性分别为攻击，防御，生命，速度
	Pokemon(int type1_, int type2_)
	{
		//先把基本属性初始化
		miss = miss_base; grade = grade_base; exp = exp_base; offense = offense_base;
		defense = defense_base; speed = speed_base; health = health_base; interval = interval_base;

		//接下来根据精灵的种类将精灵的数值进行初始化。每只精灵不一样的地方在于攻击间隔，精灵名称，技能名称。
		if (1 == type1_)//力量型
		{
			if (1 == type2_)//喷火龙
			{
				type1 = 1; type2 = 1;
				upgrade_data[0] = 6; upgrade_data[1] = 2; upgrade_data[2] = 4; upgrade_data[3] = 2;
				name = { "喷火龙" };
				move1 = { "火花" }; move2 = { "喷射火焰" };
			}
		}

		
		if (2 == type1_)//防御型
		{
			if (1 == type2_)//水箭龟
			{
				type1 = 2; type2 = 1;
				upgrade_data[0] = 2; upgrade_data[1] = 6; upgrade_data[2] = 4; upgrade_data[3] = 2;
				name = { "水箭龟" };
				move1 = { "水枪" }; move2 = { "火箭头槌" };
			}
		}

		if (3 == type1_)//肉盾型
		{
			if (1 == type2_)//乘龙
			{
				type1 = 3; type2 = 1;
				upgrade_data[0] = 3; upgrade_data[1] = 3; upgrade_data[2] = 8; upgrade_data[3] = 1;
				name = { "乘龙" };
				move1 = { "水之波动" }; move2 = { "冰冻光束" };
			}
		}

		if (4 == type1_)//速度型
		{
			if (1 == type2_)//比雕
			{
				type1 = 4; type2 = 1;
				upgrade_data[0] = 2; upgrade_data[1] = 2; upgrade_data[2] = 3; upgrade_data[3] = 3;
				name = { "比雕" };
				//速度型的攻击间隔少，所以要额外改一下攻击间隔。
				interval = 1;
				move1 = { "燕返" }; move2 = { "猛禽" };
			}
		}
	}

	//获取姓名
	string get_name()
	{
		return name;
	}

	//获取技能名称
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
		cout << name << "的";
		cout << "等级为" << grade;
		cout << " 经验为" << exp;
		cout << " 闪避率为" << miss <<"%";
		cout << " 攻击间隔为" << interval << endl;
		cout << "攻击为" << offense;
		cout << " 防御为" << defense;
		cout << " 速度为" << speed;
		cout << " 生命为" << health << endl;
	}


	//获取一只精灵的信息
	void get_info(int* info)
	{
		info[0] = grade; info[1] = exp; info[2] = miss; info[3] = interval;
		info[4] = offense; info[5] = defense; info[6] = speed; info[7] = health;
	}

	//获取升级经验
	int get_exps(int level)
	{
		return exps[level];
	}


	//技能函数，对应该精灵的两个技能。
	//不同技能的不同之处在于技能的威力不一样，同时技能具有不稳定性。有的技能具有一定的概率拥有更大的威力，或者提升或降低自己的属性。
	//参数为对方精灵的属性。
	int skill(int* info)
	{
		int move_num,temp;
		cout << "请为" << name << "选取要出手的技能:" << endl;
		//喷火龙
		if (1 == type1 && 1 == type2)
		{
			cout << "技能1为火花，威力60\n";
			cout << "技能2为喷射火焰，威力90。不过有20%概率让自己攻击下降10点\n";
			cout << "请选择要出手的技能\n";
			cin >> move_num;
			while (move_num > 2 || move_num < 1)
			{
				cout << "输入有误，请再次输入\n";
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
					cout << "喷火龙的攻击降低了！\n";
				}
				return (90);
			}
		}
		//水箭龟
		else if (2 == type1 && 1 == type2)
		{
			cout << "技能1为水枪，威力60\n";
			cout << "技能2为火箭头槌，威力90。不过有20%概率让自己防御下降10点\n";
			cout << "请选择要出手的技能\n";
			cin >> move_num;
			while (move_num > 2 || move_num < 1)
			{
				cout << "输入有误，请再次输入\n";
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
					cout << "水箭龟的防御降低了!\n";
				}
				return (90);
			}
		}
		//乘龙
		else if (3 == type1 && 1 == type2)
		{
			cout << "技能1为水之波动，威力60\n" ;
			cout << "技能2为冰冻光束，基础威力40。自己体力比对方越高，此技能威力越高\n" ;
			cout << "请选择要出手的技能\n";
			cin >> move_num;
			while (move_num > 2 || move_num < 1)
			{
				cout << "输入有误，请再次输入\n";
				cin >> move_num;
			}
			if (1 == move_num)
				return (60);
			else
			{
				temp = int(40 * (float(health / info[7])));
				cout << "冰冻光束威力为" << temp <<"!"<< endl;
				return temp;
			}
		}
		//比雕
		else if (4 == type1 && 1 == type2)
		{
			cout << "技能1为燕返，威力30\n" ;
			cout << "技能2为猛禽，威力60。不过会让自己速度下降6点。\n";
			cout << "请选择要出手的技能\n";
			cin >> move_num;
			while (move_num > 2 || move_num < 1)
			{
				cout << "输入有误，请再次输入\n";
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
				cout << "比雕的速度降低了！\n";
				return (60);
			}
		}
	}


	//攻击函数，参数为对方精灵和比赛进行的回合数（用作判断某精灵是否能出手）
	//这个函数的目的在于利用对方的防御值和闪避率计算出实际伤害
	int attack(Pokemon* pokemon, int turn)
	{
		//对方精灵的信息
		int info[8];
		pokemon->get_info(info);
		int other_grade = info[0], other_miss = info[2], other_interval = info[3], other_offense = info[4],
			other_defense = info[5], other_speed = info[6], other_health = info[7];
		string other_name = pokemon->get_name();

		//伤害量
		int damage;
		cout << "\n回合" << turn << "开始！" << endl;

		//分别进入我的精灵和对方精灵的技能函数里面进行技能的选取和威力的计算
		int my_power = skill(info);
		int my_info[8];
		get_info(my_info);
		int other_power = pokemon->skill(my_info);

		//本方精灵先出手
		if (speed >= other_speed)
		{
			cout<< rand() % 100 - miss<<endl;
			//if来判断是否到了自己攻击轮次以及是否能命中
			if ((turn - 1) % interval != 0)
				cout << name << "目前不能攻击！\n";
			else if(rand() % 100 - other_miss < 0)
				cout << name << "未能命中！\n";
			else
			{
				damage = int(float(offense)/float(other_defense) * float(my_power) * float(grade)/15.0);
				other_health -= damage;
				cout << "我方"<<name<<"对对方造成" << damage << "点伤害。对方现在的生命值为" << other_health << endl;
			}
			if (other_health > 0)
			{
				if ((turn - 1) % other_interval != 0)
					cout << other_name << "目前不能攻击！\n";
				else if (rand() % 100 - miss < 0)
					cout << other_name << "未能命中！\n";
				else if (other_health > 0)
				{
					damage = int(float(other_offense) / float(defense) * float(other_power) * float(other_grade) / 15.0);
					health -= damage;
					cout << "对方"<<other_name<<"对我方造成" << damage << "点伤害。我方现在的生命值为" << health << endl;
				}
			}
		}
		//对方先出手
		else
		{
			//对方攻击
			if (turn - 1 % other_interval == 0)
				cout << other_name << "目前不能攻击！\n";
			else if (rand() % 100 - miss < 0)
				cout << other_name << "未能命中！\n";
			else
			{
				damage = int(float(other_offense) / float(defense) * float(other_power) * float(other_grade) / 15.0);
				health -= damage;
				cout << "对方"<<other_name<<"对我方造成" << damage << "点伤害。我方现在的生命值为" << health << endl;
			}

			//我方攻击
			if (health > 0)
			{
				if (turn - 1 % interval == 0)
					cout << name << "目前不能攻击！\n";
				else if (rand() % 100 - other_miss < 0)
					cout << name << "未能命中！\n";
				else if (health > 0)
				{
					damage = int(float(offense) / float(other_defense) * float(my_power) * float(grade) / 15.0);
					other_health -= damage;
					cout << "我方"<<name<<"对对方造成" << damage << "点伤害。对方现在的生命值为" << other_health << endl;
				}
			}
			
		}
		return other_health;
	}

	//升级函数
	void upgrade(int exp_gain)
	{
		//若已经满级就不用升级了
		if (grade < 15)
		{
			exp += exp_gain;
			//获得经验，开始升级
			while (exp >= exps[grade - 1])
			{
				exp -= exps[grade - 1];
				grade++;

				//开始升级加属性
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

	//打斗函数
	void fight(Pokemon* pokemon)
	{
		//初始化轮次,自己和对手的生命值
		int turn = 1;

		int info[8];
		//获取对手精灵信息
		pokemon->get_info(info);
		int other_grade = info[0], other_exp = info[1],
			other_miss = info[2], other_interval = info[3], other_offense = info[4],
			other_defense = info[5], other_speed = info[6], other_health = info[7];
		string other_move1 = pokemon->get_move1(), other_move2 = pokemon->get_move2(),
			other_name = pokemon->get_name();

		//记录我方精灵信息
		int my_info[8];
		get_info(my_info);

		int total_my_health = health, total_other_health = other_health, pre_my_health, pre_other_health;

		//输出相关信息
		cout << name << "出场了！\n";
		cout << other_name << "出场了！\n";

		for (;; turn++)
		{
			//记录上回合的血量
			pre_my_health = health; pre_other_health = other_health;

			print_info();
			pokemon->print_info();
			other_health = attack(pokemon, turn);
			pokemon->set_health(other_health);
			//判断是否有人战败，如果有的话就回复血量，结算经验进行升级，并break跳出
			if (health <= 0)
			{
				cout << "我方战败!" << endl;
				restore(my_info);
				pokemon->restore(info);
				//开始升级。战胜者获得对手等级两倍的经验值，战败者获得对手等级一倍的经验值。
				upgrade(other_grade);
				pokemon->upgrade(grade * 2);
				print_info();
				pokemon->print_info();
				break;
			}

			if (other_health <= 0)
			{
				cout << "敌方战败!" << endl;
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


	//战斗过程中精灵可能获得一些能力提升，在这个函数里面将能力进行回复
	void restore(int* info)
	{
		miss = info[2], interval = info[3], offense = info[4],
		defense = info[5], speed = info[6], health = info[7];
	}

};

