#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#include <stdbool.h>

//int serch(int *matrix, int matrixRow, int matrixColn, int target)
//{
//	for (size_t i = 0; i < matrixRow; i++)
//	{
//		for (size_t j = 0; j < matrixColn; j++)
//		{
//			if ((matrix+matrixColn*i)[j] == target)
//			{
//				return 1;
//			}
//		}
//	}
//	return 0;
//}

int serch(int* matrix, int matrixRow, int matrixColn, int target)
{
	int row = 0;
	int col = matrixColn - 1;
	while (row < matrixRow && col >= 0)
	{
		int current = (matrix+matrixRow*row)[col];
		if (current == target)
		{
			return 1;//找到了
		}
		else if (current > target)
		{
			col--;// 当前元素较大，向左移动7一列
		}
		else
		{
			row++; //当前元素较小，向下移动一行
		}
	}
	return 0;//没找到
}
int main()
{
	int matrix[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int target;

	while (true)
	{
		printf("请输入要查找的数字->:");
		scanf("%d", &target);
		if (serch(matrix, 3, 3, target))
		{
			printf("找到了\n");
		}
		else
		{
			printf("没找到\n");
		}
	}

	return 0;
}