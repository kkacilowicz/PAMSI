#pragma once
#include "Edge.h"
#include"PriorityQueue.h"
#include <cstddef>
#include<fstream>
class AdjacencyMatrix
{
	/*MatrixEdge- Macierz s�siedztwa w kt�rej znajduj� si� wska�niki do kraw�dzi
	w kt�rej nr wiersza oznacza klucz wierzcho�ka �r�d�a, a nr kolumny to klucz wierzcho�ka celu */
	Edge*** MatrixEdge;

	Vertex* headVertex;						//lista wierzcho�k�w
	Edge*  headEdge;						//lista kraw�dzi
	int nbofEdges;							//liczba kraw�dzi
	int nbofVertices;						//liczba wierzcho�k�w
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
	
	Vertex* endVertices(Edge E);										//zwraca wierzcho�ki po dw�ch ko�cach kraw�dzi
	Vertex* opposite(Vertex* V, Edge* E);								//zwraca s�siedni wierzcho�ek wierzcho�ka V po kraw�dzi incydentnej E
	bool areAdjacent(Vertex* V, Vertex* W);								//sprawdzenie czy wierzcho�ki s� s�siednie
	void replace(Vertex *V, int NewValue) { V->setValue(NewValue); }	//zmiana warto�ci wierzcho�ka - klucza
	void replace(Edge *E, int NewWeight) { E->setWeight(NewWeight); }	//zmiana wagi w kraw�dzi
	Vertex* insertVertex(int value);									//dodaje na pocz�tek listy wierzcho�k�w
	void insertEdge(Vertex* source, Vertex* target, int Weight);		//wstawianie kraw�dzi grafu, ponadto dodanie do odpowiedniej listy incydencji
	Edge* incidentEdges(Vertex* V);										//zwraca list� kraw�dzi incydentnych danego wierzcho�ka	
	int vertices() { return nbofVertices; }								//liczba wierzcho�k�w w grafie
	int edges() { return nbofEdges; }									//liczba kraw�dzi w grafie
	void displayVertices();												//wy�wietlenie wszystkich wierzcho�k�w w grafie
	void displayEdges();												//wy�wietlenie wszystkich kraw�dzi w grafie
	void displayIncidentEdges(int value);								//wy�wietlenie wszystkich kraw�dzi wierzcho�ka, po przyj�ciu jego klucza
	void DijkstraDistances(int startVertex);							//algorytm Dijkstry do wyszukiwania najkr�tszych �cie�ek w grafie
	void DijkstraDistances(int startVertex, std::string OutputName);	//algorytm Dijkstry do wyszukiwania SP oraz zapisu wynik�w dzia�ania do pliku
	bool BellmanFordDistances(int startVertex);							//algorytm Bellmana-Forda do wyszukiwania najkr�tszych �cie�ek w grafie
	bool BellmanFordDistances(int startVertex, std::string OutputName); //algorytm Bellmana-Forda do wyszukiwania SP oraz zapisu wynik�w dzia�ania do pliku
};

