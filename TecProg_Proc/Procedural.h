#ifndef PROCEDURAL_H
#define PROCEDURAL_H

#include <fstream>

using namespace std;

namespace Filippov
{
	struct Procedural
	{
		enum lang
		{
			PROCEDURAL,
			OOP
		} key;
		unsigned short int year_of_development;
		bool abstract_type;
	};

	Procedural* Procedural_Input(Procedural &obj, ifstream &fin);
	void Procedural_Output(Procedural *obj, ofstream &fout);
}

#endif // !PROCEDURAL_H
