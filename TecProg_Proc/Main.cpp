#include "LinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace Filippov;

int main(int argc, char* argv[])
{
	ifstream fin;
	ofstream fout;

	if (argc != 3)
	{
		//cout << "incorrect command line! "
		//	"Waited: command infile outfile" << endl;

// Для удобства, вместо ошибки, введём стандарнтные файлы
		fin.open("input.txt");
		fout.open("output.txt");

	}
	else
	{
		fin.open(argv[1]);
		fout.open(argv[2]);
	}
	
	if (!fin.is_open())
	{
		cout << "No input file found or could not open!" << endl;
		system("pause");
		return 1;
	}
	

	if (!fout.is_open()) // исправлено на fout.is_open
	{
		cout << "No output file found or could not open!" << endl;
		system("pause");
		return 1;
	}

	cout << "Start" << endl;

	Linked_List list;
	Clear(list);
	Linked_List_Input(list, fin);
	fout << "Filled container." << endl;
	Linked_List_Output(list, fout);

	fout << endl << "Sorted Linked List." << endl;
	Sort_List(list);
	Linked_List_Output(list, fout);

	Only_Procedural(list, fout);

	Clear(list);
	fout << "Empty container." << endl;
	Linked_List_Output(list, fout);

	cout << "Stop" << endl;
	return 0;
}