
#include <stdio.h>



int sys_judg()
{
	union 
	{
		int i;
		char c;
	}u;
	u.i = 1;
	return u.c;
}

int main()
{
	//if (sys_judg)
	//{
	//	printf("С��\n");
	//}
	//else
	//{
	//	printf("���\n");
	//}

	int i = 1;
	if (*((char*)(&i)) == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("С��\n");
	}

	return 0;
}