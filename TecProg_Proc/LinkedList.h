#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

/*
�������� ���������, ������� ����� ������
��� ������������� ����� ���������� ������ ������
*/

namespace Filippov
{
	struct Node
	{
		/*
		Language *language;//��������� �� ������ ������
		Node *next;//��������� �� ��������� ������� � ������
		Node *prev;//��������� �� ���������� ������� � ������
		*/
//���������� shared, ��� ��� ������ �� ������ ������������ � ���������� ��������� ���������
		//shared_ptr<Language> language;
		shared_ptr<void> language;
		shared_ptr<Node> next;
		shared_ptr<Node> prev;
	};

	struct Linked_List
	{
		/*
		Node *head;//��������� �� ������ ������� � ������� ������
		Node *tail;//��������� �� ��������� ������� � ������� ������
		*/
		shared_ptr<Node> head;
		shared_ptr<Node> tail;
		size_t size_list;//������ ������
	};

	//void Init(Linked_List &obj); ������ ���������� Clear
	void Clear(Linked_List &obj);
	void Linked_List_Input(Linked_List &obj, ifstream &fin);
	void Linked_List_Output(Linked_List &obj, ofstream &fout);
	void Sort_List(Linked_List &obj);
	//void Swap(Linked_List &obj, Node *first, Node *second);
//���� ������ � �������������� ����� ����������
// �� � ������� ��� ������ ��� ������� (� � ��� ���� ����� ����, ���������� �������� �����)
	//void Swap(Linked_List& obj, shared_ptr<Node>  first, shared_ptr<Node>  second);

	void Only_Procedural(Linked_List &obj, ofstream &fout);

}

#endif