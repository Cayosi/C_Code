#define _CRT_SECURE_NO_WARNINGS 1

#include "DymmTest.h"

void mallocTest()
{
	int* p = (int*)malloc(40); //用malloc开辟40个字节的空间
	if (p != NULL)//判断是否开辟成功
	{
		for (size_t i = 0; i < 10; i++)
		{
			*(p + i) = i;
		}

		for (size_t i = 0; i < 10; i++)
		{
			printf("%d ", p[i]);
		}
	}
	else
	{
		perror("malloc");//malloc开辟内存失败
		return 1;//返回错误码
	}

	free(p);//释放内存
	p = NULL;//野指针置空
}


void callocTest()
{
	//calloc开辟好空间后会把开辟空间内的每个字节都置0
	int* p = (int*)calloc(10, sizeof(int));//使用calloc开辟10个整形的空间
	if (p != NULL)
	{
		for (size_t i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
}
void reallocTest()

{
	int* p = (int*)malloc(4);//使用malloc开辟4个字节的空间
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}
	int* temp =(int*)realloc(p, 40);//使用realloc调账空间大小为40个字节
	if (temp != NULL)//判断realloc开辟空间是否成功
	{
		p = temp;
		temp = NULL;
		for (size_t i = 0; i < 10; i++)
		{
			*(p+i) = i + 1;
		}
		for (size_t i = 0; i < 10; i++)
		{
			printf("%d ", *(p+i));
		}
	}
	else
	{
		perror("realloc");//realloc开辟空间失败
		return 1;
	}

}