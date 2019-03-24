#include "stdafx.h"
#include "CppUnitTest.h"
#include "Procedural.h"
#include "OOP.h"
#include "Functional.h"
#include "Language.h"
#include "LinkedList.h"

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
		TEST_METHOD(TestMethodProcedural1)
		{
			ifstream fin("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inp1.txt");
			Procedural actual;
			Procedural_Input(actual, fin);
			Procedural expected;
			expected.abstract_type = false;
			Assert::AreEqual(expected.abstract_type, actual.abstract_type);
		}
		TEST_METHOD(TestMethodProcedural2)
		{
			ifstream fin("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inp2.txt");
			Procedural actual;
			Procedural_Input(actual, fin);
			Procedural expected;
			expected.abstract_type = true;
			Assert::AreEqual(expected.abstract_type, actual.abstract_type);
		}
		TEST_METHOD(TestMethodOOP1)
		{
			ifstream fin("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\ino1.txt");
			Object_Oriented actual;
			Object_Oriented_Input(actual, fin);
			Object_Oriented expected;
			expected.number = Object_Oriented::inheritance::SINGLE;
			Assert::AreEqual(int(expected.number), int(actual.number));
		}
		TEST_METHOD(TestMethodFunctional1)
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
		TEST_METHOD(TestMethodLanguage1)
		{
			ifstream fin("C:\\Users\\Александр\\Documents\\Мои документы\\Visual Studio 2015\\Projects\\TecProg_Proc\\Test_Proc\\inl1.txt");
			Language *actual;
			actual = Language_Input(fin);
			Language expected;
			expected.key = Language::lang::FUNCTIONAL;
			expected.year_of_development = 1000;
			expected.reference = 1200;
			Assert::AreEqual(int(expected.key), int(actual->key));
			Assert::AreEqual(int(expected.year_of_development), int(actual->year_of_development));
			Assert::AreEqual(expected.reference, actual->reference);
		}
		//TEST_METHOD(TestMethodLinkedList1)
		//{
		//	
		//}
	};
}