#include "SeqList.h"


//打印顺序表
void SeqListPrint(SeqList* ps)
{
	if (ps && ps->a)
	{
		for (size_t i = 0; i < ps->size; i++)//遍历
		{
			printf("%d ", ps->a[i]);
		}
		printf("\n");
	}

}
//扩容检查
void CheckCap(SeqList* ps)
{
	assert(ps != NULL);
	if (ps->capacity == 0)
	{
		SLDateType* tmp = malloc(sizeof(SLDateType) * 4);
		if (tmp!=NULL)
		{
			ps->a = tmp;
			ps->capacity = 4;
		}
		else
		{
			perror("malloc");
		}
	}
	else if (ps->size == ps->capacity)
	{
		SLDateType* tmp = realloc(ps->a, 2 * ps->capacity * sizeof(SLDateType));
		if (tmp != NULL)
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
		else
		{
			perror("realloc");
		}
	}
}

//顺序表初始化
void SeqListInit(SeqList* ps)
{
	assert(ps != NULL);
		ps->size = 0;
		ps->capacity = 0;
		ps->a = NULL;
	

}

//顺序表销毁
void SeqListDestroy(SeqList* ps)
{
	if (ps)
	{
		if (ps->a)
		{
			free(ps->a);
			ps->a = NULL;
			ps->size = 0;
			ps->capacity = 0;
		}
	}
}

//在pos位置插入数据
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	if (pos >=0)
	{
		CheckCap(ps);
		for (size_t i = ps->size; i > pos; i--)
		{
			ps->a[i] = ps->a[i - 1];
		}
		ps->a[pos] = x;
		ps->size++;
	}
}

//在pos位置删除数据
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps != NULL);
	assert(ps->a != NULL);
	if (pos>=0 && pos<= ps->size-1)//边界判断
	{
		for (size_t i = pos; i < ps->size; i++)
		{
			ps->a[pos] = ps->a[pos + 1];
			pos++;
		}
		ps->size--;
	}

}

//查找数据，找到返回下标，否则返回-1
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps != NULL);
	assert(ps->a != NULL);
	if (ps)
	{
		for (int i = 0; i < ps->size; i++)
		{
			if (ps->a[i] == x)
			{
				return i;
			}
		}
	}

	return -1;
}

//尾插
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	SeqListInsert(ps, ps->size,x);
}

//头插
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	SeqListInsert(ps, 0, x);
}
//尾删
void SeqListPopFront(SeqList* ps)
{
	SeqListErase(ps, 0);
}
//头删
void SeqListPopBack(SeqList* ps)
{
	SeqListErase(ps, ps->size-1);
}

