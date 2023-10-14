#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NAME_MAX 20
#define Number_MAX 20
#define AGE_MAX 3
#define GENDER_MAX 3
#define ADRESS_MAX 20


typedef  contact DataList;
typedef struct contact
{
	char name[NAME_MAX];
	char gendex[GENDER_MAX];
	char age[AGE_MAX];
	char number[Number_MAX];
	char adress[ADRESS_MAX];
}contact;

#define Capacity 4//Ĭ�ϳ�ʼ������Ϊ�ĸ�Ԫ��
#define Mul 2 //Ĭ����������
typedef struct SequenceList
{
    DataList* datas;
    unsigned int cap;
    unsigned int len;
}SeList;

#define Contacts SeList


int initList(SeList* list);//��ʼ��˳���



int dilatation(SeList* list);//�����ж�

void headInsert(SeList* list, DataList data);//ͷ�庯��

void endInsert(SeList* list, DataList data);


void endPop(SeList* list);

void headPop(SeList* list);

void insert(SeList* list, DataList data,size_t length);

void pop(SeList* list, size_t length);
