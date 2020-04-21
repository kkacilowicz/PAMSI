#pragma once
class Vertex
{private:
	int value;									//warto�� wierzcho�ka
	Vertex* next;								//w�ze� do nast�pnego wierzcho�ka w li�cie
	friend class AdjacencyList;
public:
	Vertex() {
		value = -1;
		next = nullptr;
	}
	int getValue() { return value; }
	Vertex* getNext() { return next; }
	void setValue(int NewValue) { value = NewValue; }
	void setNext(Vertex* NewNext) { next = NewNext; }
};
