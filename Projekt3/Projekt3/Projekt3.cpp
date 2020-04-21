// Projekt3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <ctime>
#include"PriorityQueue.h"
#include "AdjacencyList.h"
#include"AdjacencyMatrix.h"

using namespace std;


int main()
{
	//porownywanie nie dziala
	Vertex* V = new Vertex;
	Vertex* V1 = new Vertex;
	Vertex* V2 = new Vertex;
	Vertex* V3 = new Vertex;
	Vertex* V4 = new Vertex;
	Vertex* V5 = new Vertex;
	Vertex* V6 = new Vertex;
	Vertex* V7 = new Vertex;
	Vertex* V8 = new Vertex;
	Vertex* V9 = new Vertex;
	Vertex* V10 = new Vertex;



	
	
	V2->setValue(2);
	V3->setValue(3);
	V4->setValue(4);
	V5->setValue(5);
	V6->setValue(6);
	V7->setValue(7);
	V8->setValue(8);
	V9->setValue(9);
	V10->setValue(10);
	
	AdjacencyList AL(10);
	AdjacencyMatrix AM(10);

	V = AM.insertVertex(0);
	V1 = AM.insertVertex(1);
	AL.insertEdge(V, V1, 0);
	AL.displayEdges();
	AL.displayVertices();
	cout << endl;


	AM.displayVertices();
	AM.insertEdge(V, V1, 0);
	AM.insertEdge(V, V2, 1);
	AM.insertEdge(V, V3, 2);
	AM.displayEdges();
	AM.displayIncidentEdges(0);
}

