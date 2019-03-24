#include "stdafx.h"
#include "CppUnitTest.h"
#include "Procedural.h"
#include "OOP.h"
#include "Functional.h"
#include "Language.h"
#include "LinkedList.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Filippov;
/*
int doubleMe(int x)
{
	return x * 2;
}
*/
namespace Test_Proc
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		/*
		TEST_METHOD(Try2)
		{
			int arg = 2;
			int actual = doubleMe(arg);
			int expected = arg * 2;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(Try3)
		{
			int arg = 3;
			int actual = doubleMe(arg);
			int expected = arg * 2;
			Assert::AreEqual(expected, actual);
		}
		*/
		TEST_METHOD(ProceduralInput1)
		{
			ifstream fin("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inp1.txt");
			Procedural actual;
			Procedural_Input(actual, fin);
			Procedural expected;
			expected.abstract_type = false;
			Assert::AreEqual(expected.abstract_type, actual.abstract_type);
		}
		TEST_METHOD(ProceduralInput2)
		{
			ifstream fin("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inp2.txt");
			Procedural actual;
			Procedural_Input(actual, fin);
			Procedural expected;
			expected.abstract_type = true;
			Assert::AreEqual(expected.abstract_type, actual.abstract_type);
		}
		TEST_METHOD(ProceduralOutput)
		{
			ofstream fout("outp.txt");
			Procedural proc;
			proc.abstract_type = true;
			Procedural_Output(proc, fout);
			fout.close();
			ifstream fin1("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inexp.txt");
			ifstream fin2("outp.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(OOPInput)
		{
			ifstream fin("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\ino1.txt");
			Object_Oriented actual;
			Object_Oriented_Input(actual, fin);
			Object_Oriented expected;
			expected.number = Object_Oriented::inheritance::SINGLE;
			Assert::AreEqual(int(expected.number), int(actual.number));
		}
		TEST_METHOD(OOPOutput)
		{
			ofstream fout("outo.txt");
			Object_Oriented oop;
			oop.number = Object_Oriented::inheritance::MULTIPLE;
			Object_Oriented_Output(oop, fout);
			fout.close();
			ifstream fin1("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inexo.txt");
			ifstream fin2("outo.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(FunctionalInput)
		{
			ifstream fin("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inf1.txt");
			Functional actual;
			Functional_Input(actual, fin);
			Functional expected;
			expected.lazy_calculations = true;
			expected.type = Functional::typification::DYNAMIC;
			Assert::AreEqual(expected.lazy_calculations, actual.lazy_calculations);
			Assert::AreEqual(int(expected.type), int(actual.type));
		}
		TEST_METHOD(FunctionalOutput)
		{
			ofstream fout("outf.txt");
			Functional func;
			func.lazy_calculations = false;
			func.type = Functional::typification::STRICT;
			Functional_Output(func, fout);
			fout.close();
			ifstream fin1("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inexf.txt");
			ifstream fin2("outf.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(LanguageInput)
		{
			ifstream fin("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inl1.txt");
			Language *actual = Language_Input(fin);
			Language expected;
			expected.key = Language::lang::FUNCTIONAL;
			expected.year_of_development = 1000;
			expected.reference = 1200;
			Assert::AreEqual(int(expected.key), int(actual->key));
			Assert::AreEqual(int(expected.year_of_development), int(actual->year_of_development));
			Assert::AreEqual(expected.reference, actual->reference);
		}
		TEST_METHOD(LanguageOutput)
		{
			ofstream fout("outl.txt");
			Language language;
			language.key = Language::lang(5);
			language.year_of_development = 1000;
			language.reference = 1200;
			Language_Output(language, fout);
			fout.close();
			ifstream fin1("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inexl.txt");
			ifstream fin2("outl.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(PastYear)
		{
			Language language;
			language.year_of_development = 2017;
			int actual = Past_Years(language);
			int expected = 2019 - language.year_of_development;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestCompare)
		{
			Language *first = new Language;
			Language *second = new Language;
			first->year_of_development = 2000;
			second->year_of_development = 1000;
			bool actual = Compare(first, second);
			bool expected = true;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(ListOutput)
		{
			ifstream fin("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inlist1.txt");
			ofstream fout("outlist1.txt");
			Linked_List list;
			Init(list);
			Linked_List_Input(list, fin);
			Linked_List_Output(list, fout);
			fout.close();
			ifstream fin1("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inexlist1.txt");
			ifstream fin2("outlist1.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(ProceduralOnlyOutput)
		{
			ifstream fin("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inlist1.txt");
			ofstream fout("outlist2.txt");
			Linked_List list;
			Init(list);
			Linked_List_Input(list, fin);
			Only_Procedural(list, fout);
			fout.close();
			ifstream fin1("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inexlist2.txt");
			ifstream fin2("outlist2.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestSort)
		{
			ifstream fin("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inlist1.txt");
			ofstream fout("outlist3.txt");
			Linked_List list;
			Init(list);
			Linked_List_Input(list, fin);
			Sort_List(list);
			Linked_List_Output(list, fout);
			fout.close();
			ifstream fin1("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inexlist3.txt");
			ifstream fin2("outlist3.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
	};
}