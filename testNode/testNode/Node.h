#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};


//��ӡ����
void NodePrint(struct ListNode* cur);

//�����½ڵ�
struct ListNode* CreatNode(int x);

//ͷ��
void SLNPushFront(struct ListNode** pphead, int x);