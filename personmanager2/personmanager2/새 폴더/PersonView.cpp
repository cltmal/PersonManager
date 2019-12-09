#include "PersonView.h"
#include <iostream>
#include "PersonModel.h"
using namespace std;
enum
{
	INSERT =1, MODIFY, DELETE, SEARCH, PRINTALL, EXIT
};
PersonView::PersonView()
{

}
PersonView::~PersonView()
{

}
PersonController* PersonView::GetPersonController()
{
	return&m_PersonController;
}
void PersonView::showMenu()
{
	cout << "1. 직원정보 입력" << endl;
	cout << "2. 직원정보 수정" << endl;
	cout << "3. 직원정보 삭제" << endl;
	cout << "4. 직원정보 검색" << endl;
	cout << "5. 직원정보 전체출력" << endl;
	cout << "6. 프로그램 종료" << endl;
	DivideLine();
}
int PersonView::GetNumMenu()
{
	int num = 0;
	cin >> num;
	if (num == 0)
		cin.clear();
	return num;
}
bool PersonView::CommandMenu(int num)
{
	bool bRet = true;

	switch (num)
	{
	case INSERT:
		m_PersonController.InsertPerson();
		break;
	case MODIFY:
		m_PersonController.ModifyPerson();
		break;
	case DELETE:
		m_PersonController.DeletePerson();
		break;
	case SEARCH:
		m_PersonController.SearchPerson();
		break;
	case PRINTALL:
		m_PersonController.PrintAllPerson();
		break;
	case EXIT:
		PersonModel pmm;
		pmm.SavePersonInfoFile(m_PersonController.getPerson());
		bRet = false;
		break;

	default:
		cout << "번호 잘못 입력하였다" << endl;
		break;
	}
	getchar();

	return bRet;
}
void PersonView::ClrScr()
{
	system("cls");
}
void PersonView::DivideLine(string strCh, int len)
{
	for (int i = 0; i < len; i++)
		cout << strCh;
	cout << endl;
}

