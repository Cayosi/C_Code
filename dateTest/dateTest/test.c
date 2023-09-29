#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>


int leapYear(size_t year)
{
	if ((0 == year % 4 && year % 100 != 0) || (0 == year % 400))
	{
		return 1;
	}
	return 0;
}



int main()
{
	size_t Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	int year = 0;
	int month = 0;
	scanf("%d %d", &year, &month);
	if (leapYear(year) && month == 2)
	{
		printf("29");
	}
	else
	{
		printf("%zd", Month[month]);
	}
	return 0;
}
