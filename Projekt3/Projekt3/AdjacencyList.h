#pragma once
#include "Edge.h"
#include <cstddef>
class AdjacencyList
{
	Edge* headEdge;							//do listy kraw�dzi
	Vertex* headVertex;						//do listy wierzcho�k�w
	int nbofEdges;							//liczba kraw�dzi
	int nbofVertices;						//liczba wierzcho�k�w
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
	//removeVertex(Vertex V); //usun�� te� kraw�dzie z nim zwi�zane
	//removeEdge(Edge E);
	//incidentEdges(Vertex V);
	//vertices();
	//edges();
};

