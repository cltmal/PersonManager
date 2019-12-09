#pragma once
#include "PersonController.h"
class PersonView
{
private:
	PersonController m_PersonController;
public:
	PersonView();
	~PersonView();
	PersonController* GetPersonController();
	void show();
	void showMenu();
	int GetNumMenu();
	bool CommandMenu(int num);
	static void ClrScr();
	static void DivideLine(string strCh = "=", int len = 20);




};

