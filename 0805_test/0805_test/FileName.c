#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

int isPowerOfTwo(int n)
{
	int result = 2;
	for (int i = 0; i < n; i++)
	{
		result *= 2;
	}
}

//写的有毛病
void halfFind(int num[10],int res)
{
	int len = sizeof(num) / sizeof(num[0]);
	int left = 0;
	int right = len - 1;
	int find = 0;
	while (left <= right)
	{
		int	mid = (left + right) / 2;

		if (num[mid] > res)
		{
			right = mid - 1;

		}
		else if (num[mid] < res)
		{
			left = mid + 1;
		}
		else
		{
			find = 1;
			printf("找到了是下标位%d的元素\n", mid);
			break;

		}

	}
	if (find == 0)
	{
		printf("数组中没有该元素\n");
	}
	

}
int main()
{
	int num[] = { 1,2,3,4,5,6,7,8,9,10 };
	halfFind(num, 4);

	return 0;
}