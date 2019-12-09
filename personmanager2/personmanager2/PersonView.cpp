#include "PersonView.h"
#include <iostream>
#include "PersonModel.h"
#include "turboc.h"
using namespace std;
enum
{
	INSERT =1, MODIFY, DELETED, SEARCH, PRINTALL, EXIT
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
	case DELETED:
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
		show();
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
void PersonView::show()
{
	gotoxy(23, 5);
	cout << "�����������������������";
	gotoxy(24, 6);
	cout << "�����������������������";
	gotoxy(25, 7);
	cout << "�����������������������";
	gotoxy(26, 8);
	cout << "�����������������������";
	gotoxy(27, 9);
	cout << "�����������������������";
	gotoxy(28, 10);
	cout << "�����������������������";
	gotoxy(29, 11);
	cout << "�����������������������";
	gotoxy(30, 12);
	cout << "�����������������������";
}

