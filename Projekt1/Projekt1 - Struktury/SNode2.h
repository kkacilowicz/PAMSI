#pragma once
class SNode2
{private:
		int elem;												//dane przechowywane
		int key;												//klucz - ktory jest w kolejnosci, oznacza dostep do elementu
		SNode2* next;											//wezel do nastepnego elementu
		SNode2* prev;											//wezel do poprzedniego elementu
		friend class DLinkedList;
	public:
		int getElement() { return elem; }
		SNode2* getNext() { return next; }
		SNode2* getPrev() { return prev; }
		void setElement(int NewElement) { elem = NewElement; }
		void setNext(SNode2* NewNext) { next = NewNext; }
		void setPrev(SNode2* NewPrev) { prev = NewPrev; }
};


