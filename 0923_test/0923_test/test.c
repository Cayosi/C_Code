#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

void printobjb(int num) {
	unsigned int ob = 0;
	unsigned int jb = 0;

	for (size_t i = 0; i < sizeof(int) * 8; i++)
	{
		if (i % 2 == 0)
		{
			ob |= (num & (1 << i));
		}
		else
		{
			jb |= (num & (1 << i));
		}
	}

	
	printf("ż��λ����������: ");
	for (size_t i = 0; i < sizeof(int)*8; i++)
	{
		printf("%d", (ob >> i) & 1);
	}
	printf("\n");
	printf("����λ����������: ");
	for (size_t i = 0; i < sizeof(int) * 8; i++)
	{
		printf("%d", (jb >> i) & 1);
	}
}

int main()
{
	char test[] = "��ǰһС�� ����һ��";
	int i = 0;
	while (test[i] != '\0')
	{
		printf("%d", (*test >> i) & 1);
		i++;
	}
	return 0;
}