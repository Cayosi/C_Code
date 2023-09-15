#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>

//void mySort(const void* basic, size_t nitems, size_t size, int(*compar)(const void*, const void*))
//{
//	char* tmp = (char*)basic;
//	for (size_t i = 0; i < nitems - 1; i++)
//	{
//		int flag = 1;
//		for (size_t j = 0; j < nitems - 1 - i; j++)
//		{
//			char* op1 = tmp + (j * size);
//			char* op2 = tmp + ((j+1) * size);
//			if (compar(op1, op2) > 0)
//			{
//				flag = 0;
//				for (size_t k = 0; k < size; k++)
//				{
//					char temp;
//					temp = *(op1 + k);
//					*(op1 + k) = *(op2 + k);
//					*(op2 + k) = temp;				
//				}
//			}
//		}
//		if (flag)
//		{
//			return;
//		}
//	}
//}
void myBubSort(void* basic, size_t nitems, size_t size, int (*compar)(const void*, const void*)) {
	char* tmp = (char*)basic;
	int flag = 1;
	size_t lastSwap = nitems - 1;

	while (flag) {
		flag = 0;
		size_t newLastSwap = 0;//在循环内部每次交换时都会记录 j 的值 在下一轮遍历时，只需要遍历到这个位置之前的元素
		for (size_t j = 0; j < lastSwap; j++) {
			char* op1 = tmp + (j * size);
			char* op2 = tmp + ((j + 1) * size);
			if (compar(op1, op2) > 0) {
				for (size_t k = 0; k < size; k++) {
					char temp;
					temp = *(op1 + k);
					*(op1 + k) = *(op2 + k);
					*(op2 + k) = temp;
				}
				flag = 1;
				newLastSwap = j;
			}
		}
		lastSwap = newLastSwap;
	}
}
int compar(const void* x, const void* y)
{
	return *(int*)x - *(int*)y;
}
int main()
{
	int arr[10] = { 1, 2,0,23,5,6,22,10,21,17 };
	myBubSort(arr, 10, 4, compar);
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}