#include "PersonController.h"
#include "PersonView.h"
bool PersonController::InsertPerson()
{
	string Name;
	string Position;
	string Group;
	string Money;
	string PhoneNumber;

	cout << "이름 입력: " ;
	cin >> Name;
	cout << "직급 입력: ";
	cin >> Position;
	cout << "부서 입력: ";
	cin >> Group;
	cout << "연봉 입력: ";
	cin >> Money;
	cout << "전화번호 입력: ";
	cin >> PhoneNumber;

	PersonInfo pi;

	pi.SetName(Name)
		.SetPosition(Position)
		.SetGroup(Group)
		.SetMoney(Money)
		.SetPhoneNumber(PhoneNumber)
		.SetWorked("재직중");

	m_PersonInfo.push_back(pi);
	return true;

}
bool PersonController::DeletePerson()
{
	string Name;
	cout << "이름 입력: ";
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
	cout << "이름 입력: ";
	cin >> Name;

	list<PersonInfo>::iterator it = m_PersonInfo.begin();
	while (it != m_PersonInfo.end())
	{
		if (Name == it->GetName())
		{
			int num;
			cout <<"<1.직급 2.부서 3.연봉 4.재직상태 5.전화번호>"<<endl;
			cin >> num;
			string Position;
			if (num == 1)
			{
				cout << "직급 입력: ";
				cin >> Position;
				it->SetPosition(Position);
			}
			string	Group;
			if (num == 2)
			{
				cout << "부서 입력: ";
				cin >> Group;
				it->SetGroup(Group);
			}
			string Money;
			if (num == 3)
			{
				cout << "연봉 입력: ";
				cin >> Money;
				it->SetMoney(Money);
			}
			string Worked;
			if (num == 4)
			{
				cout << "재직상태 입력: ";
				cin >> Worked;
				it->SetWorked(Worked);
			}
			string PhoneNumber;
			if (num == 5)
			{
				cout << "전화번호 입력: ";
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
	cout << "이름 입력: ";	
	cin >> Name;


	list<PersonInfo>::iterator it = m_PersonInfo.begin();
	while (it != m_PersonInfo.end())
	{
		if (Name == it->GetName())
		{
			cout << "이름: " << it->GetName() << endl;
			cout << "직급: " << it->GetPosition() << endl;
			cout << "부서: "<<it->GetGroup() << endl;
			cout << "연봉: "<<it->GetMoney() << endl;
			cout << "재직상태: "<<it->GetWorked() << endl;
			cout << "전화번호: "<<it->GetPhoneNumber() << endl;
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
		cout << "이름: " << it->GetName() << endl;
		cout << "직급: " << it->GetPosition() << endl;
		cout << "부서: " << it->GetGroup() << endl;
		cout << "연봉: " << it->GetMoney() << endl;
		cout << "재직상태: " << it->GetWorked() << endl;
		cout << "전화번호: " << it->GetPhoneNumber() << endl;
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
