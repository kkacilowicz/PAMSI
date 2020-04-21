#pragma once
#include "Vertex.h"
class Edge
{private:
	int weight;												//waga krawêdzi
	Edge* next;												//wezel do nastepnej krawedzi w liscie krawedzi
	Vertex* source;											//wezel do wierzcholka z ktorego wychodzi
	Vertex* target;											//wezel do wierzcholka do ktorej wchodzi
	friend class AdjacencyList;
	friend class AdjacencyMatrix;
public:
	Edge() {
		next = nullptr;
		source = nullptr;
		target = nullptr;
		weight = 0;
	}
	int getWeight() { return weight; }
	Edge* getNext() { return next; }
	Vertex* getSource() { return source; }
	Vertex* getTarget() { return target; }
	void setWeight(int NewElement) { weight = NewElement; }
	void setNext(Edge* NewNext) { next = NewNext; }
	void setSource(Vertex* NewSource) { source = NewSource; }
	void setTarget(Vertex* NewTarget) { target = NewTarget; }
};

