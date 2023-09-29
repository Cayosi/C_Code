#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#define MAX(el1,el2) ((el1) > (el2) ? (el1) : (el2))

int main()
{

    int a = 2;
    int b = 3;
    int z = MAX(a++, b++);
    printf("a=%d b=%d z=%d", a, b, z);
    return 0;
}