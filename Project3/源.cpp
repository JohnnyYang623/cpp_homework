#include"pokemons.h"

/*
������Pokemon��
��������̳����ֻ������ࣺ
������Offensive,������Defensive,�����Power,������Agile��
������ͷ�ļ����档
*/

int main()
{
	Pokemon a{ 3,1 }, b{ 4,1 };
	a.fight(&b);
	system("pause");
	return 0;
}