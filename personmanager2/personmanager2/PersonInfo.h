#pragma once
#include <iostream>

using namespace std;
class PersonInfo
{
private:
	string m_Name;
	string m_Worked;
	string m_Position;
	string m_Group;
	string m_Money;
	string m_PhoneNumber;
public:
	string GetName();
	PersonInfo& SetName(string name);
	string GetWorked();
	PersonInfo& SetWorked(string worked);
	string GetPosition();
	PersonInfo& SetPosition(string position);
	string GetGroup();
	PersonInfo& SetGroup(string group);
	string GetMoney();
	PersonInfo& SetMoney(string money);
	string GetPhoneNumber();
	PersonInfo& SetPhoneNumber(string phonenumber);
};

