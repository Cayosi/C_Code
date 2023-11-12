#include "complexNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// �������������ͷ���.
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

//�����½ڵ�
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
// ˫����������
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
// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	for (ListNode* i = pHead; i->_next!=pHead; i=i->_next)
	{
		printf("%d ", i->_next->_data);
	}
	printf("\n");
}
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListNode* newNode = NewNode();
	pHead->_prev->_next = newNode;
	newNode->_prev = pHead->_prev;
	newNode->_next = pHead;
	pHead->_prev = newNode;
	newNode->_data = x;
}
// ˫������βɾ
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
// ˫������ͷ��
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
// ˫������ͷɾ
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
// ˫���������
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
// ˫��������pos��ǰ����в���
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
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}