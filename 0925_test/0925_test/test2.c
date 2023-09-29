#include <stdio.h>

#pragma pack(1) // 设置默认对齐数为1
#define MAX(el1,el2) ((el1) > (el2) ? (el1) : (el2))
struct S1
{
	char a;
	char b;
	int c;
};

#pragma pack() //回复默认对齐数

