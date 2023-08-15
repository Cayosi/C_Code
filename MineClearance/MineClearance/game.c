#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include "game.h"

void initBoard(char Board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Board[i][j] = set;
		}
	}
}

void displayBoard(char Board[ROWS][COLS], int row, int col)
{
	printf("-----扫雷游戏-----\n");
	//打印列标
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}

	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		//打印行标
		printf("%d ", i);

		//打印棋盘
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", Board[i][j]);
		}

		printf("\n");
	}
	printf("-----扫雷游戏-----\n");
}

void setMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % (row + 1);
		int y = rand() % (col + 1);
		if (mine[x][y] == '0')//判断如果不是雷，则布置雷，是雷重新随机
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int getMineCount(char mine[ROWS][COLS], int x, int y)
{
	//数字字符减去字符 0 得到 整形
	return (mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x - 1][y] +
		mine[x + 1][y] +
		mine[x - 1][y - 1] +
		mine[x + 1][y - 1] +
		mine[x - 1][y + 1] +
		mine[x + 1][y + 1]) -
		8 * '0';
}

void scouriMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;
	while (win < row*col-EASY_COUNT)
	{
		printf("请输入要排查的坐标-> ");
		scanf("%d %d", &x, &y);
		printf("\n");
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断输入是否合法
		{
			//如果排查的坐标是"雷"游戏结束不是"雷"把show数组当前坐标的值改为周围有几个"雷"
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了！！\n");
				displayBoard(mine, row, col);
				break;
			}
			else if (show[x][y] != '*')
			{
				printf("已经排查过了请重新输入\n");
			}
			else
			{
				int res = getMineCount(mine, x, y);
				show[x][y] = res + '0';
				displayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("非法输入请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功！！\n");
		displayBoard(mine,row,col);
	}
}