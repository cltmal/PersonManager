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
	cout << "1. �������� �Է�" << endl;
	cout << "2. �������� ����" << endl;
	cout << "3. �������� ����" << endl;
	cout << "4. �������� �˻�" << endl;
	cout << "5. �������� ��ü���" << endl;
	cout << "6. ���α׷� ����" << endl;
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
		cout << "��ȣ �߸� �Է��Ͽ���" << endl;
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

