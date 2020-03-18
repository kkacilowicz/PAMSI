#include "SLinkedList.h"
#include <iostream>

const int& SLinkedList::rear()
{
	if (empty())
	{
		std::cout << "Lista jest pusta - nie mozna pokazac ostatniego elementu" << std::endl;
	}
	else
	{
		SNode* last = head;
		while (last->next)								//dopoki jest jakis nastepny
		{
			last = last->next;							//szukaj ostatniego
		}
		return last->elem;
	}
}

void SLinkedList::addFront(const int& Element)
{
	SNode* v = new SNode;
	v->elem = Element;
	v->next = head;
	v->key = 1;
	head = v;
	while (v->next)
	{
		v = v->next;
		v->key++;
	}
	size_counter++;
}

void SLinkedList::removeFront()
{
	SNode* old = head;
	head = old->next;
	delete old;
	SNode* v=new SNode;
	v->next = head;
	while (v->next)
	{
		v = v->next;
		v->key--;
	}
	size_counter--;
}

void SLinkedList::addRear(const int& Element)
{
		if (head==NULL)									//pierwsze wywolanie
	{
			addFront(Element);
	}
	else
	{
		SNode* v = new SNode;
		SNode* last = head;
		v->elem = Element;
		v->next = NULL;
		while (last->next)								//dopoki jest jakis nastepny
		{
			last = last->next;							//szukaj ostatniego
		}		
		last->next = v;
		size_counter++;
		v->key = size();
	}
	
}

void SLinkedList::removeRear()
{
	if (head->next==NULL)
	{
		removeFront();
	}
	else
	{
		SNode* last = head;
		while (last->next->next)
		{
			last = last->next;
		}
		delete last->next;
		last->next = NULL;
		
	}
	size_counter--;
}

void SLinkedList::display()
{
	SNode* tmp=head;
	std::cout << "Elementy listy: ";
	for (int i = 0; i < size(); i++)
	{
		std::cout << tmp->elem << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;

}

void SLinkedList::addAfterKey(const int& Element, int Key)
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
			SNode* v = new SNode;
			SNode* Key_After = head;
			
			
			for (int i = 0; i < Key-1; i++)
			{
				Key_After = Key_After->next;
			}
			v->setElement(Element);
			v->setNext(Key_After->getNext());
			Key_After->setNext(v);
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

void SLinkedList::removeKey(int Key)
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
			SNode* Key_Delete = head;


			for (int i = 1; i < Key-1; i++)					//wyszukiwanie elementu do usuniecia -1
			{
				Key_Delete = Key_Delete->next;
			}
			

			SNode* old = Key_Delete->next;

			Key_Delete->next = Key_Delete->next->next;		//zawarcie wezla elementu poprzedniego z nastepnym
			Key_Delete = old->next;
			delete old;

			Key_Delete->key = Key;						//Ustawienie poprawnego klucza


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
