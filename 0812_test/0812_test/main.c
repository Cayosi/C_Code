#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int juice(int money)
{
	int price = 1;
	int change = 2;
	int num = 0;
	//用钱买的
	num = money / price;
	int fin = num;

	while (num > 0)
	{
		//空瓶换的
		num = num / change;
		fin += num;
	}
	return fin;
}

int main()
{
	printf("%d\n", juice(20));

	return 0;
}

int sumFive(int num, int flag)
{
	int res = 0;//总和
	int now = 0;//单次计算
	int digit = 1;//位数

	for (int i = 0; i < flag; i++)
	{
		if (i > 0)
		{
			digit *= 10;
		}

		now += num * digit;
		res += now;
	}
	return res;
}

int countDigits(int num) {
	int count = 0;

	// 处理负数情况
	if (num < 0) {
		num = -num;
	}

	// 特殊处理 num 为 0 的情况
	if (num == 0) {
		return 1;
	}

	// 计算位数
	while (num > 0) {
		num /= 10;
		count++;
	}

	return count;
}

void Narcissistic(int min, int max)
{
	for (int i = min; i <= max; i++)
	{
		int target = 0;
		int num = i;

		// 让每一位次方运算后的结果相加
		for (int j = 0; j < countDigits(i); j++)
		{
			int temp = 0;
			int once = 1;
			temp += num % 10;

			// 每一位的次方运算
			for (int z = 0; z < countDigits(i); z++)
			{
				once *= temp;
			}

			target += once;
			num /= 10;
		}

		// 判断经过运算后是否相等（相等则为水仙花数，进行输出打印）
		if (target == i)
		{
			printf("%d ", i);
		}
	}
}

int Rhombus(int line)
{
	if (line % 2 == 0)
	{
		printf("请传入奇数");
		return 0;
	}
	//打印上半部分
	for (int i = 1; i <= line; i += 2) {
		// 打印空格
		for (int space = 0; space < (line - i) / 2; space++) {
			printf(" ");
		}

		// 打印星号
		for (int j = 0; j < i; j++) {
			printf("*");
		}

		printf("\n");
	}

	// 打印下半部分
	for (int i = line - 2; i >= 1; i -= 2) {
		// 打印空格
		for (int space = 0; space < (line - i) / 2; space++) {
			printf(" ");
		}

		// 打印星号
		for (int j = 0; j < i; j++) {
			printf("*");
		}

		printf("\n");
	}
	return 1;
}