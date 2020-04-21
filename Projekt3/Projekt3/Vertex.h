#pragma once
class Vertex
{private:
	int value;									//wartoœæ wierzcho³ka
	Vertex* next;								//wêze³ do nastêpnego wierzcho³ka w liœcie
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
