#pragma once
#include <climits>
class Vertex
{private:
	int value;									//warto�� wierzcho�ka - klucz
	Vertex* next;								//w�ze� do nast�pnego wierzcho�ka w li�cie
	int distance;								//etykieta dystansu (odleg�o�� od wierzcho�ka startowego)
	friend class AdjacencyList;
	friend class AdjacencyMatrix;
	friend class PriorityQueue;
public:
	Vertex() {
		distance = 1000000;						//pocz�tkowy dystans jest r�wny niesko�czono��
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

