#include "List.h"


void printList(SeList list)
{
	for (size_t i = 0; i < list.len; i++)
	{
		printf("%d ", list.datas[i]);
	}
	printf("\n");
}

int main()
{
	SeList list;
	initList(&list);
	headInsert(&list, 1);
	headInsert(&list, 2);
	headInsert(&list, 3);
	headInsert(&list, 4);
	headInsert(&list, 5);
	headInsert(&list, 6);
	headInsert(&list, 7);
	insert(&list, 1, 0);
	printf("%d\n",list.len );
	printList(list);
	headPop(&list);
	printList(list);
	return 0;
}