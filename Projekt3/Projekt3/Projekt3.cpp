// Projekt3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <ctime>
#include"PriorityQueue.h"
#include "AdjacencyList.h"

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




	V->setValue(0);
	V1->setValue(1);
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

	AL.insertVertex(0);

	AL.insertEdge(V, V1, 0);
	AL.insertEdge(V2, V1, 1);
	AL.insertEdge(V4, V5, 2);

	AL.displayEdges();
	cout << endl;
	AL.incidentEdges(V);
}

