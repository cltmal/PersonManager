#include "PersonModel.h"
#include "PersonInfo.h"

bool PersonModel::LoadPersonInfoFile(list<PersonInfo>* personlist)
{
	FILE* fp = NULL;
	fopen_s(&fp, "Person.txt", "rt");
	char temp[1000];
	while(fgets(temp, sizeof(temp), fp) != NULL)
	{
		PersonInfo pi;
		
			
			temp[strlen(temp) - 1] = NULL;
			pi.SetName(temp);

			fgets(temp, sizeof(temp), fp);
			temp[strlen(temp) - 1] = NULL;
			pi.SetPosition(temp);

			fgets(temp, sizeof(temp), fp);
			temp[strlen(temp) - 1] = NULL;
			pi.SetGroup(temp);

			fgets(temp, sizeof(temp), fp);
			temp[strlen(temp) - 1] = NULL;
			pi.SetMoney(temp);

			fgets(temp, sizeof(temp), fp);
			temp[strlen(temp) - 1] = NULL;
			pi.SetWorked(temp);

			fgets(temp, sizeof(temp), fp);
			temp[strlen(temp) - 1] = NULL;
			pi.SetPhoneNumber(temp);

			personlist->push_back(pi);
	}
	fclose(fp);
	return true;
}
bool PersonModel::SavePersonInfoFile(list<PersonInfo>* personlist)
{
	FILE* fp = NULL;
	fopen_s(&fp, "Person.txt", "wt");
	list<PersonInfo>::iterator it = personlist->begin();
	while (it != personlist->end())
	{
		fputs(it->GetName().c_str(), fp); fputc('\n', fp);
		fputs(it->GetPosition().c_str(), fp); fputc('\n', fp);
		fputs(it->GetGroup().c_str(), fp); fputc('\n', fp);
		fputs(it->GetMoney().c_str(), fp); fputc('\n', fp);
		fputs(it->GetWorked().c_str(), fp); fputc('\n', fp);
		fputs(it->GetPhoneNumber().c_str(), fp); fputc('\n', fp);
		it++;
	}
	fclose(fp);
	return true;
	
}