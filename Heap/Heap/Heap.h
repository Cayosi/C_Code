#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPData;
typedef struct Heap
{
	HPData* data;
	int size;
	int capacity;
}HP;

void InitHP(HP* php);
void DestroyHP(HP* php);

void HeapPush(HP* php,HPData x);

void HeapPop(HP* php);