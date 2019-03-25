#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Filippov
{
	struct Node
	{
		Language *language;
		Node *next;//указатель на следующий элемент в списке
		Node *prev;//указатель на предыдущий элемент в списке
	};

	struct LinkedList
	{
		Node *first;//указатель на первый элемент в связном списке
		Node *last;//указатель на последний элемент в связном списке
		size_t size_list;
	};

	void Init(LinkedList &obj);
	void Clear(LinkedList &obj);
	void LinkedList_Input(LinkedList &obj, ifstream &fin);
	void LinkedList_Output(LinkedList &obj, ofstream &fout);

	void Multi_Method(LinkedList &obj, ofstream &fout);
}

#endif