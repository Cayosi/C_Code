#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};


//打印链表
void NodePrint(struct ListNode* cur);

//创建新节点
struct ListNode* CreatNode(int x);

//头插
void SLNPushFront(struct ListNode** pphead, int x);