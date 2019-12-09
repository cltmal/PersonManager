#include "PersonLoop.h"
#include "PersonModel.h"
#include <list>
PersonLoop::PersonLoop()
{
	list<PersonInfo>* personList =
		m_PersonView.GetPersonController()->getPerson();
	PersonModel pm;
	pm.LoadPersonInfoFile(personList);
		
}
PersonLoop::~PersonLoop()
{

}
void PersonLoop::RunLoop()
{
	bool bRun = true;
	while (bRun)
	{
		PersonView::ClrScr();
		m_PersonView.showMenu();
		int num = m_PersonView.GetNumMenu();
		bRun = m_PersonView.CommandMenu(num);
	}
}