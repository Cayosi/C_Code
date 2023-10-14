#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_MAX 20//�������ֵ
#define GENDER_MAX 20//�Ա����ֵ
#define AGE_MAX 20//�������ֵ
#define PHONE_MAX 20//�绰���ֵ
#define ADRESS_MAX 25//��ַ���ֵ
#define SIZE_INIT 5//ͨѶ¼��ʼ�����ɵ���ϵ�˸���
//��ʼҪ���ڴ�����Ŀռ��С
#define CAP_INIT sizeof(Contacts)*SIZE_INIT
#define FLASH 2 //Ĭ�����ݱ���

typedef struct Contact//��ϵ��
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	char age[AGE_MAX];
	char phone[PHONE_MAX];
	char address[ADRESS_MAX];
}Contact;



typedef struct Contacts//ͨѶ¼
{
	Contact* contact;
	size_t size;
	size_t len;
}Contacts;


int contactsInit(Contacts* contacts);//��ʼ��ͨѶ¼
void printContacts(Contacts* contacts);//��ʾ������ϵ����Ϣ
void printContact(Contacts* contacts, size_t length);//��ӡ��ϵ��
int flash(Contacts* contacts);//����
//�����ƶ�

void insertMove(Contacts* contacts, size_t length);
//ɾ���ƶ�
void popMove(Contacts* contacts, size_t length);
//����
void headInser(Contacts* contacts);
void endInser(Contacts* contacts);
void insert(Contacts* contacts);
void Insert(Contacts* contacts, size_t length);

//ɾ��
void headPop(Contacts* contacts);
void endPop(Contacts* contacts);
void pop(Contacts* contacts);

void popContactByName(Contacts* contacts);//������ɾ��

//����

void findContactByName(Contacts* contacts);//�����ֲ���


//�޸�

void setContactByName(Contacts* contacts);//���������޸�



//����

void sortContactsByName(Contacts* contacts);//������������ͨѶ¼