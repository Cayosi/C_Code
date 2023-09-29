#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#include <stddef.h>
typedef struct Stu
{
	char name[20];
	int age;
}Stu;

struct S1
{
	char a;
	double b;
	int c;
};
struct S2
{
	char a1;
	struct S1 s1;
	double b2;
};
//int main()
//{
//	//offsetof 可以用来计算结构体成员相较于起始位置的偏移量
//	printf("%d ", offsetof(struct S1, a));
//	printf("%d ", offsetof(struct S1, b));
//	printf("%d\n", offsetof(struct S1, c));
//	printf("%d ", offsetof(struct S2, a1));
//	printf("%d ", offsetof(struct S2, s1));
//	printf("%d\n", offsetof(struct S2, b2));
//	/*  Stu stu = { "zhangsan", 20 };
//	  printf("%s\n", stu.name);
//	  printf("%d", (&stu)->age);*/
//	return 0;
//}