#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

void StatCharCount(char str[])
{
	int LetterCount = 0;
	int NumCount = 0;
	int OtherCount = 0;
	int length = strlen(str);
	printf("%d\n", length);
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
		{
			LetterCount++;
		}
		else if (str[i] >= 48 && str[i] <= 57 )
		{
			NumCount++;
		}
		else
		{
			OtherCount++;
		}
	}
	printf("字母字符出现次数>:%d\n数字字符出现次数>:%d\n其他字符出现次数>:%d\n", LetterCount, NumCount, OtherCount);
}



int main()
{
	char test[] = "123 fsdf sf {";
	StatCharCount(test);
	return 0;
}