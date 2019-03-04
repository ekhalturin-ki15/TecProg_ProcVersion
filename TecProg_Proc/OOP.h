#ifndef OOP_H
#define OOP_H

#include <fstream>

using namespace std;

namespace Filippov
{
	struct Object_Oriented
	{
		enum lang
		{
			PROCEDURAL,
			OOP,
			FUNCTIONAL
		} key;
		unsigned short int year_of_development;
		int reference;
		enum inheritance
		{
			SINGLE,
			MULTIPLE,
			INTERFACE
		} number;
	};

	void Object_Oriented_Input(Object_Oriented &obj, ifstream &fin);
	void Object_Oriented_Output(Object_Oriented &obj, ofstream &fout);
}

#endif // !OOP_H