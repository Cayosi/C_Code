#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int juice(int money)
{
	int price = 1;
	int change = 2;
	int num = 0;
	//��Ǯ���
	num = money / price;
	int fin = num;

	while (num > 0)
	{
		//��ƿ����
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
	int res = 0;//�ܺ�
	int now = 0;//���μ���
	int digit = 1;//λ��

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

	// ���������
	if (num < 0) {
		num = -num;
	}

	// ���⴦�� num Ϊ 0 �����
	if (num == 0) {
		return 1;
	}

	// ����λ��
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

		// ��ÿһλ�η������Ľ�����
		for (int j = 0; j < countDigits(i); j++)
		{
			int temp = 0;
			int once = 1;
			temp += num % 10;

			// ÿһλ�Ĵη�����
			for (int z = 0; z < countDigits(i); z++)
			{
				once *= temp;
			}

			target += once;
			num /= 10;
		}

		// �жϾ���������Ƿ���ȣ������Ϊˮ�ɻ��������������ӡ��
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
		printf("�봫������");
		return 0;
	}
	//��ӡ�ϰ벿��
	for (int i = 1; i <= line; i += 2) {
		// ��ӡ�ո�
		for (int space = 0; space < (line - i) / 2; space++) {
			printf(" ");
		}

		// ��ӡ�Ǻ�
		for (int j = 0; j < i; j++) {
			printf("*");
		}

		printf("\n");
	}

	// ��ӡ�°벿��
	for (int i = line - 2; i >= 1; i -= 2) {
		// ��ӡ�ո�
		for (int space = 0; space < (line - i) / 2; space++) {
			printf(" ");
		}

		// ��ӡ�Ǻ�
		for (int j = 0; j < i; j++) {
			printf("*");
		}

		printf("\n");
	}
	return 1;
}