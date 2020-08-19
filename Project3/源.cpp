#include"pokemons.h"

/*
主基类Pokemon。
由主基类继承四种基础基类：
力量型Offensive,防御型Defensive,肉盾型Power,敏捷型Agile。
定义在头文件里面。
*/

int main()
{
	Pokemon a{ 3,1 }, b{ 4,1 };
	a.fight(&b);
	system("pause");
	return 0;
}