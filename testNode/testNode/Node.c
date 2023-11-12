
#include "Node.h"


//��ӡ����
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

//�����½ڵ�
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

//ͷ��
void SLNPushFront(struct ListNode** pphead, int x)
{
	assert(pphead);
	struct ListNode* newNode = CreatNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}