#pragma once
#include "Edge.h"
#include"PriorityQueue.h"
#include <cstddef>
#include<iostream>
#include <fstream>
class AdjacencyList
{
	/* Edge ** ListofEdges - Jest to tablica list kraw�dzi incydentnych. 
	Pod ka�dym indeksem np. 1, kryje si� "mini-lista" kraw�dzi incydentnych wierzcho�ka 1*/
	Edge** ListofEdges;						//lista kraw�dzi, kt�ra zawiera informacje o incydencjach



	Vertex* headVertex;						//lista wierzcho�k�w
	int nbofEdges;							//liczba kraw�dzi
	int nbofVertices;						//liczba wierzcho�k�w
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
	
	Vertex* endVertices(Edge E);										//zwraca wierzcho�ki po dw�ch ko�cach kraw�dzi
	Vertex* opposite(Vertex *V, Edge *E);   							//zwraca s�siedni wierzcho�ek wierzcho�ka V po kraw�dzi incydentnej E
	bool areAdjacent(Vertex *V, Vertex *W);								//sprawdzenie czy wierzcho�ki s� s�siednie
	void replace(Vertex V, int NewValue) { V.setValue(NewValue); }		//zmiana warto�ci wierzcho�ka - klucza
	void replace(Edge E, int NewWeight) { E.setWeight(NewWeight); }		//zmiana wagi w kraw�dzi
	Vertex* insertVertex(int value);									//dodaje wierzcho�ek na pocz�tek listy wierzcho�k�w
	void insertEdge(Vertex* source, Vertex* target, int Weight);		//wstawianie kraw�dzi grafu, ponadto dodanie do odpowiedniej listy incydencji
	Edge* incidentEdges(Vertex *V);										//zwraca list� kraw�dzi incydentnych danego wierzcho�ka
	Vertex* vertices() { return headVertex; }							//zwraca dost�p do listy wierzcho�k�w
	int edges() { return nbofEdges; }									//liczba kraw�dzi w grafie
	void displayVertices();												//wy�wietlenie wszystkich wierzcho�k�w w grafie
	void displayEdges();												//wy�wietlenie wszystkich kraw�dzi w grafie
	void displayIncidentEdges(int value);								//wy�wietlenie wszystkich kraw�dzi wierzcho�ka, po przyj�ciu jego klucza
	void DijkstraDistances(int startVertex);							//algorytm Dijkstry do wyszukiwania najkr�tszych �cie�ek w grafie
	void DijkstraDistances(int startVertex, std::string OutputName);	//algorytm Dijkstry do wyszukiwania SP oraz zapisu wynik�w dzia�ania do pliku
	bool BellmanFordDistances(int startVertex);							//algorytm Bellmana-Forda do wyszukiwania najkr�tszych �cie�ek w grafie
	bool BellmanFordDistances(int startVertex, std::string OutputName); //algorytm Bellmana-Forda do wyszukiwania SP oraz zapisu wynik�w dzia�ania do pliku
};

