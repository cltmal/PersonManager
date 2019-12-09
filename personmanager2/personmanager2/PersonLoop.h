#pragma once
#include "PersonView.h"
#include <iostream>

using namespace std;

class PersonLoop
{
private:
	PersonView m_PersonView;
public:
	PersonLoop();
	~PersonLoop();
	void RunLoop();

};

