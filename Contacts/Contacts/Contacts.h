#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_MAX 20//名字最大值
#define GENDER_MAX 20//性别最大值
#define AGE_MAX 20//年龄最大值
#define PHONE_MAX 20//电话最大值
#define ADRESS_MAX 25//地址最大值
#define SIZE_INIT 5//通讯录初始能容纳的联系人个数
//初始要向内存申请的空间大小
#define CAP_INIT sizeof(Contacts)*SIZE_INIT
#define FLASH 2 //默认扩容倍数

typedef struct Contact//联系人
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	char age[AGE_MAX];
	char phone[PHONE_MAX];
	char address[ADRESS_MAX];
}Contact;



typedef struct Contacts//通讯录
{
	Contact* contact;
	size_t size;
	size_t len;
}Contacts;


int contactsInit(Contacts* contacts);//初始化通讯录
void printContacts(Contacts* contacts);//显示所有联系人信息
void printContact(Contacts* contacts, size_t length);//打印联系人
int flash(Contacts* contacts);//扩容
//插入移动

void insertMove(Contacts* contacts, size_t length);
//删除移动
void popMove(Contacts* contacts, size_t length);
//插入
void headInser(Contacts* contacts);
void endInser(Contacts* contacts);
void insert(Contacts* contacts);
void Insert(Contacts* contacts, size_t length);

//删除
void headPop(Contacts* contacts);
void endPop(Contacts* contacts);
void pop(Contacts* contacts);

void popContactByName(Contacts* contacts);//按名字删除

//查找

void findContactByName(Contacts* contacts);//按名字查找


//修改

void setContactByName(Contacts* contacts);//按照名字修改



//排序

void sortContactsByName(Contacts* contacts);//按照名字排序通讯录