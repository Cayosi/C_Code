#include  "Heap.h"

void InitHP(HP* php)
{
	php->size = 0;
	php->capacity = 0;
	php->data = NULL;
}

void swap(HPData* a, HPData* b)
{
	HPData tmp = *a;
	*a = *b;
	*b = tmp;
}
//儿比爹小儿当爹
void UpSet(HPData* data, int son)
{
	int parent = (son - 1) / 2;

	while (son > 0)
	{
		if (data[son] < data[parent])
		{
			swap(&data[son], &data[parent]);
			//各找各的爹
			son = (son - 1) / 2;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}

	}
}
void DestroyHP(HP* php)
{
	free(php->data);
	php->data = NULL;
	php->size = 0;
	php->capacity = 0;
}

void HeapPush(HP* php, HPData x)
{

	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity != 0 ? php->capacity * 2 : 4;
		HPData* tmp = realloc(php->data, newCapacity * sizeof(sizeof(HPData)));
		if (tmp)
		{
			php->data = tmp;
			php->capacity = newCapacity;
		}
		else
		{
			perror("realloc");
			exit(-1);
		}
	}

	php->data[php->size] = x;
	UpSet(php->data, php->size);
	php->size++;
}




void printHP(HP hp)
{
	for (size_t i = 0; i < hp.size; i++)
	{
		printf("%d ", hp.data[i]);
	}
	printf("\n");
}



void DownSet(HPData* data, int size,int pos)
{
	
	while (pos*2+1 <= size)
	{
		int min = pos * 2 + 1;
		if (min+1<=size && data[min]>data[min+1])
		{
			min = min + 1;
		}
		HPData  tmp = data[min];
		data[min] = data[pos];
		data[pos] = tmp;
		pos = min;
	}
}
void HeapPop(HP* php)
{

	php->data[0] = php->data[--php->size];//尾到头像下调整
	DownSet(php->data,php->size,0);
}