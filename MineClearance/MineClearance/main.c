#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)



#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("*****   1.��ʼ��Ϸ   *****\n");
	printf("*****   0.�˳���Ϸ   *****\n");
	printf("**************************\n");
}
void game()
{

	srand((unsigned int)time(NULL));//��ʼ�����������Ϊʱ���
	//���̶���
	char mine[ROWS][COLS];//��
	char show[ROWS][COLS];//�Ų��׵���Ϣ
	//��ʼ������
	initBoard(mine,ROWS,COLS,'0');
	initBoard(show,ROWS,COLS,'*');
	//������
	setMine(mine, ROW, COL);
	//��ʾ����
	displayBoard(show, ROW, COL);
	//�Ų���
	scouriMine(mine, show, ROW, COL);
}

int main()
{
	int input = 0;
	
	srand((unsigned int)time(NULL));//��ʼ�����������Ϊʱ���
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������������룡��\n");
			break;
		}
	} while (input);
	return 0;
}