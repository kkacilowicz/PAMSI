#pragma once
#include "Vertex.h"
class PriorityQueue
{
private:
	int capacity;
	int* H;
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

		H = NULL;
	}
	PriorityQueue(int* A, int cap) {
		capacity = cap;								//cap oznacza n+1 wielkosc
													//capacity oznacza n
		H = new int[capacity];
		for (int i = 1; i < capacity; i++)
		{
			H[i] = A[i];

		}
		size_counter = capacity - 1;
	}
	~PriorityQueue() { delete[] H; }
	void swapVertices(int value1, int value2);
	bool empty() { return size() == 0; };			//czy jest pusty
	int size() { return size_counter; };			//okreslanie wielkosci kopca
	int Parent(int i) { return i / 2; }				//zwraca rodzica elementu
	int LeftSon(int i) { return 2 * i; }			//zwraca lewego syna
	int RightSon(int i) { return (2 * i) + 1; }		//zwraca prawego syna
	void MinHeapify(int i);							//przywracanie wartoœci kopca typu min
	void MinHeapifyVertices(int i);					//przywracanie wartoœci kopca typu min dla wierzcho³ków
	void display();									//czytelne wyswietlenie kopca
	void displayVertices();							//czytelne wyœwietlenie wierzcho³ków w kolejce priorytetowej
	void BuildHeap();								//budowanie kopca
	void BuildHeapVertices();
	int RemoveMin();								//usun wartoœæ najmniejsz¹ z kopca
	Vertex* RemoveMinVertex();
	void AddElement(int Element);					//dodaj element do kopca
	void upheap(int i);								//przywracanie wlasnosci kopca w gore
};



