#include "PersonController.h"
#include "PersonView.h"
bool PersonController::InsertPerson()
{
	string Name;
	string Position;
	string Group;
	string Money;
	string PhoneNumber;

	cout << "�̸� �Է�: " ;
	cin >> Name;
	cout << "���� �Է�: ";
	cin >> Position;
	cout << "�μ� �Է�: ";
	cin >> Group;
	cout << "���� �Է�: ";
	cin >> Money;
	cout << "��ȭ��ȣ �Է�: ";
	cin >> PhoneNumber;

	PersonInfo pi;

	pi.SetName(Name)
		.SetPosition(Position)
		.SetGroup(Group)
		.SetMoney(Money)
		.SetPhoneNumber(PhoneNumber)
		.SetWorked("������");

	m_PersonInfo.push_back(pi);
	return true;

}
bool PersonController::DeletePerson()
{
	string Name;
	cout << "�̸� �Է�: ";
	cin >> Name;

	list<PersonInfo>::iterator it = m_PersonInfo.begin();
	while (it != m_PersonInfo.end())
	{
		if (Name == it->GetName())
		{
			m_PersonInfo.erase(it);
			break;
		}
		it++;
	}
	return true;
}
bool PersonController::ModifyPerson()
{
	string Name;
	cout << "�̸� �Է�: ";
	cin >> Name;

	list<PersonInfo>::iterator it = m_PersonInfo.begin();
	while (it != m_PersonInfo.end())
	{
		if (Name == it->GetName())
		{
			int num;
			cout <<"<1.���� 2.�μ� 3.���� 4.�������� 5.��ȭ��ȣ>"<<endl;
			cin >> num;
			string Position;
			if (num == 1)
			{
				cout << "���� �Է�: ";
				cin >> Position;
				it->SetPosition(Position);
			}
			string	Group;
			if (num == 2)
			{
				cout << "�μ� �Է�: ";
				cin >> Group;
				it->SetGroup(Group);
			}
			string Money;
			if (num == 3)
			{
				cout << "���� �Է�: ";
				cin >> Money;
				it->SetMoney(Money);
			}
			string Worked;
			if (num == 4)
			{
				cout << "�������� �Է�: ";
				cin >> Worked;
				it->SetWorked(Worked);
			}
			string PhoneNumber;
			if (num == 5)
			{
				cout << "��ȭ��ȣ �Է�: ";
				cin >> PhoneNumber;
				it->SetPhoneNumber(PhoneNumber);
			}
		
			break;

		}
		it++;
	}
	return true;
}
bool PersonController::SearchPerson()
{
	string Name;
	cout << "�̸� �Է�: ";	
	cin >> Name;


	list<PersonInfo>::iterator it = m_PersonInfo.begin();
	while (it != m_PersonInfo.end())
	{
		if (Name == it->GetName())
		{
			cout << "�̸�: " << it->GetName() << endl;
			cout << "����: " << it->GetPosition() << endl;
			cout << "�μ�: "<<it->GetGroup() << endl;
			cout << "����: "<<it->GetMoney() << endl;
			cout << "��������: "<<it->GetWorked() << endl;
			cout << "��ȭ��ȣ: "<<it->GetPhoneNumber() << endl;
			break;
		}

		it++;
	}
	getchar();
	return true;
}
bool PersonController::PrintAllPerson()
{
	PersonView pv;
	list<PersonInfo>::iterator it = m_PersonInfo.begin();
	while (it != m_PersonInfo.end())
	{
		cout << "�̸�: " << it->GetName() << endl;
		cout << "����: " << it->GetPosition() << endl;
		cout << "�μ�: " << it->GetGroup() << endl;
		cout << "����: " << it->GetMoney() << endl;
		cout << "��������: " << it->GetWorked() << endl;
		cout << "��ȭ��ȣ: " << it->GetPhoneNumber() << endl;
		pv.DivideLine();
		it++;
	}
	getchar();
	return true;
}
list<PersonInfo>* PersonController::getPerson()
{
	return &m_PersonInfo;
}
