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

	// 逐个字符复制 src 到 dest，直到遇到 \0 
	while ((*dest++ = *src++) != '\0') {
		// 从 src 复制字符到 dest，直到遇到 \0
	}

	return dest_start;
}

char* my_strcat(char* dest, const char* src) {
	char* dest_start = dest;

	// 将 dest 指针移动到 dest 字符串的末尾
	while (*dest != '\0') {
		dest++;
	}

	// 逐个字符复制 src 到 dest，直到遇到 \0
	while (*src != '\0') {
		*dest++ = *src++;
	}

	// 添加 \0 以确保 dest 成为一个有效字符串
	*dest = '\0';

	return dest_start;
}

int main()
{

	char str[] = "hello world";
	size_t len = my_strlen(str);
	printf("str的长度：%zd\n", len);
	char copy[30];
	my_strcpy(copy, str);
	printf("复制的字符串copy：%s\n", copy);
	my_strcat(copy, str);
	printf("追加过str的copy：%s\n",copy);
	return 0;
}