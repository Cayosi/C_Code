
#include "Node.h"


//打印链表
void NodePrint(struct ListNode* cur)
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
struct ListNode* CreatNode(int x)
{
	struct ListNode* newNode = malloc(sizeof(struct ListNode));
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
void SLNPushFront(struct ListNode** pphead, int x)
{
	assert(pphead);
	struct ListNode* newNode = CreatNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}