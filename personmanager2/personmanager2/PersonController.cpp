#include "PersonController.h"
#include "PersonView.h"
enum
{
	모든정보=1,부서별검색,직급별검색
};
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
			cout << "수정할 부분을 선택하시오.."<<endl;
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


	cout << "검색목록 선택"<<endl;	
	cout << "1.모든정보 2.부서 검색 3.직급 검색" << endl;
	int num;
	cin >> num;
	int cnt = 0;


	list<PersonInfo>::iterator it = m_PersonInfo.begin();
	if (num == 1)
	{
		string name;
		cout << "이름을 입력하세요: ";
		cin >> name;
		/*name[name.length() - 1] = 0;*/
			while (it != m_PersonInfo.end())
			{
				if (name == it->GetName())
				{
					cout << "이름: " << it->GetName() << endl;
					cout << "직급: " << it->GetPosition() << endl;
					cout << "부서: " << it->GetGroup() << endl;
					cout << "연봉: " << it->GetMoney() << endl;
					cout << "핸드폰번호: " << it->GetPhoneNumber() << endl;
					cout << endl;
					break;
				}
				it++;
			}
			if (it == m_PersonInfo.end())
				cout << "그런 사람 없어요" << endl;
	}
	else if (num == 2)
	{
			string Group;
			cout << "부서를 입력하세여..";
			cin >> Group;

			while (it != m_PersonInfo.end())
			{
				if (Group == it->GetGroup())
				{
					if (cnt == 0)
					{
						cout << it->GetGroup() << "소속 목록입니다." << endl;
						cnt++;
					}
					cout << it->GetName() << endl;
				}
				it++;
			}

			
	}
	else if (num == 3)
	{
		string Position;
		cout << "직급을 입력하세여..";
		cin >> Position;
		while (it != m_PersonInfo.end())
		{
			if (Position == it->GetPosition())
			{
				if (cnt == 0)
				{
					cout << it->GetPosition()<< "소속 목록입니다" <<endl;
					cnt++;
				}
				cout << it->GetName() << endl;
			}
			it++;
		}
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
