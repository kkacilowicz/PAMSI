#pragma once
#include "Edge.h"
#include <cstddef>
class AdjacencyList
{
	Edge* headEdge;							//do listy krawêdzi
	Vertex* headVertex;						//do listy wierzcho³ków
	int nbofEdges;							//liczba krawêdzi
	int nbofVertices;						//liczba wierzcho³ków
public:
	AdjacencyList() {
		headEdge = NULL;
		headVertex = NULL;
		nbofEdges = 0;
		nbofVertices = 0;
	}
	~AdjacencyList() {
		for (int i = 0; i < nbofEdges; i++)
		{
			Edge* old = headEdge;
			headEdge = old->next;
			delete old;
		}
		for (int i = 0; i < nbofVertices; i++)
		{
			Vertex* old = headVertex;
			headVertex = old->next;
			delete old;
		}

	}
	Vertex* endVertices(Edge E);
	Vertex* opposite(Vertex V, Edge E);
	//areAdjacent(Vertex V, Vertex W);
	//replace(Vertex V, int x);
	//replace(Edge E, int NewWeight);
	//insertVertex(int value);
	//insertEdge(Vertex source, Vertex target, int Weight);
	//removeVertex(Vertex V); //usun¹æ te¿ krawêdzie z nim zwi¹zane
	//removeEdge(Edge E);
	//incidentEdges(Vertex V);
	//vertices();
	//edges();
};

