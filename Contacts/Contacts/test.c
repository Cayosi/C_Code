
#include "Contacts.h"




void headTest()

{
	Contacts contacts;
	contactsInit(&contacts);
	headInser(&contacts);
	printContacts(&contacts);
}



int main()
{
	//Contacts contacts;
	//int res = contactsInit(&contacts);
	//printf("%d\n", res);
	//res = flash(&contacts);
	//printf("%d\n", res);
	Contacts contacts;
	contactsInit(&contacts);
	for (size_t i = 0; i < 5; i++)
	{
		Insert(&contacts, i);
	}
	setContactByName(&contacts);
	printContacts(&contacts);
	sortContactsByName(&contacts);
	printContacts(&contacts);
	
	return 0;

}