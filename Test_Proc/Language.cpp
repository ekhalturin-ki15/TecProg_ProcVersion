#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include "Language.h"
#include <ctime>

Filippov::Language *Filippov::Language_Input(ifstream &fin)
{
	Language *language = new Language;
	Procedural *proc;
	Object_Oriented *oop;
	Functional *func;
	unsigned short int temp;
	fin >> temp;
	fin >> language->year_of_development;
	fin >> language->reference;
	switch (temp)
	{
	case 1:
		proc = new Procedural;
		language->key = Language::lang::PROCEDURAL;
		proc = (Procedural *)language;
		Procedural_Input(*proc, fin);
		return language;
	case 2:
		oop = new Object_Oriented;
		language->key = Language::lang::OOP;
		oop = (Object_Oriented *)language;
		Object_Oriented_Input(*oop, fin);
		return language;
	case 3:
		func = new Functional;
		language->key = Language::lang::FUNCTIONAL;
		func = (Functional *)language;
		Functional_Input(*func, fin);
		return language;
	default:
		return NULL;
	}
}

void Filippov::Language_Output(Language &obj, ofstream &fout)
{
	switch (obj.key)
	{
	case Language::lang::PROCEDURAL:
		Procedural_Output((Procedural&)obj, fout);
		break;
	case Language::lang::OOP:
		Object_Oriented_Output((Object_Oriented&)obj, fout);
		break;
	case Language::lang::FUNCTIONAL:
		Functional_Output((Functional&)obj, fout);
		break;
	default:
		fout << "Incorrect programming language" << endl;
		//return;
	}
	fout << "Year of development = " << obj.year_of_development
		<< ", The number of references of this language on the Internet = " << obj.reference << endl;
}

bool Filippov::Compare(Language *first, Language *second)
{
	return Past_Years(*first) < Past_Years(*second);
}

int Filippov::Past_Years(Language &obj)
{
	time_t now = time(NULL);
	tm *localtm = localtime(&now);
	return 1900 + localtm->tm_year - obj.year_of_development;
}