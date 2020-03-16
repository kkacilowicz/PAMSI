#pragma once
class SNode
{private:
	int elem;												//dane przechowywane
	int key;												//klucz - ktory jest w kolejnosci, oznacza dostep do elementu
	SNode* next;											//wezel do nastepnego elementu
	friend class SLinkedList;
public:
	int getElement() { return elem; }
	SNode* getNext() { return next; }
	void setElement(int NewElement) { elem = NewElement; }
	void setNext(SNode* NewNext) { next = NewNext; }
};

