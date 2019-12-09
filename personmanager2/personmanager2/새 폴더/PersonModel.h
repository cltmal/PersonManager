#pragma once
#include "PersonInfo.h"
#include <list>
using namespace std;
class PersonModel
{
public:
	bool LoadPersonInfoFile(list<PersonInfo>* personlist);
	bool SavePersonInfoFile(list<PersonInfo>* personlist);

};

