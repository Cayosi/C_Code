#pragma once
#include "List.h"

#define NAME_MAX 20
#define Number_MAX 20
#define AGE_MAX 3
#define GENDER_MAX 3
#define ADRESS_MAX 20
typedef struct contact
{
	char name[NAME_MAX];
	char gendex[GENDER_MAX];
	char age[AGE_MAX];
	char number[Number_MAX];
	char adress[ADRESS_MAX];
}contact;

#define Contacts SeList

