#include <stdio.h>
#include "SListNode.h"
#include "stdlib.h"
#include <assert.h>
//��ӡ����
void NodePrint(SLNode* cur)
{	
	if (cur == NULL)
	{
		printf("NULL");
		return;
	}
	else
	{
		while (cur != NULL)
		{
			printf("%d ", cur->val);
			cur = cur->next;
		}

	}
	
	printf("\n");
}

//�����½ڵ�
SLNode* CreatNode(SLNDataType x)
{
	SLNode* newNode = malloc(sizeof(SLNode));
	if (newNode != NULL)
	{
		newNode->val = x;
		newNode->next = NULL;
		return newNode;
	}
	
		perror("malloc");
		exit(-1);
	
}

//ͷ��
void SLNPushFront(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* newNode = CreatNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}
//β��
void SLNPushBack(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* newNode = CreatNode(x);
	newNode->next = NULL;
	newNode->val = x;
	if (*pphead == NULL)
	{
		*pphead = newNode;
		
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}


//βɾ
void SLTPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);

	SLNode* cur = *pphead;
	SLNode* prev = NULL;

	while (cur->next != NULL) 
	{
		prev = cur;
		cur = cur->next;
	}
	//һ���ڵ�
	if (prev == NULL) 
	{
		free(cur);
		*pphead = NULL;
	}
	//����ڵ�
	else 
	{
		prev->next = NULL;
		free(cur);
	}
}


//ͷɾ
void SLTPopFront(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
		SLNode* node = *pphead;
		*pphead = (*pphead)->next;
		free(node);
		node = NULL;
	
}

SLNode* SLFind(SLNode* phead, SLNDataType x)
{
	SLNode* cur = phead;

	while (cur != NULL && cur->val != x  )
	{
		cur = cur->next;
	}
	return cur;
}

//��posλ�ú����������
void SListInsertAfter(SLNode* pos, SLNDataType x)
{
	assert(pos);
		SLNode* next = pos->next;
		pos->next = CreatNode(x);
		pos->next->next = next;

	
}

//��posλ��ǰ��������ݣ�����β��
void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x)
{
	assert(((pos==NULL) && (*pphead==NULL)) || ((pos!=NULL) && (*pphead!=NULL)));
	if (*pphead == pos)
	{
		SLNPushFront(pphead, x);
	}
	else
	{
		SLNode* front = *pphead;
		while (front->next != pos)
		{
			front = front->next;
			//�д��˲���ȡλ��Ϲ��
			if (front == NULL)
			{
				return;
			}
		}
		front->next = CreatNode(x);
		front->next->next = pos;
	}
}

//ɾ��pos���������
void SListEraseAfter(SLNode* pos)
{
	assert(pos);
	assert(pos->next);
		SLNode* next = pos->next;
		pos->next = next->next;
		free(next);
		next = NULL;
	
}
//ɾ��posλ��
void SLTErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);

	if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
		pos = NULL;
	}
	else
	{
		SLNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
		pos = NULL;
	}

}
//��������
void SLTDestroy(SLNode** pphead)
{
	SLNode* cur = *pphead;
	SLNode* tmp;
	while (cur != NULL)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}
	*pphead = NULL;
}