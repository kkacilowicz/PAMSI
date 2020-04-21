#pragma once
#include "Edge.h"
#include <cstddef>
/*Implementacja macierzy s¹siedztwa dla grafu nieskierowanego*/
class AdjacencyMatrix
{
	Vertex* headVertex;						//lista wierzcho³ków
	Edge*  headEdge;						//lista krawêdzi
	Edge*** MatrixEdge;
	int nbofEdges;							//liczba krawêdzi
	int nbofVertices;						//liczba wierzcho³ków
public:
	AdjacencyMatrix(int vertices) {
		MatrixEdge = new Edge ** [vertices];
		for (int i = 0; i < vertices; i++)
		{
			MatrixEdge[i] = new Edge * [vertices];

			for (int j = 0; j < vertices; j++)
			{
				MatrixEdge[i][j] = NULL;
			}
		}
		headEdge = NULL;
		headVertex = NULL;
		nbofEdges = 0;
		nbofVertices = vertices;
	}
	/*
	~AdjacencyMatrix() {

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
			delete[] MatrixEdge[i];
		}
		delete[]MatrixEdge;
		
	}
	*/
	Vertex* endVertices(Edge E);
	Vertex* opposite(Vertex* V, Edge* E);
	bool areAdjacent(Vertex* V, Vertex* W);
	void replace(Vertex *V, int NewValue) { V->setValue(NewValue); }
	void replace(Edge *E, int NewWeight) { E->setWeight(NewWeight); }
	Vertex* insertVertex(int value);									//dodaje na pocz¹tek listy wierzcho³ków
	void insertEdge(Vertex* source, Vertex* target, int Weight);
	Edge* incidentEdges(Vertex* V);
	int vertices() { return nbofVertices; }
	int edges() { return nbofEdges; }
	void displayVertices();
	void displayEdges();
	void displayIncidentEdges(int value);
	//void test(Vertex* V);


};

