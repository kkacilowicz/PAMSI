#pragma once
#include "SNode.h"
#include <cstddef>
class SLinkedList
{
private:
	SNode* head;										//wezel do pierwszego elementu
	int size_counter;									//licznik do wielkosci listy
public:
	SLinkedList() {										//konstruktor
		head= NULL;
		size_counter = 0;
	};
	~SLinkedList() {									//destruktor
		for (int i = 0; i < size(); i++)
		{
			SNode* old = head;
			head = old->next;
			delete old;
		}
	};
	bool empty() const { return head == NULL; };		//sprawdzenie, czy lista jest pusta
	const int& front() const {return head->elem;};		//dostep do pierwszego elementu
	const int& rear();									//dostep do ostatniego elementu
	void addFront(const int& Element);					//dodanie z przodu listy
	int removeFront();									//usuniecie z przodu listy
	void addRear(const int& Element);					//dodanie z przodu listy
	int removeRear();									//usuniecie z przodu listy
	int size() { return size_counter; }					//wielkosc listy
	void display();										//wyswietlenie wszystkich elementow listy
	void split(SLinkedList& S1, SLinkedList& S2);		//dzielenie listy na pol
	void merge(SLinkedList& S1, SLinkedList& S2);		//scalanie dwoch list w jedna
	void mergesort();
	};


