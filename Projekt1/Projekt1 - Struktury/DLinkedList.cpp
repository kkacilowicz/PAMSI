#include "DLinkedList.h"
#include <iostream>

void DLinkedList::addFront(const int& Element)
{

	SNode2* v = new SNode2;
	v->elem = Element;

	v->next = head;
	v->prev = NULL;
	if (head)							//jesli juz wczesniej istnial pierwszy, tworzy link
		head->prev = v;
	head = v;
	if (!tail)							//pierwsze wywolanie
		tail = head;
	
	
	v->key = 1;
	while (v->next)
	{
		v = v->next;
		v->key++;
	}
	
	size_counter++;
}

void DLinkedList::removeFront()
{
	SNode2* old = head;
	head = old->next;
	delete old;
	SNode2* v = new SNode2;
	v->next = head;
	while (v->next)
	{
		v = v->next;
		v->key--;
	}
	size_counter--;
}

void DLinkedList::addRear(const int& Element)
{
	if (head == NULL)									//pierwsze wywolanie
	{
		addFront(Element);
	}
	else
	{
		SNode2* v = new SNode2;
		SNode2* last = tail;
		v->elem = Element;
		tail->next = v;
		v->prev = tail;
		tail = v;
		last->next = v;
		size_counter++;
		v->key = size();
	}
}

void DLinkedList::removeRear()
{
	if (head->next == NULL)
	{
		removeFront();
	}
	else
	{
		SNode2* last = tail;
		tail = last->prev;
		tail->next = NULL;
		delete last;
		

	}
	size_counter--;
}

void DLinkedList::display()
{

	SNode2* tmp = head;
	std::cout << "Elementy listy: ";
	for (int i = 0; i < size(); i++)
	{
		std::cout << tmp->elem << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;

}

void DLinkedList::addAfterKey(const int& Element, int Key)
{
	if (Key >= 0 && Key <= size())
	{
		if (Key == 0)
		{
			addFront(Element);
		}
		else if (Key == size())
		{
			addRear(Element);
		}
		else
		{
			SNode2* v = new SNode2;
			SNode2* Key_After = head;


			for (int i = 0; i < Key -1; i++)
			{
				Key_After = Key_After->next;
			}
			v->setElement(Element);
			v->setPrev(Key_After);
			v->setNext(Key_After->getNext());
			Key_After->setNext(v);
			
			v->next->prev = v;
			
			v->key = Key;


			while (Key_After->next)
			{
				Key_After = Key_After->next;
				Key_After->key++;
			}
			size_counter++;


		}
	}
	else
	{
		std::cout << "Zle podany klucz - musi byc to liczba miedzy 0 a wielkoscia listy" << std::endl;
	}
}

void DLinkedList::removeKey(int Key)
{
	if (Key >= 1 && Key <= size())
	{
		if (Key == 1)
		{
			removeFront();
		}
		else if (Key == size())
		{
			removeRear();
		}
		else
		{
			SNode2* Key_Delete = head;


			for (int i = 1; i < Key - 1; i++)					//wyszukiwanie elementu do usuniecia -1
			{
				Key_Delete = Key_Delete->next;
			}


			SNode2* old = Key_Delete->next;
			(old->getPrev())->setNext(old->getNext());
			(old->getNext())->setPrev(old->getPrev());
			old->setNext(NULL);
			old->setPrev(NULL);
			
			delete old;

			Key_Delete->key = Key-1;						//Ustawienie poprawnego klucza


			while (Key_Delete->next)
			{
				Key_Delete = Key_Delete->next;
				Key_Delete->key--;
			}
			size_counter--;


		}
	}
	else
	{
		std::cout << "Zle podany klucz - musi byc to liczba miedzy 0 a wielkoscia listy" << std::endl;
	}


}
