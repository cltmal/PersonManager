#pragma once
#include "PersonInfo.h"
#include <list>


class PersonController
{
private:
	list<PersonInfo>m_PersonInfo;
public:
	bool InsertPerson();
	bool DeletePerson();
	bool ModifyPerson();
	bool SearchPerson();
	bool PrintAllPerson();
	list<PersonInfo>* getPerson();
};

