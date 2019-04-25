#define _CRT_SECURE_NO_WARNINGS
#include "Language.h"
#include <ctime>
#include <string>
#include <sstream>


shared_ptr<void> Deleter(unique_ptr<Filippov::Functional>& func1)
{
	unique_ptr<Filippov::Functional> func2;
	func2 = unique_ptr<Filippov::Functional>(func1.release());
	return func2;
}
//Filippov::Language *Filippov::Language_Input(ifstream &fin)
//Придётся сделать void*, иначе, размеры не состыкуются
shared_ptr<void> Filippov::Language_Input(ifstream& fin)
{
	/*
	Language *language = new Language;
	Procedural *proc;
	Object_Oriented *oop;
	Functional *func;
	*/

	unique_ptr<Language> language;
	language = make_unique<Language>();
	unique_ptr<Procedural> proc;
	unique_ptr<Object_Oriented> oop;
	unique_ptr<Functional> func;
	string temp;

	//Самому парсить строку и делать проверки неудобно
	//Воспользуемся с++ streamstring
	stringstream line;
	getline(fin, temp, '\n');
	line.str(temp);
	//Всё, у нас есть буффер для считывания, и за его пределы мы не выйдём

		//fin >> temp;
	line >> temp;

	/*if (temp == "\0")
	{
		return false;
	}*/

	if (temp.size() != 1)
	{
		//fin.get();
		getline(fin, temp, '\n');
		return NULL;
	}

	if (!isdigit(int(unsigned char(temp.front()))))
	{
		fin.get();
		getline(fin, temp, '\n');
		return NULL;
	}
	int state = stoi(temp);

	getline(fin, temp, '\n');
	line.clear();
	line.str(temp);

	//fin >> temp;
	line >> temp;

	//Больше этот отдельный случай не требуется
		/*if (temp == "\0")
		{
			return false;
		}
		*/
	if (temp.length() != 4)
	{
		//getline(fin, temp, '\n');
		return NULL;
	}
	for (auto iter = temp.begin(); iter != temp.end(); ++iter)
	{
		if (!isdigit(int(unsigned char(*iter))))
		{
			//getline(fin, temp, '\n');
			return NULL;
		}
	}


	language->year_of_development = stoul(temp);

	//fin >> temp;
	line >> temp;
	//if (temp == "\0")
	//{
	//	return false;
	//}
	for (auto iter = temp.begin(); iter != temp.end(); ++iter)
	{
		if (!isdigit(int(unsigned char(*iter))))
		{
			//getline(fin, temp, '\n');
			return NULL;
		}
	}
	language->reference = stoull(temp);

	switch (state)
	{
	case 1:
		//proc = new Procedural;
		language->key = Language::lang::PROCEDURAL;
		proc = unique_ptr<Procedural>((Procedural*)language.release());

		//if (!Procedural_Input(*proc, fin))
		if (!Procedural_Input(*proc, line))
		{
			return NULL;
		}
		else
		{
			//return language;
			//language = unique_ptr<Language>((Language*)proc.release());
			return proc;
		}

	case 2:
		//oop = new Object_Oriented;
		language->key = Language::lang::OOP;
		//oop = (Object_Oriented *)language;
		oop = unique_ptr<Object_Oriented>((Object_Oriented*)language.release());
		//if (!Object_Oriented_Input(*oop, fin))
		if (!Object_Oriented_Input(*oop, line))
		{
			return NULL;
		}
		else
		{
			//language = unique_ptr<Language>((Language*)oop.release());
			return oop;
		}
	case 3:
		//func = new Functional;
		language->key = Language::lang::FUNCTIONAL;
		//func = (Functional *)language;
		func = unique_ptr<Functional>((Functional*)language.release());
		//if (!Functional_Input(*func, fin))
		if (!Functional_Input(*func, line))
		{
			//Честно - не знаю, но нужно очистить самому
			//Теперь знаю, нельзя удалять наполовину заполненую структуру, различия в размере
			return NULL;
		}
		else
		{
			//language = unique_ptr<Language>((Language*)func.release());
			return func;
		}

	default:
		//getline(fin, temp, '\n');
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
		return;
	}
	fout << "Year of development = " << obj.year_of_development
		<< ", The number of references of this language on the Internet = " << obj.reference << endl;
}

int Filippov::Past_Years(Language &obj)
{
	time_t now = time(NULL);
	tm *localtm = localtime(&now);
	return 1900 + localtm->tm_year - obj.year_of_development;
}

//bool Filippov::Compare(Language *first, Language *second)
bool Filippov::Compare(shared_ptr<void> first, shared_ptr<void> second)
{
	if (first == NULL && second != NULL)
	{
		return true;
	}
	if (first != NULL && second == NULL)
	{
		return false;
	}
	if (first == NULL && second == NULL)
	{
		return false;
	}
//Лучше сделать так, чтобы был возрат результата в любом случаи
	/*if (first != NULL && second != NULL)
	{
		return Past_Years(*first) < Past_Years(*second);
	}*/
	return Past_Years(*(Language*)(first.get())) < Past_Years(*(Language*)(second.get()));
}