#pragma once
#include "Edge.h"
#include <cstddef>
class AdjacencyList
{
	Edge** ListofEdges;						//lista krawêdzi
	Vertex** ListofIncidence;				//lista incydencji (wierzcho³ki, które siê spotykaj¹)
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
	Vertex* insertVertex(int value);									//dodaje na pocz¹tek listy wierzcho³ków
	void insertEdge(Vertex* source, Vertex* target, int Weight);
	//void removeVertex(Vertex V); //usun¹æ te¿ krawêdzie z nim zwi¹zane
	//void removeEdge(Edge E);
	Edge* incidentEdges(Vertex *V);
	int vertices() { return nbofVertices; }
	int edges() { return nbofEdges; }
	void displayVertices();
	void displayEdges();
	void displayIncidentEdges(int value);
	void test(Vertex *V);
};

