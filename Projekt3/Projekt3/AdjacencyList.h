#pragma once
#include "Edge.h"
#include"PriorityQueue.h"
#include <cstddef>
#include<iostream>
#include <fstream>
class AdjacencyList
{
	/* Edge ** ListofEdges - Jest to tablica list krawêdzi incydentnych. 
	Pod ka¿dym indeksem np. 1, kryje siê "mini-lista" krawêdzi incydentnych wierzcho³ka 1*/
	Edge** ListofEdges;						//lista krawêdzi, która zawiera informacje o incydencjach



	Vertex* headVertex;						//lista wierzcho³ków
	int nbofEdges;							//liczba krawêdzi
	int nbofVertices;						//liczba wierzcho³ków
public:
	AdjacencyList(int vertices) {
		ListofEdges = new Edge * [vertices];
		for (int i = 0; i < vertices; i++)
		{
			ListofEdges[i] = NULL;
		}
		headVertex = NULL;
		nbofEdges = 0;
		nbofVertices = vertices;
	}
	
	~AdjacencyList() {



		for (int i = 0; i < nbofVertices; ++i) {
			Edge*tmp= ListofEdges[i];
			while (tmp)
			{
				Edge* old = tmp;
				tmp = old->next;
				delete old;
			}
		}
		delete[] ListofEdges;
	}
	
	Vertex* endVertices(Edge E);										//zwraca wierzcho³ki po dwóch koñcach krawêdzi
	Vertex* opposite(Vertex *V, Edge *E);   							//zwraca s¹siedni wierzcho³ek wierzcho³ka V po krawêdzi incydentnej E
	bool areAdjacent(Vertex *V, Vertex *W);								//sprawdzenie czy wierzcho³ki s¹ s¹siednie
	void replace(Vertex V, int NewValue) { V.setValue(NewValue); }		//zmiana wartoœci wierzcho³ka - klucza
	void replace(Edge E, int NewWeight) { E.setWeight(NewWeight); }		//zmiana wagi w krawêdzi
	Vertex* insertVertex(int value);									//dodaje wierzcho³ek na pocz¹tek listy wierzcho³ków
	void insertEdge(Vertex* source, Vertex* target, int Weight);		//wstawianie krawêdzi grafu, ponadto dodanie do odpowiedniej listy incydencji
	Edge* incidentEdges(Vertex *V);										//zwraca listê krawêdzi incydentnych danego wierzcho³ka
	Vertex* vertices() { return headVertex; }							//zwraca dostêp do listy wierzcho³ków
	int edges() { return nbofEdges; }									//liczba krawêdzi w grafie
	void displayVertices();												//wyœwietlenie wszystkich wierzcho³ków w grafie
	void displayEdges();												//wyœwietlenie wszystkich krawêdzi w grafie
	void displayIncidentEdges(int value);								//wyœwietlenie wszystkich krawêdzi wierzcho³ka, po przyjêciu jego klucza
	void DijkstraDistances(int startVertex);							//algorytm Dijkstry do wyszukiwania najkrótszych œcie¿ek w grafie
	void DijkstraDistances(int startVertex, std::string OutputName);	//algorytm Dijkstry do wyszukiwania SP oraz zapisu wyników dzia³ania do pliku
	bool BellmanFordDistances(int startVertex);							//algorytm Bellmana-Forda do wyszukiwania najkrótszych œcie¿ek w grafie
	bool BellmanFordDistances(int startVertex, std::string OutputName); //algorytm Bellmana-Forda do wyszukiwania SP oraz zapisu wyników dzia³ania do pliku
};

