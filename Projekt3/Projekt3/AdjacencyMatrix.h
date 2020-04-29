#pragma once
#include "Edge.h"
#include"PriorityQueue.h"
#include <cstddef>
#include<fstream>
class AdjacencyMatrix
{
	/*MatrixEdge- Macierz s¹siedztwa w której znajduj¹ siê wskaŸniki do krawêdzi
	w której nr wiersza oznacza klucz wierzcho³ka Ÿród³a, a nr kolumny to klucz wierzcho³ka celu */
	Edge*** MatrixEdge;

	Vertex* headVertex;						//lista wierzcho³ków
	Edge*  headEdge;						//lista krawêdzi
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
	
	~AdjacencyMatrix() {


		for (int i = 0; i < nbofVertices; ++i) {
			for (int j = 0; j < nbofVertices; j++)
			{
				delete MatrixEdge[i][j];
			}
			delete[] MatrixEdge[i];
		}
		delete[]MatrixEdge;

	
	}
	
	Vertex* endVertices(Edge E);										//zwraca wierzcho³ki po dwóch koñcach krawêdzi
	Vertex* opposite(Vertex* V, Edge* E);								//zwraca s¹siedni wierzcho³ek wierzcho³ka V po krawêdzi incydentnej E
	bool areAdjacent(Vertex* V, Vertex* W);								//sprawdzenie czy wierzcho³ki s¹ s¹siednie
	void replace(Vertex *V, int NewValue) { V->setValue(NewValue); }	//zmiana wartoœci wierzcho³ka - klucza
	void replace(Edge *E, int NewWeight) { E->setWeight(NewWeight); }	//zmiana wagi w krawêdzi
	Vertex* insertVertex(int value);									//dodaje na pocz¹tek listy wierzcho³ków
	void insertEdge(Vertex* source, Vertex* target, int Weight);		//wstawianie krawêdzi grafu, ponadto dodanie do odpowiedniej listy incydencji
	Edge* incidentEdges(Vertex* V);										//zwraca listê krawêdzi incydentnych danego wierzcho³ka	
	int vertices() { return nbofVertices; }								//liczba wierzcho³ków w grafie
	int edges() { return nbofEdges; }									//liczba krawêdzi w grafie
	void displayVertices();												//wyœwietlenie wszystkich wierzcho³ków w grafie
	void displayEdges();												//wyœwietlenie wszystkich krawêdzi w grafie
	void displayIncidentEdges(int value);								//wyœwietlenie wszystkich krawêdzi wierzcho³ka, po przyjêciu jego klucza
	void DijkstraDistances(int startVertex);							//algorytm Dijkstry do wyszukiwania najkrótszych œcie¿ek w grafie
	void DijkstraDistances(int startVertex, std::string OutputName);	//algorytm Dijkstry do wyszukiwania SP oraz zapisu wyników dzia³ania do pliku
	bool BellmanFordDistances(int startVertex);							//algorytm Bellmana-Forda do wyszukiwania najkrótszych œcie¿ek w grafie
	bool BellmanFordDistances(int startVertex, std::string OutputName); //algorytm Bellmana-Forda do wyszukiwania SP oraz zapisu wyników dzia³ania do pliku
};

