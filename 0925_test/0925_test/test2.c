#include <stdio.h>

#pragma pack(1) // ����Ĭ�϶�����Ϊ1
#define MAX(el1,el2) ((el1) > (el2) ? (el1) : (el2))
struct S1
{
	char a;
	char b;
	int c;
};

#pragma pack() //�ظ�Ĭ�϶�����

