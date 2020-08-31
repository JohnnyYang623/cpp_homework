#pragma once

#include<iostream>
#include<stdlib.h>
#include<string>
#include"vector"
//#include<time.h>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

/*四种基本类型:
力量型：高攻击；
肉盾型：高生命值；
防御型：高防御；
敏捷型：低攻击间隔，高速度*/



class PokemonBase
	//主基类
{

public:
	/*
	包含十种成员：名字name，攻击方式moves, 等级grade，经验值exp，闪避miss，攻击间隔interval，
	攻击值offense，防御值defense，速度speed，生命health
	*/
	string name, move1, move2;
	int miss_base, grade_base, exp_base, interval_base, offense_base, defense_base, speed_base, health_base;
	/*
	包含：
	数组exps：存储该精灵升到各级所需要的经验。
	数组upgrade_data：每升一级，各属性获得的加成。这个目前不写，因为不同类型的精灵每升一级获得的各项属性值不一样。
	攻击函数attack：形参为另一只精灵。返回值为另一只精灵的生命。这个函数结算两只精灵相互攻击一次后的结果。
	获取该精灵信息函数get_info：返回值为一个数组。数组大小为8。分别是该精灵的
		grade, exp, miss, interval, offense, defense, speed, health
	升级函数upgrade：形参为获得的经验值。依据exps判断当前精灵的经验值是否大于升级所需的经验值。如果是的话则进行升级。
		同时依据数组upgrade_data内容
	打斗函数fight：形参是另一只精灵的指针而非值传递。进入以后开始循环，调用attack函数进行结算。一旦检测到自己精灵或者形参的精灵体力值小于0，就停止战斗。
		获胜的精灵获取等同于对方精灵等级的经验值。此时调用两只精灵的升级函数。退出循环，结束。

	*/

	//构造函数，每只精灵初始属性一样，所以初始化各项初始属性。
	PokemonBase();
	//升级所需的经验
	int exps[14] = { 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30 };

	int get_exp() { return exps[1]; }

	//每升一级所获得的能力提升
	int upgrade_data[4] = { 2, 2, 2, 2 };




	//获取姓名
	string get_name();


};
