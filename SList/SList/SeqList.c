#include "SeqList.h"


//��ӡ˳���
void SeqListPrint(SeqList* ps)
{
	if (ps && ps->a)
	{
		for (size_t i = 0; i < ps->size; i++)//����
		{
			printf("%d ", ps->a[i]);
		}
		printf("\n");
	}

}
//���ݼ��
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

//˳����ʼ��
void SeqListInit(SeqList* ps)
{
	assert(ps != NULL);
		ps->size = 0;
		ps->capacity = 0;
		ps->a = NULL;
	

}

//˳�������
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

//��posλ�ò�������
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

//��posλ��ɾ������
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps != NULL);
	assert(ps->a != NULL);
	if (pos>=0 && pos<= ps->size-1)//�߽��ж�
	{
		for (size_t i = pos; i < ps->size; i++)
		{
			ps->a[pos] = ps->a[pos + 1];
			pos++;
		}
		ps->size--;
	}

}

//�������ݣ��ҵ������±꣬���򷵻�-1
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

//β��
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	SeqListInsert(ps, ps->size,x);
}

//ͷ��
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	SeqListInsert(ps, 0, x);
}
//βɾ
void SeqListPopFront(SeqList* ps)
{
	SeqListErase(ps, 0);
}
//ͷɾ
void SeqListPopBack(SeqList* ps)
{
	SeqListErase(ps, ps->size-1);
}

