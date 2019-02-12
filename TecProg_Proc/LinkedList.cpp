#include "LinkedList.h"

void Filippov::Init(LinkedList &obj)
{
	obj.First = NULL;
	obj.Last = NULL;
	obj.SizeList = 0;
}

void Filippov::Clear(LinkedList &obj)
{
	Node *Temp = NULL;
	while (obj.Last != NULL)
	{
		Temp = obj.Last->Prev;
		delete obj.Last;
		obj.Last = Temp;
		--obj.SizeList;
	}
	obj.First = Temp;
}

void Filippov::LinkedList_Input(LinkedList &obj, ifstream &fin)
{
	Node *Temp;
	while (!fin.eof())
	{
		Temp = new Node;

		Temp->Next = NULL;

		Temp->language = Language_Input(fin);

		++obj.SizeList;

		if (obj.First == NULL)
		{
			Temp->Prev = NULL;
			obj.First = obj.Last = Temp;
		}
		else
		{
			Temp->Prev = obj.Last;
			obj.Last->Next = Temp;
			obj.Last = Temp;
		}
	}
}

void Filippov::LinkedList_Output(LinkedList &obj, ofstream &fout)
{
	Node *current = obj.First;
	fout << "Container contains " << obj.SizeList << " elements." << endl;

	for (size_t i = 0; i < obj.SizeList; i++)
	{
		fout << i + 1 << ": ";
		Language_Output(current->language, fout);
		fout << "The number of years that have passed since the year the language was created = "
			<< Past_Years(current->language) << endl;
		current = current->Next;
	}
}



void Filippov::Sort_List(LinkedList &obj)
{
	if (obj.SizeList < 2)
		return;

	Node *current = obj.First;

	bool flag = false;

	do
	{
		current = obj.First;
		flag = false;
		for (size_t i = 0; i < (obj.SizeList - 1); ++i)
		{
			if (Compare(current->language, current->Next->language))
			{
				Swap(obj, current, current->Next);
				flag = true;
			}
			else
			{
				current = current->Next;
			}
		}
	} while (flag);
}

void Filippov::Swap(LinkedList &obj, Node *first, Node *second)
{
	if ((first->Prev == NULL) && (second->Next == NULL))//если в списке всего 2 элемента, но нам приспичило поменять их местами
	{
		obj.First = second;
		obj.Last = first;
		first->Prev = second;
		second->Next = first;
		first->Next = NULL;
		second->Prev = NULL;
		return;
	}
	if ((first->Prev == NULL) && (second->Next != NULL))//если мы меняем местами первый и второй элемент списка, в котором 3 и более элементов !(first->Prev)
	{
		first->Next = second->Next;
		first->Prev = second;
		second->Next->Prev = first;
		second->Next = first;
		second->Prev = NULL;
		obj.First = second;
		return;
	}
	if ((first->Prev != NULL) && (second->Next == NULL))//если мы меняем местами предпоследний и последний элемент списка, в котором 3 и более элементов !(second->Next)
	{
		second->Prev = first->Prev;
		first->Prev = second;
		first->Next = NULL;
		second->Next = first;
		second->Prev->Next = second;
		obj.Last = first;
		return;
	}
	if ((first->Prev != NULL) && (second->Next != NULL))//если мы меняем каких-то два элемента, находящихся в середине списка, в котором 4 и более элемента(например второй и третий, если в списке 4 элемента)
	{
		first->Next = second->Next;
		second->Prev = first->Prev;
		second->Next = first;
		first->Prev = second;
		second->Prev->Next = second;
		first->Next->Prev = first;
		return;
	}
}



void Filippov::Only_Procedural(LinkedList &obj, ofstream &fout)
{
	Node *current = obj.First;
	fout << endl << "Only Procedural languages." << endl;

	for (size_t i = 0; i < obj.SizeList; i++)
	{
		fout << i + 1 << ": ";
		if (current->language->key == Language::lang::PROCEDURAL)
		{
			Language_Output(current->language, fout);
		}
		else
		{
			fout << endl;
		}
		current = current->Next;
	}
	fout << endl;
}