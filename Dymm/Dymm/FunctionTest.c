#define _CRT_SECURE_NO_WARNINGS 1

#include "DymmTest.h"

void mallocTest()
{
	int* p = (int*)malloc(40); //��malloc����40���ֽڵĿռ�
	if (p != NULL)//�ж��Ƿ񿪱ٳɹ�
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
		perror("malloc");//malloc�����ڴ�ʧ��
		return 1;//���ش�����
	}

	free(p);//�ͷ��ڴ�
	p = NULL;//Ұָ���ÿ�
}


void callocTest()
{
	//calloc���ٺÿռ���ѿ��ٿռ��ڵ�ÿ���ֽڶ���0
	int* p = (int*)calloc(10, sizeof(int));//ʹ��calloc����10�����εĿռ�
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
	int* p = (int*)malloc(4);//ʹ��malloc����4���ֽڵĿռ�
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}
	int* temp =(int*)realloc(p, 40);//ʹ��realloc���˿ռ��СΪ40���ֽ�
	if (temp != NULL)//�ж�realloc���ٿռ��Ƿ�ɹ�
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
		perror("realloc");//realloc���ٿռ�ʧ��
		return 1;
	}

}