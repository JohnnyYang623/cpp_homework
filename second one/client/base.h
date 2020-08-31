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

/*���ֻ�������:
�����ͣ��߹�����
����ͣ�������ֵ��
�����ͣ��߷�����
�����ͣ��͹�����������ٶ�*/



class PokemonBase
	//������
{

public:
	/*
	����ʮ�ֳ�Ա������name��������ʽmoves, �ȼ�grade������ֵexp������miss���������interval��
	����ֵoffense������ֵdefense���ٶ�speed������health
	*/
	string name, move1, move2;
	int miss_base, grade_base, exp_base, interval_base, offense_base, defense_base, speed_base, health_base;
	/*
	������
	����exps���洢�þ���������������Ҫ�ľ��顣
	����upgrade_data��ÿ��һ���������Ի�õļӳɡ����Ŀǰ��д����Ϊ��ͬ���͵ľ���ÿ��һ����õĸ�������ֵ��һ����
	��������attack���β�Ϊ��һֻ���顣����ֵΪ��һֻ������������������������ֻ�����໥����һ�κ�Ľ����
	��ȡ�þ�����Ϣ����get_info������ֵΪһ�����顣�����СΪ8���ֱ��Ǹþ����
		grade, exp, miss, interval, offense, defense, speed, health
	��������upgrade���β�Ϊ��õľ���ֵ������exps�жϵ�ǰ����ľ���ֵ�Ƿ������������ľ���ֵ������ǵĻ������������
		ͬʱ��������upgrade_data����
	�򶷺���fight���β�����һֻ�����ָ�����ֵ���ݡ������Ժ�ʼѭ��������attack�������н��㡣һ����⵽�Լ���������βεľ�������ֵС��0����ֹͣս����
		��ʤ�ľ����ȡ��ͬ�ڶԷ�����ȼ��ľ���ֵ����ʱ������ֻ����������������˳�ѭ����������

	*/

	//���캯����ÿֻ�����ʼ����һ�������Գ�ʼ�������ʼ���ԡ�
	PokemonBase();
	//��������ľ���
	int exps[14] = { 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30 };

	int get_exp() { return exps[1]; }

	//ÿ��һ������õ���������
	int upgrade_data[4] = { 2, 2, 2, 2 };




	//��ȡ����
	string get_name();


};
