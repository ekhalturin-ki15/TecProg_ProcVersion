#include "LinkedList.h"

void Filippov::Init(LinkedList &obj)
{
	obj.first = NULL;
	obj.last = NULL;
	obj.size_list = 0;
}

void Filippov::Clear(LinkedList &obj)
{
	Node *Temp = NULL;
	while (obj.last != NULL)
	{
		Temp = obj.last->prev;
		delete obj.last;
		obj.last = Temp;
		--obj.size_list;
	}
	obj.first = Temp;
}

void Filippov::LinkedList_Input(LinkedList &obj, ifstream &fin)
{
	Node *Temp;
	while (!fin.eof())
	{
		Temp = new Node;

		Temp->next = NULL;

		Temp->language = Language_Input(fin);

		++obj.size_list;

		if (obj.first == NULL)
		{
			Temp->prev = NULL;
			obj.first = obj.last = Temp;
		}
		else
		{
			Temp->prev = obj.last;
			obj.last->next = Temp;
			obj.last = Temp;
		}
	}
}

void Filippov::LinkedList_Output(LinkedList &obj, ofstream &fout)
{
	Node *current = obj.first;
	fout << "Container contains " << obj.size_list << " elements." << endl;

	for (size_t i = 0; i < obj.size_list; i++)
	{
		fout << i + 1 << ": ";
		Language_Output(current->language, fout);
		current = current->next;
	}
	fout << endl;
}

void Filippov::Multi_Method(LinkedList &obj, ofstream &fout)
{
	Node *current_first = obj.first;
	Node *current_second = current_first->next;

	fout << "Multimethod." << endl;
	for (size_t i = 0; i < obj.size_list - 1; i++)
	{
		for (size_t j = i + 1; j < obj.size_list; j++)
		{
			switch (current_first->language->key)
			{
			case Language::lang::PROCEDURAL:
				switch (current_second->language->key)
				{
				case Language::lang::PROCEDURAL:
					fout << "Procedural and Procedural." << endl;
					break;
				case Language::lang::OOP:
					fout << "Procedural and OOP." << endl;
					break;
				default:
					fout << "Unknown type." << endl;
					break;
				}
				break;
			case Language::lang::OOP:
				switch (current_second->language->key)
				{
				case Language::lang::PROCEDURAL:
					fout << "OOP and Procedural." << endl;
					break;
				case Language::lang::OOP:
					fout << "OOP and OOP." << endl;
					break;
				default:
					fout << "Unknown type." << endl;
					break;
				}
				break;
			default:
				fout << "Unknown type." << endl;
				break;
			}
			Language_Output(current_first->language, fout);
			Language_Output(current_second->language, fout);
			current_second = current_second->next;
		}
		current_first = current_first->next;
		current_second = current_first->next;
	}
}