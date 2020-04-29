#pragma once
#include <climits>
class Vertex
{private:
	int value;									//wartoœæ wierzcho³ka - klucz
	Vertex* next;								//wêze³ do nastêpnego wierzcho³ka w liœcie
	int distance;								//etykieta dystansu (odleg³oœæ od wierzcho³ka startowego)
	friend class AdjacencyList;
	friend class AdjacencyMatrix;
	friend class PriorityQueue;
public:
	Vertex() {
		distance = 1000000;						//pocz¹tkowy dystans jest równy nieskoñczonoœæ
		value = -1;
		next = nullptr;
	}
	int getDistance() { return distance; }
	int getValue() { return value; }
	Vertex* getNext() { return next; }
	void setDistance(int NewDistance) { distance = NewDistance; }
	void setValue(int NewValue) { value = NewValue; }
	void setNext(Vertex* NewNext) { next = NewNext; }
};

