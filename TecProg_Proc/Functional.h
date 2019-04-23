#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include <fstream>

using namespace std;

namespace Filippov
{
	struct Functional
	{
		enum lang
		{
			PROCEDURAL,
			OOP,
			FUNCTIONAL
		} key;
		unsigned int year_of_development;
		unsigned long long int reference;
		bool lazy_calculations;
		enum typification
		{
			STRICT,
			DYNAMIC
		} type;
	};

	//bool Functional_Input(Functional &obj, ifstream &fin);
	bool Functional_Input(Functional& obj, stringstream& fin);
	void Functional_Output(Functional &obj, ofstream &fout);
}

#endif