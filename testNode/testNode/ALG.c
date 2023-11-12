
#include "Node.h"
#include <stdbool.h>


//ɾ�������нڵ��val �� val��ͬ�ڵ�
struct ListNode* removeElements1(struct ListNode* head, int val)
{
	struct ListNode* cur = head;
	struct ListNode* tail = NULL;
	while (cur)
	{
		if (cur->val == val)
		{
			struct ListNode* tmp = cur->next;
			free(cur);
			if (tail)
			{
				cur = tmp;
				tail->next = cur;
			}
			else
			{
				head = cur = tmp;
			}
		}
		else
		{
			tail = cur;
			cur = cur->next;
		}
	}
	return head;
}

//�ڱ�λ
struct ListNode* removeElements2(struct ListNode* head, int val)
{
	struct ListNode* newNode = NULL;
	struct ListNode* tail = NULL;
	newNode = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* cur = head;
	if (newNode)
	{
		while (cur)
		{
			if (cur->val == val)
			{
				struct ListNode* tmp = cur->next;
				free(cur);
				cur = tmp;
				tail->next = cur;
			}
			else
			{
				tail->next = cur;
				tail = tail->next;
				cur = cur->next;
			}
		}
		struct ListNode* tmp = newNode;
		newNode = newNode->next;
		free(tmp);
		return newNode;
	}
	perror("malloc");
	return head;

}

//���������е�����k���ڵ�
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	struct ListNode* n1 = pListHead;
	struct ListNode* n2 = pListHead;
	while (k--)
	{
		if (n1 == NULL)
		{
			return NULL;
		}
		n1 = n1->next;
	}

	while (n1 != NULL)
	{
		n1 = n1->next;
		n2 = n2->next;
	}
	return n2;
}
//����ָ�
//����һ�����ͷָ�� ListNode* pHead����һ��ֵx����дһ�δ��뽫����С��x�Ľ������������֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣

struct ListNode* partition(struct ListNode* head, int x)
{
	if (!head)
		return head;
	struct ListNode* n1 = NULL;//val<x
	struct ListNode* n2 = NULL;//val>x
	struct ListNode* tail1 = NULL;//n1��β
	struct ListNode* tail2 = NULL;//n2��β
	struct ListNode* cur = head;//����
	while (cur)
	{
		if (cur->val < x)
		{
			if (n1)
			{
				tail1->next = cur;
				tail1 = tail1->next;
			}
			else
			{
				n1 = tail1 = cur;
			}
		}
		else
		{
			if (n2)
			{
				tail2->next = cur;
				tail2 = tail2->next;
			}
			else
			{
				n2 = tail2 = cur;
			}
		}
		cur = cur->next;
	}
	if (tail1 && tail2)//���������нڵ�
	{
		tail1->next = n2;
		tail2->next = NULL;
	}
	if (n1)
		return n1;
	return n2;//n1Ϊ��
}

//�ϲ�������������
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	//����һ��Ϊ�շ�����һ��
	if (list1 == NULL || list2 == NULL)
	{
		return  (list1 == NULL ? list2 : list1);
	}
	struct ListNode* newNode = NULL;
	struct ListNode* tail = NULL;//newNode��β
	struct ListNode* cur1 = list1;
	struct ListNode* cur2 = list2;
	//˭С˭��newNode��
	while (cur1 && cur2)
	{
		if (cur1->val < cur2->val)
		{
			if (!newNode)
			{
				tail = newNode = cur1;
			}
			else
			{
				tail->next = cur1;
				if (tail->next != NULL);
				tail = tail->next;
			}
			cur1 = cur1->next;
		}
		else
		{
			if (!newNode)
			{
				tail = newNode = cur2;
			}
			else
			{
				tail->next = cur2;
				if (tail->next != NULL);
				tail = tail->next;
			}
			cur2 = cur2->next;
		}
	}
	//cur1 �� cur2û����
	while (cur1)
	{
		tail->next = cur1;
		tail = tail->next;
		cur1 = cur1->next;
	}
	while (cur2)
	{
		tail->next = cur2;
		tail = tail->next;
		cur2 = cur2->next;
	}

	return newNode;
}
//ɾ�������е�����n���ڵ�
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
	struct ListNode newNode = { 0,NULL };
	if (head->next)
	{
		struct ListNode* n1 = head;
		struct ListNode* n2 = head;
		while (n1->next && n)
		{
			n1 = n1->next;
			n--;
		}
		if (n)
		{
			newNode.next = n2->next;
			free(n2);
		}
		else
		{
			newNode.next = n2;
			while (n1->next)
			{
				n1 = n1->next;
				n2 = n2->next;
			}
			struct ListNode* pos = n2->next;
			n2->next = pos->next;
		}

		return newNode.next;
	}
	else if (n == 1)
	{
		free(head);
		return NULL;
	}
	return head;
}



