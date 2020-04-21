#pragma once
#include "Edge.h"
#include <cstddef>
class AdjacencyList
{
	Edge** ListofEdges;						//lista kraw�dzi
	Vertex** ListofIncidence;				//lista incydencji (wierzcho�ki, kt�re si� spotykaj�)
	Edge* headEdge;
	Vertex* headVertex;						//do listy wierzcho�k�w
	int nbofEdges;							//liczba kraw�dzi
	int nbofVertices;						//liczba wierzcho�k�w
public:
	AdjacencyList(int vertices) {
		ListofEdges = new Edge * [vertices];
		for (int i = 0; i < vertices; i++)
		{
			ListofEdges[i] = NULL;
		}
		ListofIncidence = new Vertex * [vertices];
		for (int i = 0; i < vertices; i++)
		{
			ListofIncidence[i] = NULL;
		}
		headEdge = NULL;
		headVertex = NULL;
		nbofEdges = 0;
		nbofVertices = vertices;
	}
	/*
	~AdjacencyList() {
		for (int i = 0; i < nbofVertices; i++)
		{
			Vertex* old = headVertex;
			headVertex = old->next;
			delete old;
		}

	}
	*/
	Vertex* endVertices(Edge E);
	Vertex* opposite(Vertex *V, Edge *E);
	//bool areAdjacent(Vertex V, Vertex W);
	void replace(Vertex V, int NewValue) { V.setValue(NewValue); }
	void replace(Edge E, int NewWeight) { E.setWeight(NewWeight); }
	Vertex* insertVertex(int value);									//dodaje na pocz�tek listy wierzcho�k�w
	void insertEdge(Vertex* source, Vertex* target, int Weight);
	//void removeVertex(Vertex V); //usun�� te� kraw�dzie z nim zwi�zane
	//void removeEdge(Edge E);
	Edge* incidentEdges(Vertex *V);
	int vertices() { return nbofVertices; }
	int edges() { return nbofEdges; }
	void displayVertices();
	void displayEdges();
	void displayIncidentEdges(int value);
	void test(Vertex *V);
};

