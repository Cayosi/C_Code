#define _CRT_SECURE_NO_WARNINGS

#include <stddef.h>
#include <stdio.h>

void MergeOutput(int n, int m)// 两组有序数组合并后正序输出
{
	int num1[1000];
	int num2[1000];
	int i = 0;
	int j = 0;
	printf("请输入第一组正序数据\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num1[i]);
	}
	printf("请输入第二组正序数据\n");
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &num2[i]);
	}

	// 谁小谁打印 打印后下标+1
	while (i < n && j < m)
	{
		if (num1[i] <= num2[j])
		{
			printf("%d ", num1[i]);
			i++;
		}
		else
		{
			printf("%d ", num2[j]);
			j++;
		}
	}
	//到这里后 有可能有其中一组没有打印完(肯定是比前面的都大了而且是正序，直接遍历打印
	while (i < n)
	{
		printf("%d ", num1[i]);
		i++;
	}
	while (j < m)
	{
		printf("%d ", num2[j]);
		j++;
	}
}
void is_prime(int min, int max)
{
	int flag;
	int count = 0;
	int cpu = 0;
	printf("\n%d到%d之间的素数有->\n", min, max);
	for (int i = min; i < max; i++) {
		flag = 1;
		for (int j = 2; j < i - 1; j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			cpu += i;
			printf("%d ", i);
			count++;
			if (count % 5 == 0)
			{
				printf("\n");
			}
		}
	}

	printf("\n%d到%d之间的素数和是%d\n", min, max, cpu);
}

int leapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void isTrue(int res)
{

	if (res)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
}

void mutTable(int size)
{
	// i的值是行号同时也等于每行要打印的次数
	for (int i = 1; i <= size; i++)
	{

		for (int j = 1; j <= i ; j++)
		{
			printf("%d * %d = %d ", i, j, i * j);
		}

		printf("\n");

	}
}
void init(int num[], int size, int res)
{
	for (int i = 0; i < size; i++)
	{
		num[i] = res;
	}
}
void print(int num[],int size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
}
void reverse(int num[],int size)
{
	int temp[1000];
	int flag = size -1;
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = num[i];
	}
	for (size_t i = 0; i < size; i++)
	{
		num[flag] = temp[i];
		flag--;
	}
	
}
int main()
{

	int num[5] = { 1,2,3,4,5 };
	int size = sizeof(num) / sizeof(num[0]);
	printf("原数组为-> ");
	print(num,5);
	reverse(num,size);
	/*init(num, 5, 1);*/
	printf("逆置后为-> ");
	print(num, 5);
	init(num, 5, 0);
	printf("初始化后为-> ");
	print(num, 5);
	return 0;
}