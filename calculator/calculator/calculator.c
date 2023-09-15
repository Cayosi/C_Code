#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
void menu()
{
	printf("**********************\n");
	printf("*****1.sum 2.sub******\n");
	printf("*****3.mul 4.div******\n");
	printf("*****0.exit     ******\n");
	printf("**********************\n");
}
int sum(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}

int main()
{
	//
	int(*calp[])(int, int) = { 0,sum,sub,mul,div };
	char sym[] = { '0','+','-','*','/'};
	int input;
	int x;
	int y;

	do
	{
		x = 0;
		y = 0;
		input = 0;
		menu();
		printf("请选择->：");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入两个整形->：");
			scanf("%d %d", &x, &y);
			printf("\n%d%c%d = %d\n", x,sym[input],y,calp[input](x, y));
		}
		else if (input == 0)
		{
			break;
		}
		else
		{
			printf("输入错误重新输入\n");
		}
	} while (input);
	return 0;
}