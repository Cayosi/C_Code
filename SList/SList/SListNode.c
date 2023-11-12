#include <stdio.h>
#include "SListNode.h"
#include "stdlib.h"
#include <assert.h>
//打印链表
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

//创建新节点
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

//头插
void SLNPushFront(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* newNode = CreatNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}
//尾插
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


//尾删
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
	//一个节点
	if (prev == NULL) 
	{
		free(cur);
		*pphead = NULL;
	}
	//多个节点
	else 
	{
		prev->next = NULL;
		free(cur);
	}
}


//头删
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

//在pos位置后面插入数据
void SListInsertAfter(SLNode* pos, SLNDataType x)
{
	assert(pos);
		SLNode* next = pos->next;
		pos->next = CreatNode(x);
		pos->next->next = next;

	
}

//在pos位置前面插入数据，不许尾插
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
			//有歹人不获取位置瞎传
			if (front == NULL)
			{
				return;
			}
		}
		front->next = CreatNode(x);
		front->next->next = pos;
	}
}

//删除pos后面的数据
void SListEraseAfter(SLNode* pos)
{
	assert(pos);
	assert(pos->next);
		SLNode* next = pos->next;
		pos->next = next->next;
		free(next);
		next = NULL;
	
}
//删除pos位置
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
//销毁链表
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