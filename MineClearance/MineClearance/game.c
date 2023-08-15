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
	printf("-----ɨ����Ϸ-----\n");
	//��ӡ�б�
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}

	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		//��ӡ�б�
		printf("%d ", i);

		//��ӡ����
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", Board[i][j]);
		}

		printf("\n");
	}
	printf("-----ɨ����Ϸ-----\n");
}

void setMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % (row + 1);
		int y = rand() % (col + 1);
		if (mine[x][y] == '0')//�ж���������ף������ף������������
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int getMineCount(char mine[ROWS][COLS], int x, int y)
{
	//�����ַ���ȥ�ַ� 0 �õ� ����
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
		printf("������Ҫ�Ų������-> ");
		scanf("%d %d", &x, &y);
		printf("\n");
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж������Ƿ�Ϸ�
		{
			//����Ų��������"��"��Ϸ��������"��"��show���鵱ǰ�����ֵ��Ϊ��Χ�м���"��"
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը���ˣ���\n");
				displayBoard(mine, row, col);
				break;
			}
			else if (show[x][y] != '*')
			{
				printf("�Ѿ��Ų��������������\n");
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
			printf("�Ƿ���������������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�����\n");
		displayBoard(mine,row,col);
	}
}