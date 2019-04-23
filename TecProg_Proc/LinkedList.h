#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

/*
Основное изменение, которое нужно ввести
Это использование умных указателей вместо ссылок
*/

namespace Filippov
{
	struct Node
	{
		/*
		Language *language;//указатель на объект списка
		Node *next;//указатель на следующий элемент в списке
		Node *prev;//указатель на предыдущий элемент в списке
		*/
//Используем shared, так как ссылка на объект используется у нескольких элементов структуры
		//shared_ptr<Language> language;
		shared_ptr<void> language;
		shared_ptr<Node> next;
		shared_ptr<Node> prev;
	};

	struct Linked_List
	{
		/*
		Node *head;//указатель на первый элемент в связном списке
		Node *tail;//указатель на последний элемент в связном списке
		*/
		shared_ptr<Node> head;
		shared_ptr<Node> tail;
		size_t size_list;//размер списка
	};

	//void Init(Linked_List &obj); Теперь достаточно Clear
	void Clear(Linked_List &obj);
	void Linked_List_Input(Linked_List &obj, ifstream &fin);
	void Linked_List_Output(Linked_List &obj, ofstream &fout);
	void Sort_List(Linked_List &obj);
	//void Swap(Linked_List &obj, Node *first, Node *second);
//Тоже меняем с использованием умных указателей
// Да и ненужна нам больше эта функция (и в ней было много кода, достаточно уязвимое место)
	//void Swap(Linked_List& obj, shared_ptr<Node>  first, shared_ptr<Node>  second);

	void Only_Procedural(Linked_List &obj, ofstream &fout);

}

#endif