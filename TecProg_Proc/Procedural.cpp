#include "Procedural.h"

Filippov::Procedural * Filippov::Procedural_Input(Procedural &obj, ifstream &fin)
{
	fin >> obj.abstract_type;
	return &obj;
}

void Filippov::Procedural_Output(Procedural *obj, ofstream &fout)
{
	fout << "It is Procedural programming language: Abstract data types is ";
	if (obj->abstract_type)
	{
		fout << "present, ";
	}
	else
	{
		fout << "missing, ";
	}
}