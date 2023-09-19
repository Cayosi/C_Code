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
			return 1;//�ҵ���
		}
		else if (current > target)
		{
			col--;// ��ǰԪ�ؽϴ������ƶ�7һ��
		}
		else
		{
			row++; //��ǰԪ�ؽ�С�������ƶ�һ��
		}
	}
	return 0;//û�ҵ�
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
		printf("������Ҫ���ҵ�����->:");
		scanf("%d", &target);
		if (serch(matrix, 3, 3, target))
		{
			printf("�ҵ���\n");
		}
		else
		{
			printf("û�ҵ�\n");
		}
	}

	return 0;
}