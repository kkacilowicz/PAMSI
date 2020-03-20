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
	head = v;
	size_counter++;
}

int SLinkedList::removeFront()
{
	SNode* old = head;
	int tmp = old->elem;
	head = old->next;
	delete old;
	SNode* v=new SNode;
	v->next = head;
	size_counter--;
	return tmp;
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
		
	}
	
}

int SLinkedList::removeRear()
{
	if (head->next==NULL)
	{
		removeFront();
	}
	else
	{
		int tmp;
		SNode* last = head;
		while (last->next->next)
		{
			last = last->next;
		}
		tmp = last->next->elem;
		delete last->next;
		last->next = NULL;
		size_counter--;
		return tmp;
	}
	
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

void SLinkedList::split(SLinkedList& S1, SLinkedList& S2)
{
	SNode* v1;
	SNode* v2;
	int tmp=0;
	int initial_size = size();
	S1.addFront(0);
	S2.addFront(0);
	v1 = S1.head;
	v2 = S2.head;

	while (head)
	{
		if (tmp<(initial_size/2))
		{
			
			v1->next = head;
			v1 = v1->next;
			S1.size_counter++;
			tmp++;
			size_counter--;
		}
		else
		{
			v2->next = head;
			v2 = v2->next;
			S2.size_counter++;
			size_counter--;
		}
		head = head->next;
	
	}

	v1->next = v2->next = NULL;

	S1.removeFront();
	S2.removeFront();

}

void SLinkedList::merge(SLinkedList& S1, SLinkedList& S2)
{
	while (!S1.empty()&&!S2.empty())
	{
		if (S1.front()<=S2.front())
		{
			addRear(S1.removeFront());
		}
		else
		{
			addRear(S2.removeFront());
		}
	}
	while (!S1.empty())
	{
		addRear(S1.removeFront());
	}
	while (!S2.empty())
	{
		addRear(S2.removeFront());
	}

}

void SLinkedList::mergesort()
{
	SLinkedList S1, S2;

	if (size() > 1) {
		split(S1, S2);
		S1.mergesort();
		S2.mergesort();
		if (empty())
		{
			merge(S1, S2);

		}
	}
	
}

