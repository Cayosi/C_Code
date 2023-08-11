#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)



#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("*****   1.开始游戏   *****\n");
	printf("*****   0.退出游戏   *****\n");
	printf("**************************\n");
}
void game()
{

	srand((unsigned int)time(NULL));//初始化随机数种子为时间戳
	//棋盘定义
	char mine[ROWS][COLS];//雷
	char show[ROWS][COLS];//排查雷的信息
	//初始化棋盘
	initBoard(mine,ROWS,COLS,'0');
	initBoard(show,ROWS,COLS,'*');
	//布置雷
	setMine(mine, ROW, COL);
	//显示棋盘
	displayBoard(show, ROW, COL);
	//排查雷
	scouriMine(mine, show, ROW, COL);
}

int main()
{
	int input = 0;
	
	srand((unsigned int)time(NULL));//初始化随机数种子为时间戳
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误请重新输入！！\n");
			break;
		}
	} while (input);
	return 0;
}