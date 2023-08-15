#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>

int main()
{
	

	int a = 3;
	int b = 4;
	printf("a = %d b = %d\n", a, b);
	//不创建中间变量，交换两个变量的值

	a = a + b;
	b = a - b;
	a = a - b;


	printf("a = %d b = %d\n", a, b);

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	printf("a = %d b = %d\n", a, b);
	return 0;
}