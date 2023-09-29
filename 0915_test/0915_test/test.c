#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>

typedef void(*tes)(int);//给 void(*)(int) 类型 重新命名为 tes  


int sum(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int main()
{
	//void (*test(void(*)(int), int))(int);
	//上下等价
	//tes test(tes, int); 

	//函数指针数组，存放函数指针的数组
	int(*pArr[4])(int, int) = { sum,sub }; 
	return 0;
}