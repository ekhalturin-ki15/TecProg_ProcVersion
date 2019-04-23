﻿#include "Procedural.h"
#include <string>
#include <sstream>

//bool Filippov::Procedural_Input(Procedural &obj, ifstream &fin)
bool Filippov::Procedural_Input(Procedural& obj, stringstream& fin)
{
	string temp;
	fin >> temp;
	/*if (temp == "\0")
	{
		return false;
	}*/
	if (temp.length() > 1)
	{
		return false;
	}
	if (!isdigit(int(unsigned char(temp.front()))))
	{
		return false;
	}

	int state = stoi(temp);
	if (state > 0)
	{
		obj.abstract_type = true;
	}
	else
	{
		obj.abstract_type = false;
	}
	return true;
}

void Filippov::Procedural_Output(Procedural &obj, ofstream &fout)
{
	fout << "It is Procedural programming language: Abstract data types is ";
	if (obj.abstract_type)
	{
		fout << "present, ";
	}
	else
	{
		fout << "missing, ";
	}
}