//��ת����
//1.�ı�nextָ��ָ��
//2.ͷ��
struct ListNode* reverseList1(struct ListNode* head)
{
	if (!head)
		return head;
	struct ListNode* n1 = NULL;
	struct ListNode* n2 = head;
	struct ListNode* n3 = head->next;

	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}
	return n1;
}

struct ListNode* reverseList2(struct ListNode* head)
{
	if (!head)
		return head;

	struct ListNode* newNode = NULL;
	struct ListNode* cur = head;
	struct ListNode* tmp = NULL;//��¼��һ��
	while (cur)
	{
		tmp = cur->next;
		cur->next = newNode;
		newNode = cur;//�ı�ͷ
		cur = tmp;
	}
	return newNode;
}
//�ཻ����
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	if (headA == headB)
		return headA;
	struct ListNode* curA, * curB;
	curA = headA;
	curB = headB;
	int flagA = 0;
	int flagB = 0;
	//1.��β�ڵ㣬��¼����
	//2.��¼����
	while (curA->next)
	{
		curA = curA->next;
		flagA++;
	}
	while (curB->next)
	{
		curB = curB->next;
		flagB++;
	}
	if (curA == curB)//�ཻ
	{
		struct ListNode* longNode = NULL;
		struct ListNode* shortNode = NULL;
		if (flagA > flagB)
		{
			longNode = headA;
			shortNode = headB;
		}
		else
		{
			longNode = headB;
			shortNode = headA;
		}

		int gap = abs(flagA - flagB);

		while (gap--)//�������߲�ಽ
		{
			longNode = longNode->next;
		}
		while (1)//һ�������
		{
			if (longNode == shortNode)
			{
				return longNode;
			}
			if (longNode && shortNode)
			{
				longNode = longNode->next;
				shortNode = shortNode->next;
			}

		}
	}
	return NULL;//���ཻ
}

//�ж��Ƿ��л�

bool hasCycle(struct ListNode* head)
{

	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast && fast->next)//�ཻ
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return true;
		}
	}
	return false;
}
//�����뻷�ڵ�
struct ListNode* detectCycle(struct ListNode* head)
{
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	struct ListNode* pos = head;

	while (fast && fast->next)//�ཻ
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			break;
		}
	}
	if (!fast || !fast->next)
		return NULL;
	while (pos != fast)
	{
		pos = pos->next;
		fast = fast->next;
	}
	return pos;
}


typedef struct RNode {
	int val;
	struct RNode* next;
	struct RNode* random;
	
}RNode;
//�������ĸ���
struct RNode* copyRandomList(struct RNode* head) 
{
	for (RNode* node = head; node !=NULL ; node=node->next->next)
	{
		RNode* newNode = malloc(sizeof(RNode));
		newNode->val = node->val;
		newNode->next = node->next;
		node->next = newNode;
	}
	RNode* copy = head->next;
	RNode* curC = head->next;
	for (RNode* node = head; node!=NULL ; node=node->next->next)
	{
		RNode* newNode = head->next;
		curC->random = node->random != NULL ? node->random->next : NULL;
		curC = copy->next->next;
	}
	for (RNode* node = head;node!=NULL;node=node->next)
	{
		node->next = node->next->next;
		curC->next = curC->next != NULL ? curC->next->next : NULL;
	}
	return copy;
}

//������Ľṹ�ж�

bool chkPalindrome(struct ListNode* head)
{
	struct ListNode* cur = head;
	struct ListNode* mid = head;
	
	while (cur)
	{
		mid = mid->next;
		if (!cur->next)
		{
			break;
		}
		cur = cur->next->next;
		
	}
	struct ListNode* rhead = NULL;
	struct ListNode* tmp = NULL;
	cur = mid;
	while (cur)
	{
		tmp = cur->next;
		if (!rhead)
		{
			rhead = cur;
			rhead->next = NULL;
		}
		else
		{
			cur->next = rhead;
			rhead = cur;
		}
		cur = tmp;
	}
	cur = head;
	while (rhead)
	{
		if (cur->val != rhead->val)
		{
			break;
		}
		cur = cur->next;
		rhead = rhead->next;
	}

	if (rhead)
	{
		return false;
	}
	return true;
}


int main()
{
	struct ListNode* node = NULL;

	
	SLNPushFront(&node, 1);
	SLNPushFront(&node, 2);
	SLNPushFront(&node, 2);
	SLNPushFront(&node, 1);
	//SLNPushFront(&node, 2);
	//SLNPushFront(&node, 2);
	//SLNPushFront(&node, 1);
	//SLNPushFront(&node, 1);
	//partition(node, 3);
	if (chkPalindrome(node))
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
	//NodePrint(node);
	//node = removeElements2(node, 1);
	//node = removeElements2(node, 2);
	//node = partition(node, 3);
	//node = removeNthFromEnd(node, 1);
	//node = reverseList2(node);
	//NodePrint(node);
}