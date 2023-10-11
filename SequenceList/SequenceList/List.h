#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef  int DataList;
#define Capacity 4//默认初始化容量为四个元素
#define Mul 2 //默认扩容两倍
typedef struct SequenceList
{
    DataList* datas;
    unsigned int cap;
    unsigned int len;
}SeList;


int initList(SeList* list);//初始化顺序表



int dilatation(SeList* list);//扩容判断

void headInsert(SeList* list, DataList data);//头插函数

void endInsert(SeList* list, DataList data);


void endPop(SeList* list);

void headPop(SeList* list);

void insert(SeList* list, DataList data,size_t length);

void pop(SeList* list, size_t length);
