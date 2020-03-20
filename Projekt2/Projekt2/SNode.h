#pragma once
class SNode
{private:
	int elem;												//dane przechowywane
	SNode* next;											//wezel do nastepnego elementu
	friend class SLinkedList;
public:
	int getElement() { return elem; }
	SNode* getNext() { return next; }
	void setElement(int NewElement) { elem = NewElement; }
	void setNext(SNode* NewNext) { next = NewNext; }
};

