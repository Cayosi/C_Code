#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)


#include <stdio.h>
#include <stdlib.h>

struct Stu
{
	char name[20];
	unsigned int age;
};

int stuCop(const void* el1, const void* el2)
{
	 struct Stu *tmp1 = el1;
	 struct Stu *tmp2 = el2;

	 return tmp1->age - tmp2->age;

}
int intCop(const void* el1, const void* el2)
{
	int* tmp1 = el1;
	int* tmp2 = el2;

	return *tmp1 - *tmp2;

}
int charCop(const void* el1, const void* el2)
{
	char* tmp1 = el1;
	char* tmp2 = el2;

	return *tmp1 - *tmp2;

}

int main()
{
	struct Stu stuArr[5] = { {"zhangsan1",25},{"zhangsan2",22},{"zhangsan3",26},{"zhangsan4",28},{"zhangsan5",20} };
	int numArr[5] = { 2,3,1,5,7 };
	char charArr[7] = { 'a','s','d','f','g','h','j' };
	qsort(numArr, 5, sizeof(numArr[0]), intCop);
	qsort(stuArr, 5, sizeof(stuArr[0]), stuCop);
	qsort(charArr, 7, sizeof(charArr[0]), charCop);
	for (size_t i = 0; i < 5; i++)
	{
		fprintf(stdout, "ÐÕÃû£º%s£¬ÄêÁä£º%d\n", stuArr[i].name,stuArr[i].age);
	}
	printf("numArr = { ");
	for (size_t i = 0; i < 5; i++)
	{
		printf("%d ", numArr[i]);
	}
	printf("}\n");
	printf("charArr = { ");
	for (size_t i = 0; i < 7; i++)
	{
		printf("'%c' ", charArr[i]);
	}
	printf("}\n");
	return 0;
}