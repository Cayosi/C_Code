#pragma warning (disable: 4996)
#pragma warning (disable: 6031)
#pragma warning (disable: 4477)
#pragma warning (disable: 6054)
#define _CRT_SECURE_NO_WARNINGS


#include "Contacts.h"



//ͨѶ¼��ʼ��
int contactsInit(Contacts* contacts)
{
	Contact* temp = (Contact*)calloc(5,sizeof(Contact));
	if (temp != NULL)
	{
		contacts->contact = temp;
		temp = NULL;
		contacts->size = SIZE_INIT;
		contacts->len = 0;
		return 0;
	}
	else
	{
		perror("calloc");
		return 1;
	}
}

//��ӡ��ϵ��
void printContact(Contacts* contacts, size_t length)
{
	
		printf("��ţ�%zd { ������%s �Ա�%s ���䣺%s �绰��%s ��ַ��%s }\n",
			length,
			contacts->contact[length].name,
			contacts->contact[length].gender,
			contacts->contact[length].age,
			contacts->contact[length].phone,
			contacts->contact[length].address);
	

}
//��ӡͨѶ¼
void printContacts(Contacts* contacts)
{
	for (size_t i = 0; i < contacts->len; i++)
	{
		printContact(contacts, i);
	}

}
//����
int flash(Contacts* contacts)
{
	if (contacts->size - contacts->len < 1)//�����ж�
	{
		Contact* temp = realloc(contacts->contact, sizeof(Contact) * (contacts->size) * FLASH);
		if (temp != NULL)
		{
			contacts->contact = temp;
			temp = NULL;
			return 0;
		}
		else
		{
			perror("realloc");
			return 1;
		}

	}
	

	return 0;

}

//�����ƶ�
void insertMove(Contacts* contacts,size_t length)
{
	for (size_t i = contacts->len; i >length; i--)
	{
		contacts->contact[i] = contacts->contact[i - 1];
	}
	
}
//ɾ���ƶ�
void popMove(Contacts* contacts, size_t length)
{
	for (size_t i = length; i < contacts->len -1; i++)
	{
		contacts->contact[i] = contacts->contact[i+1];
	}
}
//����λ�ò���
void insert(Contacts* contacts)
{
	flash(contacts);
	size_t length = 0;
	printf("�������ĸ�λ�ò�����ϵ�ˣ�������->");
	scanf("%zu", &length);
	insertMove(contacts, length);
	printf("�밴��ʽ������Ҫ�������ϵ�˵���Ϣ\n");
	printf("���� �Ա� ���� �绰 ��ַ ->");
	scanf("%s %s %s %s %s",
		&contacts->contact[length].name,
		&contacts->contact[length].gender,
		&contacts->contact[length].age,
		&contacts->contact[length].phone,
		&contacts->contact[length].address
	);
	contacts->len++;

}
void Insert(Contacts* contacts, size_t length)
{
	flash(contacts);
	insertMove(contacts,length);
	printf("�밴��ʽ������Ҫ�������ϵ�˵���Ϣ\n");
	printf("���� �Ա� ���� �绰 ��ַ ->");
	scanf("%s %s %s %s %s",
		&contacts->contact[length].name,
		&contacts->contact[length].gender,
		&contacts->contact[length].age,
		&contacts->contact[length].phone,
		&contacts->contact[length].address
	);
		contacts->len++;
	
}
//ͷ��
void headInser(Contacts* contacts)
{
	Insert(contacts, 0);
}


void endInser(Contacts* contacts)
{
	Insert(contacts, contacts->len);
	
}

//����λ��ɾ��
void pop(Contacts* contacts)
{
	size_t length = 0;
	printf("������Ҫɾ������ϵ�˵������->");
	scanf("%zu", &length);
	popMove(contacts, length);
	contacts->len--;
}
void Pop(Contacts* contacts,size_t length)
{
	popMove(contacts, length);
	contacts->len--;
}

//ͷɾ
void headPop(Contacts* contacts)
{
	Pop(contacts, 0);
}
//βɾ
void endPop(Contacts* contacts)
{
	Pop(contacts, contacts->len - 1);
}

int FindContactByName(Contacts* contacts, char name[NAME_MAX])
{
	for (size_t i = 0; i < contacts->len; i++)
	{
		if (strcmp(name, contacts->contact[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}


void findContactByName(Contacts* contacts)
{
	char name[NAME_MAX];
	printf("������Ҫ���ҵ���ϵ��->");
	scanf("%s", name);
	int res = FindContactByName(contacts, name);
	if (res!= -1)
	{
		printf("�ҵ��ˣ���ϵ����Ϣ����->:\n");
	}
	printf("ͨѶ¼��û�и���ϵ��\n");
}

//��������ɾ��
void popContactByName(Contacts* contacts)
{
	char name[NAME_MAX];
	printf("������Ҫɾ������ϵ��->");
	scanf("%s", name);
	for (size_t i = 0; i < contacts->len; i++)
	{
		if (strcmp(contacts->contact->name, name)) //������ͬ��ɾ��
		{
			Pop(contacts, i);
		}
	}
}


//�޸���ͬ������ϵ�˵���Ϣ
void setContactByName(Contacts* contacts)
{
	
		char name[NAME_MAX];
		printf("��������Ҫ�޸ĵ���ϵ��->");
		scanf("%s", &name);
		int res = FindContactByName(contacts, name);
		if (res != -1)
		{
			printf("�밴��ʽ����Ҫ�޸ĵ���Ϣ\n");
			printf("���� �绰 ��ַ->\n");
			scanf("%s %s %s", contacts->contact[res].age,
				contacts->contact[res].phone,
				contacts->contact[res].address);
			return;
		}
		else
		{
			printf("ͨѶ¼��û�и���ϵ��,����������\n");
		}
	

}


void sortContactsByName(Contacts* contacts)
{
	for (size_t i = contacts->len-1; i > 0; i--)//ð������
	{
		for (size_t j = 0; j < i; j++)
		{
			if (strcmp(contacts->contact[j].name, contacts->contact[j + 1].name)>0)
			{
				Contact tmp = contacts->contact[j];
				contacts->contact[j] = contacts->contact[j + 1];
				contacts->contact[j + 1] = tmp;
			}
		}

	}
}