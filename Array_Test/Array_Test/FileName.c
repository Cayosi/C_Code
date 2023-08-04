#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

int Fun(int n)
{
	if (n == 5)
		return 2;
	else
		return 2 * Fun(n + 1);
}


//int main()
//{
//	int num[10];
//	float sum = 0;
//	printf("请输入十个整数\n");
//	for (size_t i = 0; i < 10; i++)
//	{
//		scanf("%d ", &num[i]);
//		sum += num[i];
//	}
//	
//	printf("%.2f\n", sum / 10);
//	
//	return 0;
//}

//int main()
//{
//	
//	int temp;
//	int arr1[3] = { 1,2,3 };
//	int arr2[3] = { 3,2,1 };
//	int len = sizeof(arr1) / sizeof(arr1[0]);
//	printf("交换前的数组\n");
//	printf("arr1 = {");
//	for (int i = 0; i < len; i++)
//	{
//		if (i == len - 1)
//		{
//			printf("%d", arr1[i]);
//		}
//		else
//		{
//			printf("%d,", arr1[i]);
//		}
//
//	}
//	printf("}\n");
//	printf("arr2 = {");
//	for (int i = 0; i < len; i++)
//	{
//		if (i == len - 1)
//		{
//			printf("%d", arr2[i]);
//		}
//		else
//		{
//			printf("%d,", arr2[i]);
//		}
//
//	}
//	printf("}\n");
//	for (int i = 0; i < len; i++)
//	{
//		temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp;
//	}
//	printf("交换后的数组\n");
//	printf("arr1 = {");
//	for (int i = 0; i < len; i++)
//	{
//		if (i == len - 1)
//		{
//			printf("%d", arr1[i]);
//		}
//		else
//		{
//			printf("%d,", arr1[i]);
//		}
//		
//	}
//	printf("}\n");
//
//	printf("arr2 = {");
//	for (int i = 0; i < len; i++)
//	{
//		if (i == len - 1)
//		{
//			printf("%d", arr2[i]);
//		}
//		else
//		{
//			printf("%d,", arr2[i]);
//		}
//		
//	}
//	printf("}\n");
//	return 0;
//}
int MaxCommon(int a, int b)
{
	int c;
	while (1)
	{
		c = a % b;
		if (c == 0)
		{
			return b;

		}
		else {
			a = b;
			b = c;
		}
	}
	}

void leapYear(int min, int max)
{
	int count = 0;
	printf("%d年到%d年中闰年有：\n", min, max);
	for (int i = min; i <= max; i++)
	{
		if ((i % 100 != 0 && i % 4 == 0) || (i % 400 == 0))
		{
			count++;
			printf("%d年 ", i);
			if (count % 10 == 0)
			{
				printf("\n");
			}
		}
	}
	printf("\n共%d个闰年\n", count);
}
int main()
{
	leapYear(1000, 2000);
	return 0;
}