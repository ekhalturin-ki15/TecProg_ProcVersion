#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "Procedural.h"
#include "OOP.h"
#include "Functional.h"


//Хорошая идея, выделить отдельные namespace
//Cловно static class
namespace Filippov
{
	struct Language
	{
		enum lang
		{
			PROCEDURAL,
			OOP,
			FUNCTIONAL
		} key;
		unsigned int year_of_development;
		unsigned long long int reference;
	};

	//Language *Language_Input(ifstream &fin);
	shared_ptr<void> Language_Input(ifstream& fin);
	void Language_Output(Language &obj, ofstream &fout);
	int Past_Years(Language &obj);
	//bool Compare(Language *first, Language *second);
	bool Compare(shared_ptr<void> first, shared_ptr<void> second);
}

#endif