#include "List.h"




int initList(SeList* list)
{
	DataList* temp = calloc(Capacity, sizeof(DataList));
	if (temp != NULL)
	{
		list->datas = temp;
		list->cap = Capacity;
		list->len = 0;
		return 0;
	}
	else
	{
		perror("calloc");
		return 1;
	}

}


int dilatation(SeList* list)
{
	if (list->cap <= list->len + 1);
	{
		DataList* temp = realloc(list->datas, sizeof(list->datas[0]) * list->cap * Mul);
		if (temp != NULL)
		{
			list->datas = temp;
			return 0;
		}
		perror("realloc");	
		return 1;
	}
	return 0;
}

void headInsert(SeList* list, DataList data)
{
	
	 dilatation(list);//�����ж�


	if (list->len == 0)//list��û������
	{
		(list->datas)[0] = data;
		(list->len)++;
	}
	else
	{
		for (size_t i = list->len; i > 0; i--)
		{
			list->datas[i] = list->datas[i - 1];//��󿽱�����
		}
		(list->datas)[0] = data;
		(list->len)++;
	}

	
	}
	

	


void endInsert(SeList* list, DataList data)
{
	 dilatation(list);//�����ж�
	list->datas[list->len] = data;
	list->len++;
}

void endPop(SeList* list)
{
	list->len--;
}
void headPop(SeList* list)
{
	for (size_t i = 0; i < list->len-1; i++)
	{
		list->datas[i] = list->datas[i+1]; // ��һ������ǰһ��
	}
	list->len--;
}

void insert(SeList* list, DataList data, size_t length)
{
	  dilatation(list);//�����ж�
	for (size_t i = list->len; i > length; i--)
	{
		list->datas[i] =  list->datas[i-1]; // ǰһ�����Ǻ�һ��
	}
	list->datas[length] = data;
	list->len++;
}

void pop(SeList* list, size_t length)
{
	for (size_t i = length; i < list->len-1; i++)
	{
		list->datas[i] = list->datas[i+1]; // ��һ������ǰһ��
	}
	list->len--;
}