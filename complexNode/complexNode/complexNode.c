#include "complexNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* head = malloc(sizeof(ListNode));
	if (!head)
	{
		perror("malloc");
		exit(-1);
	}
	head->_next = head;
	head->_prev = head;

	return head;
}

//创建新节点
ListNode* NewNode()
{
	ListNode* newNode = malloc(sizeof(ListNode));
	if (!newNode)
	{
		perror("malloc");
		exit(-1);
	}
	return newNode;
}
// 双向链表销毁
void ListDestory(ListNode** pHead)
{
	ListNode* destory = (*pHead)->_next;
	ListNode* tmp;
	while (destory != *pHead)
	{
		tmp = destory->_next;
		free(destory);
		destory = tmp;
	}
	free(*pHead);
	*pHead = NULL;
}
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	for (ListNode* i = pHead; i->_next!=pHead; i=i->_next)
	{
		printf("%d ", i->_next->_data);
	}
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListNode* newNode = NewNode();
	pHead->_prev->_next = newNode;
	newNode->_prev = pHead->_prev;
	newNode->_next = pHead;
	pHead->_prev = newNode;
	newNode->_data = x;
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	if (pHead->_next == pHead)
	{
		return;
	}
	ListNode* del = pHead->_prev;
	pHead->_prev = del->_prev;
	pHead->_prev->_next = pHead;
	free(del);
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	if (pHead->_next == pHead)
		ListPushBack(pHead, x);
	else
	{
		ListNode* newNode = NewNode();

		ListNode* tmp = pHead->_next;
		pHead->_next = newNode;
		newNode->_prev = pHead;
		newNode->_next = tmp;
		tmp->_prev = newNode;
		newNode->_data = x;
	}

	
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	if (pHead->_next!=pHead)
	{
		
		if (pHead->_next->_next == pHead)
		{
			free(pHead->_next);
			pHead->_next = pHead;
			pHead->_prev = pHead;
		}
		else
		{
			ListNode* pop = pHead->_next;
			pHead->_next = pop->_next;
			free(pop);
		}
	}
	
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	for (ListNode* i = pHead; i->_next != pHead; i = i->_next)
	{
		if (i->_next->_data == x)
		{
			return i->_next;
		}
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* tmp = pos->_prev;
	ListNode* newnode = NewNode();
	tmp->_next = newnode;
	newnode->_prev = tmp;
	newnode->_next = pos;
	pos->_prev = newnode;
	newnode->_data = x;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}