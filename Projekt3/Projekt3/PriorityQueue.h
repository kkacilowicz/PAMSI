#pragma once
#include "Vertex.h"
class PriorityQueue
{
private:
	int capacity;
	int size_counter;
	Vertex** TabVertex;								//tablica wierzcho³ków
public:
	PriorityQueue(Vertex* headVertex, int vertices) {
		capacity = vertices;

		TabVertex = new Vertex*[vertices+1];

		Vertex* tmp = headVertex;
		for (int i = 1; i < vertices+1; i++)
		{
			TabVertex[i] = tmp;
			tmp = tmp->next;
		}

		size_counter = capacity;

	}
	~PriorityQueue() {

		delete[] TabVertex;
	}
	void swapVertices(int value1, int value2);
	bool empty() { return size() == 0; };			//czy jest pusty
	int size() { return size_counter; };			//okreslanie wielkosci kopca
	int Parent(int i) { return i / 2; }				//zwraca rodzica elementu
	int LeftSon(int i) { return 2 * i; }			//zwraca lewego syna
	int RightSon(int i) { return (2 * i) + 1; }		//zwraca prawego syna
	void MinHeapifyVertices(int i);					//przywracanie wartoœci kopca typu min dla wierzcho³ków
	void displayVertices();							//czytelne wyœwietlenie wierzcho³ków w kolejce priorytetowej
	void BuildHeapVertices();
	Vertex* RemoveMinVertex();
};



