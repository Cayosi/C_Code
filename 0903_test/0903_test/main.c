#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#include <assert.h>
#include <string.h>
////指针变量的⼤⼩取决于地址的⼤⼩
////32位平台下地址是32个bit位（即4个字节）
////64位平台下地址是64个bit位（即8个字节）
//int main()
//{
//	//int arr[10] = { 0 };
//	//int res = &arr[0] - &arr[9];
//	//printf("%d\n", res);
//
//	//for (int i = 0; i < len; i++)
//	//{
//	//	printf("%d ", *(p + i));// 指针+整数跳到下一个元素的地址
//	//}
//	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int len = sizeof(arr) / sizeof(arr[0]);
//	//int* p = &arr[0];
//	//while (p<arr+len) //指针比较
//	//{
// //   printf("%d ",*p);
//	//p++;
//	//}
//
//	//int a = 2;
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	return 0;
//}
void my_print(int* arr, size_t sz)
{
	for (size_t i = 0; i < sz; i++)
	{
		printf("%d ", *(arr + i));
	}
}
size_t my_strlen(char* tmp)
{
	assert(tmp);
	size_t count = 0;
	while (*(tmp++))
	{
		count++;
	}
	return count;
}
void str_left(char* basic, int k)
{

	size_t len = strlen(basic);

	assert(k <= len);

	//左旋 每一次把首元素移到尾元素一共移k次
	for (size_t i = 0; i < k; i++)
	{
		char tmp = basic[0];
		for (size_t j = 0; j < len - 1; j++)
		{
			basic[j] = basic[j + 1];
		}
		basic[len - 1] = tmp;
	}
}

void reversed_order(char* basic)
{
	size_t len = strlen(basic);
	char tmp[10000] = { 0 };
	size_t flag = len;
	char* p1 = tmp;
	//倒序复制一份除了\0的basic
	for (size_t i = 0; i < len; i++)
	{
		tmp[i] = basic[flag - 1];
		flag--;
	}
	//交换
	while (*basic)
	{
		*(basic++) = *(p1++);
	}
}

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int* const basic, size_t sz)
{
	assert(basic);

	//冒泡sz-1趟
	for (size_t i = 0; i < sz - 1; i++)
	{
		//每趟比较sz-i-1个
		for (size_t j = 0; j < sz - i - 1; j++)
		{
			if (*(basic + j) > *(basic + j + 1))
			{
				swap((basic + j), (basic + j + 1));
			}
		}

	}
}
void reorderArray(int array[], size_t length)
{
	assert(array);
	int left = 0;
	int right = length - 1;
	while (left < right)
	{
		//从左边找偶数
		while (array[left] % 2 != 0)
		{
			left++;
		}
		//从右边找奇数
		while (array[right] % 2 == 0)
		{
			right--;
		}
		//交换
		swap(&array[left], &array[right]);
	}
}

int spinJudge(const char* const basic1, const char* const basic2)
{

	size_t length = strlen(basic1);

	if (strcmp(basic1, basic2) == 0)
	{
		return 0;
	}

	else
	{
		int k = 1;
		for (size_t i = 0; i < length - 1; i++)
		{
			str_left(basic2, k);
			if (strcmp(basic1, basic2) == 0)
			{
				return 1;
			}
			else
			{
				k++;
			}
		}
		return 0;
	}

}int countOnes(int n) {
	int count = 0;

	while (n != 0) {
		//n = 1时 count + 1
		count += n & 1;
		//每次运算后干掉最后一位
		n >>= 1;
	}

	return count;
}
void aloneNum(int* arr, size_t length)
{
	int res = 0;
	for (size_t i = 0; i < length; i++)
	{
		res ^= arr[i];
	}
	printf("单身狗是：%d\n",res);
}
int main()
{
	int i = 1;
	int ret = (++i) + (++i) + (++i);
	printf("ret = %d\n", ret);
	//int arr[] = { 1,2,3,4,5,1,2,3,4};
	//size_t length = sizeof(arr) / sizeof(arr[0]);
	//aloneNum(arr, length);

	/*int a = 1;
	int b = 2;
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a=%d\nb=%d", a, b);
	int n;
	printf("请输入一个整数：");
	scanf("%d", &n);

	int onesCount = countOnes(n);

	printf("%d的二进制表示中1的个数是：%d\n", n, onesCount);*/
	//int arr[10] = { 5,1,5,6,2,74,12,45,34,21 };
	//char arr1[] = "abcd";
	//char arr2[] = "abcd";

	//printf("%d ", spinJudge(arr1, arr2));

	return 0;
}