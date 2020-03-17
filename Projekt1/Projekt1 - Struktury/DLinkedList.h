#pragma once
#include "SNode2.h"
#include <cstddef>
class DLinkedList
{
private:
	SNode2* tail;										//wezel do ostatniego elementu
	SNode2* head;										//wezel do pierwszego elementu
	int size_counter;									//licznik do wielkosci listy
public:
	DLinkedList() {										//konstruktor
		head = tail = NULL;
		size_counter = 0;
	};
	~DLinkedList() {									//destruktor
		for (int i = 0; i < size(); i++)
		{
			SNode2* old = head;
			head = old->next;
			delete old;
		}
	
	};
	bool empty() const { return head == NULL; };		//sprawdzenie, czy lista jest pusta
	const int& front() const { return head->elem; };	//dostep do pierwszego elementu
	const int& rear() const { return tail->elem; };		//dostep do ostatniego elementu
	void addFront(const int& Element);					//dodanie z przodu listy
	void removeFront();									//usuniecie z przodu listy
	void addRear(const int& Element);					//dodanie z przodu listy
	void removeRear();									//usuniecie z przodu listy
	int size() { return size_counter; }					//wielkosc listy
	void display();										//wyswietlenie wszystkich elementow listy
	void addAfterKey(const int& Element, int Key);		//dodanie elementu po elemencie z kluczem
	void removeKey(int Key);							//usuniecie elementu z zadanym kluczem
};