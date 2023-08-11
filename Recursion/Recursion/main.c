#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>


int fb1(int len)
{
	if (len == 0 || len == 1 )
	{
		return len;
	}
	else
	{
		return fb1(len - 1) + fb1(len - 2);
	}
}


int fb2(int len)
{
	int res1 = 0;
	int res2 = 1;
	int res = 0;
	if (len == 0 || len == 1)
	{
		return len;
	}
	else 
	{
		for (int i = 2; i <= len; i++)
		{
			res = res1 + res2;
			res1 = res2;
			res2 = res;
		}
		return res;
	}

}

int nPower(int num,int flag)
{
	if (flag == 1)
	{
		return num;
	}
	else if (flag == 0)
	{
		return 1;
	}
	else
	{
		
		return  num * nPower(num,flag-1) ;
	}
	
}

int everySum(int num)
{
	if (num %10 == 0)
	{
		return num;
	}
	else
	{
		return everySum(num / 10) + (num % 10);
	}
	
}

int fact1(int res)
{
	if (res == 0 || res == 1)
	{
		return res;
	}
	return res * fact1(res - 1);
}
int fact2(int num)
{
	int res = 1;
	while (num > 1)
	{
		res *= (num--);
	}
	return res;
}

void printEvery(int num)
{
	
	if (num / 10 > 0)
	{
		printEvery(num / 10);

	}
		printf("%d ", num%10);
	

	
	
	
}
int main()
{
	
	printEvery(1234);
	
	return	0;
}