
#include "complexNode.h"

#include <stdio.h>


void BackTest()
{
	ListNode* node = ListCreate();
	ListPushBack(node, 1);
	ListPushBack(node, 2);
	ListPushBack(node, 3);
	ListPushBack(node, 4);

	ListPrint(node);
	ListPopBack(node);
	ListPrint(node);
}

void FrontTest()
{
	ListNode* node = ListCreate();
	ListPushFront(node,1);
	ListPushFront(node,2);
	ListPushFront(node,3);
	ListPushFront(node,4);
	ListPrint(node);
	ListNode* pos = ListFind(node, 2);
	ListInsert(pos, 9);
	ListPrint(node);
	//ListPopFront(node);
	//if (node->_next == node)
	//{
	//	printf("sucess");
	//}
	//ListPrint(node);
}

void targetPrint(ListNode* target)
{
	if (target)
	{
		printf("%d\n", target->_data);
	}
	else
	{
		printf("NULL");
	}
}
void FindTest()
{


	ListNode* node = ListCreate();
	ListPushBack(node, 1);
	ListPushBack(node, 2);
	ListPushBack(node, 3);
	ListPushBack(node, 4);
ListNode* target = 	ListFind(node, 1);
targetPrint(target);
 target = 	ListFind(node, 2);
targetPrint(target);
 target = 	ListFind(node, 3);
targetPrint(target);
 target = 	ListFind(node, 4);
targetPrint(target);
 target = 	ListFind(node, 5);
targetPrint(target);
}

void test()
{
	ListNode* node = ListCreate();
	ListPushFront(node, 1);
	ListPushFront(node, 2);
	ListPushFront(node, 3);
	ListPushFront(node, 4);
	ListPrint(node);
	ListNode* pos = ListFind(node, 2);
	ListInsert(pos, 9);
	ListPrint(node);
	 pos = ListFind(node, 9);
	ListErase(pos);
	ListPrint(node);
}
int main()
{
	//test();
	//FrontTest();
	//FindTest();
	ListNode* node = ListCreate();
	ListPushBack(node, 1);
	ListPushBack(node, 2);
	ListPushBack(node, 3);
	ListPushBack(node, 4);
	ListPrint(node);
	ListDestory(&node);
	if (node == NULL)
	{
		printf("sucess");
	}
	return 0;
}