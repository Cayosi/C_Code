#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>

typedef void(*tes)(int);//�� void(*)(int) ���� ��������Ϊ tes  


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
	//���µȼ�
	//tes test(tes, int); 

	//����ָ�����飬��ź���ָ�������
	int(*pArr[4])(int, int) = { sum,sub }; 
	return 0;
}