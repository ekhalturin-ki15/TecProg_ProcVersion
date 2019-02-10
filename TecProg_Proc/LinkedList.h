#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Filippov
{
	struct Node
	{
		Language *language;
		Node *Next;//указатель на следующий элемент в списке
		Node *Prev;//указатель на предыдущий элемент в списке
	};

	struct LinkedList
	{
		Node *First;//указатель на первый элемент в связном списке
		Node *Last;//указатель на последний элемент в связном списке
		size_t SizeList;
	};

	void Init(LinkedList &obj);
	void Clear(LinkedList &obj);

	void LinkedList_Input(LinkedList &obj, ifstream &fin);
	void LinkedList_Output(LinkedList &obj, ofstream &fout);

	void Sort_List(LinkedList &obj);
	void Swap(LinkedList &obj, Node *first, Node *second);
}

#endif // !LINKEDLIST_H