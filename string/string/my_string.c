#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>

size_t my_strlen(const char* str) {
	size_t length = 0;

	while (*str != '\0') {
		length++;
		str++;
	}

	return length;
}

char* my_strcpy(char* dest, const char* src) {
	char* dest_start = dest;

	// ����ַ����� src �� dest��ֱ������ \0 
	while ((*dest++ = *src++) != '\0') {
		// �� src �����ַ��� dest��ֱ������ \0
	}

	return dest_start;
}

char* my_strcat(char* dest, const char* src) {
	char* dest_start = dest;

	// �� dest ָ���ƶ��� dest �ַ�����ĩβ
	while (*dest != '\0') {
		dest++;
	}

	// ����ַ����� src �� dest��ֱ������ \0
	while (*src != '\0') {
		*dest++ = *src++;
	}

	// ��� \0 ��ȷ�� dest ��Ϊһ����Ч�ַ���
	*dest = '\0';

	return dest_start;
}

int main()
{

	char str[] = "hello world";
	size_t len = my_strlen(str);
	printf("str�ĳ��ȣ�%zd\n", len);
	char copy[30];
	my_strcpy(copy, str);
	printf("���Ƶ��ַ���copy��%s\n", copy);
	my_strcat(copy, str);
	printf("׷�ӹ�str��copy��%s\n",copy);
	return 0;
}