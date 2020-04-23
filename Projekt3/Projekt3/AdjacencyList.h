#pragma once
#include "Edge.h"
#include"PriorityQueue.h"
#include <cstddef>
#include<iostream>
class AdjacencyList
{
	Edge** ListofEdges;						//lista krawêdzi, która zawiera informacje o incydencjach
	Edge* headEdge;
	Vertex* headVertex;						//do listy wierzcho³ków
	int nbofEdges;							//liczba krawêdzi
	int nbofVertices;						//liczba wierzcho³ków
public:
	AdjacencyList(int vertices) {
		ListofEdges = new Edge * [vertices];
		for (int i = 0; i < vertices; i++)
		{
			ListofEdges[i] = NULL;
		}
		headEdge = NULL;
		headVertex = NULL;
		nbofEdges = 0;
		nbofVertices = vertices;
	}
	/*
	~AdjacencyList() {
		
		Vertex* tmp = headVertex;
		while (tmp)
		{
			Vertex* old = headVertex;
			headVertex = old->next;
			delete old;
			tmp = tmp->next;
		}
		
		Edge* tmp1 = headEdge;
		while (tmp1)
		{
			Edge* old = headEdge;
			headEdge = old->next;
			delete old;
			tmp1 = tmp1->next;
		}
		for (int i = 0; i < nbofVertices; ++i) {
			delete[] ListofEdges[i];
		}
		delete[] ListofEdges;
		
	}
	*/
	Vertex* endVertices(Edge E);
	Vertex* opposite(Vertex *V, Edge *E);
	bool areAdjacent(Vertex *V, Vertex *W);
	void replace(Vertex V, int NewValue) { V.setValue(NewValue); }
	void replace(Edge E, int NewWeight) { E.setWeight(NewWeight); }
	Vertex* insertVertex(int value);									//dodaje na pocz¹tek listy wierzcho³ków
	void insertEdge(Vertex* source, Vertex* target, int Weight);
	Edge* incidentEdges(Vertex *V);
	Vertex* vertices() { return headVertex; }
	Edge* edges() { return headEdge; }
	void displayVertices();
	void displayEdges();
	void displayIncidentEdges(int value);
	void test(Vertex *V);
	void DijkstraDistances(int startVertex);
};

