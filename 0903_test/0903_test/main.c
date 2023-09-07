#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
//指针变量的⼤⼩取决于地址的⼤⼩
//32位平台下地址是32个bit位（即4个字节）
//64位平台下地址是64个bit位（即8个字节）
int main()
{
	//int arr[10] = { 0 };
	//int res = &arr[0] - &arr[9];
	//printf("%d\n", res);

	//for (int i = 0; i < len; i++)
	//{
	//	printf("%d ", *(p + i));// 指针+整数跳到下一个元素的地址
	//}
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int len = sizeof(arr) / sizeof(arr[0]);
	//int* p = &arr[0];
	//while (p<arr+len) //指针比较
	//{
 //   printf("%d ",*p);
	//p++;
	//}

	//int a = 2;
	char* a[] = { "work","at","alibaba" };
	char** pa = a;
	return 0;
}