#include "stdafx.h"
#include "OOP.h"

void Filippov::Object_Oriented_Input(Object_Oriented &obj, ifstream &fin)
{
	unsigned short int temp;
	fin >> temp;
	switch (temp)
	{
	case 1:
		obj.number = Object_Oriented::inheritance::SINGLE;
		break;
	case 2:
		obj.number = Object_Oriented::inheritance::MULTIPLE;
		break;
	case 3:
		obj.number = Object_Oriented::inheritance::INTERFACE;
		break;
	default:
		break;
	}
}

void Filippov::Object_Oriented_Output(Object_Oriented &obj, ofstream &fout)
{
	fout << "It is Object-oriented programming language: Inheritance is ";
	switch (obj.number)
	{
	case Object_Oriented::inheritance::SINGLE:
		fout << "single, ";
		break;
	case Object_Oriented::inheritance::MULTIPLE:
		fout << "multiple, ";
		break;
	case Object_Oriented::inheritance::INTERFACE:
		fout << "interface, ";
		break;
	default:
		break;
	}
}