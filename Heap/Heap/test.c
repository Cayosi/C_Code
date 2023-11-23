#include "Heap.h"



void pushTest()
{
	HP php;
	InitHP(&php);
	HeapPush(&php, 4);
	HeapPush(&php, 3);
	HeapPush(&php, 2);
	HeapPush(&php, 1);
	HeapPush(&php, 2);
	HeapPush(&php, 10);
	HeapPush(&php, 20);
	HeapPush(&php, 15);
	HeapPush(&php, 11);
	HeapPush(&php, 12);
	HeapPush(&php, 12);
	printHP(php);
	HeapPop(&php);
	printHP(php);
}

int main()
{

	pushTest();



	return 0;
}