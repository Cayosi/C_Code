#pragma once

typedef int SLNDataType ;


typedef struct SListNode
{
	int val;
	struct SListNode* next;
}SLNode;
//��ӡ��ͷ������
void NodePrint(SLNode* cur);
//β��
void SLNPushBack(SLNode** pphead, SLNDataType x);
//ͷ��
void SLNPushFront(SLNode** pphead, SLNDataType x);

void SLTPopBack(SLNode** pphead);

//����
SLNode* SLFind(SLNode* phead, SLNDataType x);

void SListInsertAfter(SLNode* pos, SLNDataType x);

void SListEraseAfter(SLNode* pos);


void SLTErase(SLNode** pphead, SLNode* pos);
void SLTDestroy(SLNode** pphead);

void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x);