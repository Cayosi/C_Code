#pragma warning (disable: 4996)
#pragma warning (disable: 6031)
#pragma warning (disable: 4477)
#pragma warning (disable: 6054)
#define _CRT_SECURE_NO_WARNINGS


#include "Contacts.h"



//通讯录初始化
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

//打印联系人
void printContact(Contacts* contacts, size_t length)
{
	
		printf("序号：%zd { 姓名：%s 性别：%s 年龄：%s 电话：%s 地址：%s }\n",
			length,
			contacts->contact[length].name,
			contacts->contact[length].gender,
			contacts->contact[length].age,
			contacts->contact[length].phone,
			contacts->contact[length].address);
	

}
//打印通讯录
void printContacts(Contacts* contacts)
{
	for (size_t i = 0; i < contacts->len; i++)
	{
		printContact(contacts, i);
	}

}
//扩容
int flash(Contacts* contacts)
{
	if (contacts->size - contacts->len < 1)//扩容判断
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

//插入移动
void insertMove(Contacts* contacts,size_t length)
{
	for (size_t i = contacts->len; i >length; i--)
	{
		contacts->contact[i] = contacts->contact[i - 1];
	}
	
}
//删除移动
void popMove(Contacts* contacts, size_t length)
{
	for (size_t i = length; i < contacts->len -1; i++)
	{
		contacts->contact[i] = contacts->contact[i+1];
	}
}
//任意位置插入
void insert(Contacts* contacts)
{
	flash(contacts);
	size_t length = 0;
	printf("您想在哪个位置插入联系人？请输入->");
	scanf("%zu", &length);
	insertMove(contacts, length);
	printf("请按格式输入你要插入的联系人的信息\n");
	printf("名字 性别 年龄 电话 地址 ->");
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
	printf("请按格式输入你要插入的联系人的信息\n");
	printf("名字 性别 年龄 电话 地址 ->");
	scanf("%s %s %s %s %s",
		&contacts->contact[length].name,
		&contacts->contact[length].gender,
		&contacts->contact[length].age,
		&contacts->contact[length].phone,
		&contacts->contact[length].address
	);
		contacts->len++;
	
}
//头插
void headInser(Contacts* contacts)
{
	Insert(contacts, 0);
}


void endInser(Contacts* contacts)
{
	Insert(contacts, contacts->len);
	
}

//任意位置删除
void pop(Contacts* contacts)
{
	size_t length = 0;
	printf("请输入要删除的联系人的下序号->");
	scanf("%zu", &length);
	popMove(contacts, length);
	contacts->len--;
}
void Pop(Contacts* contacts,size_t length)
{
	popMove(contacts, length);
	contacts->len--;
}

//头删
void headPop(Contacts* contacts)
{
	Pop(contacts, 0);
}
//尾删
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
	printf("请输入要查找的联系人->");
	scanf("%s", name);
	int res = FindContactByName(contacts, name);
	if (res!= -1)
	{
		printf("找到了，联系人信息如下->:\n");
	}
	printf("通讯录中没有该联系人\n");
}

//按照名字删除
void popContactByName(Contacts* contacts)
{
	char name[NAME_MAX];
	printf("请输入要删除的联系人->");
	scanf("%s", name);
	for (size_t i = 0; i < contacts->len; i++)
	{
		if (strcmp(contacts->contact->name, name)) //名字相同就删除
		{
			Pop(contacts, i);
		}
	}
}


//修改相同名字联系人的信息
void setContactByName(Contacts* contacts)
{
	
		char name[NAME_MAX];
		printf("请输入你要修改的联系人->");
		scanf("%s", &name);
		int res = FindContactByName(contacts, name);
		if (res != -1)
		{
			printf("请按格式输入要修改的信息\n");
			printf("年龄 电话 地址->\n");
			scanf("%s %s %s", contacts->contact[res].age,
				contacts->contact[res].phone,
				contacts->contact[res].address);
			return;
		}
		else
		{
			printf("通讯录中没有该联系人,请重新输入\n");
		}
	

}


void sortContactsByName(Contacts* contacts)
{
	for (size_t i = contacts->len-1; i > 0; i--)//冒泡排序
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