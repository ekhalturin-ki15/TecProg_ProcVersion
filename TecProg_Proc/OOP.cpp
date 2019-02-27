#include "OOP.h"

void Filippov::Object_oriented_Input(Object_oriented &obj, ifstream &fin)
{
	unsigned short int temp;
	fin >> temp;
	switch (temp)
	{
	case 1:
		obj.number = Object_oriented::inheritance::SINGLE;
		break;
	case 2:
		obj.number = Object_oriented::inheritance::MULTIPLE;
		break;
	case 3:
		obj.number = Object_oriented::inheritance::INTERFACE;
		break;
	default:
		break;
	}
}

void Filippov::Object_oriented_Output(Object_oriented &obj, ofstream &fout)
{
	fout << "It is Object-oriented programming language: Inheritance is ";
	switch (obj.number)
	{
	case Object_oriented::inheritance::SINGLE:
		fout << "single, ";
		break;
	case Object_oriented::inheritance::MULTIPLE:
		fout << "multiple, ";
		break;
	case Object_oriented::inheritance::INTERFACE:
		fout << "interface, ";
		break;
	default:
		break;
	}
}