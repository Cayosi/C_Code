
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
	//	printf("小端\n");
	//}
	//else
	//{
	//	printf("大端\n");
	//}

	int i = 1;
	if (*((char*)(&i)) == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("小端\n");
	}

	return 0;
}