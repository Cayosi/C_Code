#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

int halfFind(int num[], int len,int res)
{
	int left = 0;
	int right = len - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
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
			return mid;
		}
	}
	return -1;
}


int main()
{

	int num[] = { 1,2,3,4,5,6,7,8,9,10 };
	int find1 = halfFind(num, 10, 1);
	int find2 = halfFind(num, 10, 10);
	int find3 = halfFind(num, 10, 5);
	int find4 = halfFind(num, 10, 11);
	printf("%d\n", find1);
	printf("%d\n", find2);
	printf("%d\n", find3);
	printf("%d\n", find4);
	return 0;
}