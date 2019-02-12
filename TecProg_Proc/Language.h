#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "Procedural.h"
#include "OOP.h"
#include "Functional.h"

namespace Filippov
{
	struct Language
	{
		enum lang
		{
			PROCEDURAL,
			OOP
		} key;
		unsigned short int year_of_development;
	};

	Language* Language_Input(ifstream &fin);
	void Language_Output(Language *obj, ofstream &fout);
}

#endif // !LANGUAGE_H