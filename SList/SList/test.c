#include "SeqList.h"
#include "SListNode.h"
void test1()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListInsert(&seq, 0, 1);
	SeqListInsert(&seq, 1, 2);
	SeqListInsert(&seq, 2, 3);
	SeqListInsert(&seq, 3, 4);
	SeqListPrint(&seq);
	SeqListPopFront(&seq);
	SeqListPrint(&seq);
	SeqListPopBack(&seq);
	SeqListPrint(&seq);
	SeqListPushFront(&seq, 1);
	SeqListPrint(&seq);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 4);
	SeqListPrint(&seq);
	//SeqListErase(&seq, 0);
	//SeqListPrint(&seq);
	//int res1 = SeqListFind(&seq, 1);
	//printf("%d ", res1);	
	//int res2 = SeqListFind(&seq, 2);
	//printf("%d ", res2);	
	//int res3 = SeqListFind(&seq, 3);
	//printf("%d ", res3);	
	//int res4 = SeqListFind(&seq, 4);
	//printf("%d ", res4);
	int res5 = SeqListFind(&seq, 4);
	printf("%d ", res5);
}
void test2()
{
	SeqList seq ;
	SeqList* test = &seq;
	test = NULL;
	SeqListInit(test);
}
void test3()
{
	SLNode* node = NULL;
	SLNPushBack(&node, 2);
	SLNPushBack(&node, 3);
	SLNPushBack(&node, 4);
	SLNode* res = SLFind(node, 4);
	SListInsertAfter(res, 5);
	NodePrint(node);
	res = SLFind(node, 2);
	SLTErase(&node,res);
	NodePrint(node);
	SLTDestroy(&node);
	NodePrint(node);
}

SLNode* removeElements(SLNode* head, int val)
{
	if (head == NULL)
	{
		return head;
	}
	SLNode* cur = head;
	while (cur->next != NULL)
	{
		if (head->val == val)
		{
			SLNode* tmp = head->next;
			free(head);
			head = tmp;
			cur = head;
			tmp = NULL;
			continue;
		}

			if ( cur->next->val == val)
			{
				SLNode* tmp = cur->next;
				cur->next = tmp->next;
				free(tmp);
				tmp = NULL;
				continue;
				
			}
			if (cur->next != NULL)
			{
				cur = cur->next;
			}
			
	}
	if (head->val == val)
	{
		free(head);
		head = NULL;
	}
	return head;
}

SLNode* middleNode(SLNode* head)
{
	SLNode* cur = head;
	SLNode* half = head;
	while (cur!=NULL && cur->next != NULL)
	{
		half = half->next;
		cur = cur->next->next;
		
	}
	return half;
}
SLNode* FindKthToTail(SLNode* pListHead, int k)
{
	SLNode* n1 = pListHead;
	SLNode* n2 = pListHead;
	while (k--)
	{
		if (n1 == NULL)
		{
			return NULL;
		}
		n1 = n1->next;
	}
	
	while (n1!=NULL)
	{
		n1 = n1->next;
		n2 = n2->next;
	}
	return n2;
}
void test4()
{
	SLNode* node = NULL;
	SLNPushFront(&node, 1);
	SLNPushFront(&node, 2);
	SLNPushFront(&node, 3);
	SLNPushFront(&node, 2);
	SLNPushFront(&node, 1);
	//SLNPushFront(&node, 7);
	//SLNPushFront(&node, 7);
	//SLNPushFront(&node, 7);
	node = removeElements(node, 2);
	NodePrint(node);
}
void test5()
{
	SLNode* node = NULL;
	SLNPushFront(&node, 1);
	SLNPushFront(&node, 2);
	SLNPushFront(&node, 3);
	SLNPushFront(&node, 4);
	SLNPushFront(&node, 2);
	SLNPushFront(&node, 1);
	SLNode* res = middleNode(node);
	printf("%d\n", res->val);
}
void test6()
{
	SLNode* node = NULL;
	SLNPushFront(&node, 1);
	SLNPushFront(&node, 2);
	SLNPushFront(&node, 3);
	SLNPushFront(&node, 4);
	SLNPushFront(&node, 5);
	SLNPushFront(&node, 6);
	SLNode* res = FindKthToTail(node, 6);
	NodePrint(res);
}


void removeElement(SLNode** pphead,SLNDataType val)
{
	SLNode* cur = *pphead;
	SLNode* prev = NULL;
	while (cur)
	{
		if (cur->val == val)
		{
			SLNode* tmp = cur->next;
			free(cur);
			if (prev)
			{
				cur = tmp;
				prev->next = cur;
			}
			else
			{
				*pphead = tmp;
				cur = *pphead;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
void test7()
{
	SLNode* node = NULL;
	SLNPushFront(&node, 1);
	SLNPushFront(&node, 2);
	SLNPushFront(&node, 3);
	SLNPushFront(&node, 4);
	SLNPushFront(&node, 2);
	SLNPushFront(&node, 1);
	removeElement(&node, 1);
	NodePrint(node);
}
int main()
{

	test7();
}