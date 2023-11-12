#pragma once

typedef int SLNDataType ;


typedef struct SListNode
{
	int val;
	struct SListNode* next;
}SLNode;
//打印无头单链表
void NodePrint(SLNode* cur);
//尾插
void SLNPushBack(SLNode** pphead, SLNDataType x);
//头插
void SLNPushFront(SLNode** pphead, SLNDataType x);

void SLTPopBack(SLNode** pphead);

//查找
SLNode* SLFind(SLNode* phead, SLNDataType x);

void SListInsertAfter(SLNode* pos, SLNDataType x);

void SListEraseAfter(SLNode* pos);


void SLTErase(SLNode** pphead, SLNode* pos);
void SLTDestroy(SLNode** pphead);

void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x);