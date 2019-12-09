#include "PersonInfo.h"


string PersonInfo::GetName()
{
	return m_Name;
}
PersonInfo& PersonInfo::SetName(string name)
{
	m_Name = name;
	return* this;
}
string PersonInfo::GetWorked()
{
	return m_Worked;
}
PersonInfo& PersonInfo::SetWorked(string worked)
{
	m_Worked = worked;
	return*this;
}
string PersonInfo::GetPosition()
{
	return m_Position;
}
PersonInfo& PersonInfo::SetPosition(string position)
{
	m_Position = position;
	return*this;
}
string PersonInfo::GetGroup()
{
	return m_Group;
}
PersonInfo& PersonInfo::SetGroup(string group)
{
	m_Group = group;
	return *this;
}
string PersonInfo::GetMoney()
{
	return m_Money;
}
PersonInfo& PersonInfo::SetMoney(string money)
{
	m_Money = money;
	return *this;
}
string PersonInfo::GetPhoneNumber()
{
	return m_PhoneNumber;
}
PersonInfo& PersonInfo::SetPhoneNumber(string phonenumber)
{
	m_PhoneNumber = phonenumber;
	return *this;
}