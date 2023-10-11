#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef  int DataList;
#define Capacity 4//Ĭ�ϳ�ʼ������Ϊ�ĸ�Ԫ��
#define Mul 2 //Ĭ����������
typedef struct SequenceList
{
    DataList* datas;
    unsigned int cap;
    unsigned int len;
}SeList;


int initList(SeList* list);//��ʼ��˳���



int dilatation(SeList* list);//�����ж�

void headInsert(SeList* list, DataList data);//ͷ�庯��

void endInsert(SeList* list, DataList data);


void endPop(SeList* list);

void headPop(SeList* list);

void insert(SeList* list, DataList data,size_t length);

void pop(SeList* list, size_t length);
