#include "LinkedList.h"


//Зачем, есть функция Clear (теперь)
/*
void Filippov::Init(Linked_List &obj)
{
	obj.head = NULL;
	obj.tail = NULL;
	obj.size_list = 0;
}
*/
//Удаление объектов больше не нужно, перепишем
/*
void Filippov::Clear(Linked_List &obj)
{
	Node *temp = NULL;
	while (obj.tail != NULL)
	{
		temp = obj.tail->prev;
		delete obj.tail;
		obj.tail = temp;
		--obj.size_list;
	}
	obj.head = temp;
}
*/

//Функция упростилась
void Filippov::Clear(Linked_List& obj)
{
	obj.size_list = 0;
	obj.head = NULL;
	obj.tail = NULL;
}

void Filippov::Linked_List_Input(Linked_List &obj, ifstream &fin)
{
	//Node *temp;
	shared_ptr<Node> temp;
	while (!fin.eof())
	{
		//temp = new Node;
//Больше не используем new
		temp = make_shared<Node>();

		temp->language = Language_Input(fin);
		temp->next = NULL;
		++obj.size_list;

		if (obj.head == NULL)//если список пустой
		{
			temp->prev = NULL;
			obj.head = obj.tail = temp;
		}
		else//если в списке есть хотя бы 1 элемент
		{
			temp->prev = obj.tail;
			obj.tail->next = temp;
			obj.tail = temp;
		}
	}
}

void Filippov::Linked_List_Output(Linked_List &obj, ofstream &fout)
{
	//Node *current = obj.head;
	shared_ptr<Node> current = obj.head;
	fout << "Container contains " << obj.size_list << " elements." << endl;

	for (size_t i = 0; i < obj.size_list; i++)
	{
		fout << i + 1 << ": ";
		if (current->language == NULL)
		{
			fout << "Error reading data! Expected other values in the string." << endl;
		}
		else
		{
			Language_Output(*(Language*)(current->language.get()), fout);
			fout << "The number of years that have passed since the year the language was created = "
				<< Past_Years(*(Language*)(current->language.get()))<< endl;
		}
		current = current->next;
	}
}

void Filippov::Sort_List(Linked_List &obj)
{
	if (obj.size_list < 2)
	{
		return;
	}
	//Node *current = obj.head;
	shared_ptr<Node> current = obj.head;
	bool flag = false;

	//Пузырёк, серьёзно? Ну а почему бы и нет
	do
	{
		current = obj.head;
		flag = false;
		for (size_t i = 0; i < (obj.size_list - 1); ++i)
		{
			if (Compare(current->language, current->next->language))
			{
				//Swap(obj, current, current->next);
			//Нам незачем менять местами всю структуру с указателями
			//Достаточно поменять местами хранимые данные, связи prev и next останутся правильными
				std::swap(current->language, current->next->language);
				flag = true;
			}
			else
			{
				current = current->next;
			}
		}
	} while (flag);
}

void Filippov::Only_Procedural(Linked_List& obj, ofstream& fout)
{
	//Node *current = obj.head;
	shared_ptr<Node> current = obj.head;
	fout << endl << "Only Procedural languages." << endl;

	for (size_t i = 0; i < obj.size_list; i++)
	{
		fout << i + 1 << ": ";
		if (current->language == NULL)
		{
			fout << endl;
			continue;
		}
		if (((Language*)(current->language.get()))->key == Language::lang::PROCEDURAL)
		{
			Language_Output(*(Language*)(current->language.get()), fout);
		}
		else
		{
			fout << endl;
		}
		current = current->next;
	}
	fout << endl;
}

//Функция больше не используется
/*
void Filippov::Swap(Linked_List &obj, Node *first, Node *second)
{
	if ((first->prev == NULL) && (second->next == NULL))//если в списке всего 2 элемента, но нам приспичило поменять их местами
	{
		obj.head = second;
		obj.tail = first;
		first->prev = second;
		second->next = first;
		first->next = NULL;
		second->prev = NULL;
		return;
	}
	//если мы меняем местами первый и второй элемент списка, в котором 3 и более элементов !(first->prev)
	if ((first->prev == NULL) && (second->next != NULL))
	{
		first->next = second->next;
		first->prev = second;
		second->next->prev = first;
		second->next = first;
		second->prev = NULL;
		obj.head = second;
		return;
	}
	//если мы меняем местами предпоследний и последний элемент списка, в котором 3 и более элементов !(second->next)
	if ((first->prev != NULL) && (second->next == NULL))
	{
		second->prev = first->prev;
		first->prev = second;
		first->next = NULL;
		second->next = first;
		second->prev->next = second;
		obj.tail = first;
		return;
	}
	
	если мы меняем каких-то два элемента, находящихся в середине списка, в котором 4 и более элемента
	(например второй и третий, если в списке 4 элемента)
	
	if ((first->prev != NULL) && (second->next != NULL))
	{
		first->next = second->next;
		second->prev = first->prev;
		second->next = first;
		first->prev = second;
		second->prev->next = second;
		first->next->prev = first;
		return;
	}
}
*/
