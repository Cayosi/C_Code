#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
//int main()
{
	int test[] = { 1,2,34 };
	char test2[] = { '1', '2', 'd' };
	int res = sizeof(test2) / sizeof(test2[0]);
		for (int i = 0; i < res; i++)
		{
			printf("%p\n", &test2[i]);

		}

	return 0;
}

