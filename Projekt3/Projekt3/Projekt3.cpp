// Projekt3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <ctime>
#include<fstream>
#include"PriorityQueue.h"
#include "AdjacencyList.h"
#include"AdjacencyMatrix.h"

using namespace std;


int main()
{
/*
	fstream File;               //plik z ktorego wczytujemy
	int VSource, VTarget, Weight;
	int nbofvertices, nbofedges, VStart;



	File.open("graphV10Dens0.5.txt", ios::in);
	if (File.good() == false) {
		cout << "Nie wczytano";
		return 0;
	}

	File >> nbofvertices >> nbofedges >> VStart;

	AdjacencyMatrix AM(nbofvertices);

	Vertex** TabVertex = new Vertex * [nbofvertices];


	for (int i = 0; i < nbofvertices; i++)
	{
		TabVertex[i] = AM.insertVertex(i);
	}

	while (!File.eof())
	{
		while (File >> VSource >> VTarget >> Weight)
		{
			AM.insertEdge(TabVertex[VSource], TabVertex[VTarget], Weight);
		}
	}
	File.close();

	

	AM.DijkstraDistances(3);
	*/

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
	
	int nbofvertices;
	nbofvertices = 10;

	AdjacencyMatrix AM(6);

	AdjacencyList AL(nbofvertices);
	Vertex** TabVertex= new Vertex* [nbofvertices];


	for (int i = 0; i < nbofvertices; i++)
	{
		TabVertex[i] = AL.insertVertex(i);
	}
	/*
	AM.insertEdge(TabVertex[0], TabVertex[1], 3);
	AM.insertEdge(TabVertex[0], TabVertex[4], 3);
	AM.insertEdge(TabVertex[1], TabVertex[2], 1);
	AM.insertEdge(TabVertex[2], TabVertex[3], 3);
	AM.insertEdge(TabVertex[2], TabVertex[5], 1);
	AM.insertEdge(TabVertex[3], TabVertex[1], 3);
	AM.insertEdge(TabVertex[4], TabVertex[5], 2);
	AM.insertEdge(TabVertex[5], TabVertex[0], 6);
	AM.insertEdge(TabVertex[5], TabVertex[3], 1);
	AM.displayEdges();
	AM.displayVertices();
	*/
	//AM.DijkstraDistances(0);
	//AM.displayIncidentEdges(0);


	AL.insertEdge(TabVertex[0], TabVertex[1], 75);
	AL.insertEdge(TabVertex[0], TabVertex[5], 111);
	AL.insertEdge(TabVertex[0], TabVertex[6], 30);
	AL.insertEdge(TabVertex[0], TabVertex[7], 119);

	AL.insertEdge(TabVertex[1], TabVertex[0], 123);
	AL.insertEdge(TabVertex[1], TabVertex[2], 27);
	AL.insertEdge(TabVertex[1], TabVertex[4], 101);
	AL.insertEdge(TabVertex[1], TabVertex[7], 48);
	
	AL.insertEdge(TabVertex[2], TabVertex[0], 14);
	AL.insertEdge(TabVertex[2], TabVertex[1], 132);
	AL.insertEdge(TabVertex[2], TabVertex[3], 129);
	AL.insertEdge(TabVertex[2], TabVertex[4], 119);
	AL.insertEdge(TabVertex[2], TabVertex[6], 99);
	AL.insertEdge(TabVertex[2], TabVertex[9], 62);

	AL.insertEdge(TabVertex[3], TabVertex[0], 38);
	AL.insertEdge(TabVertex[3], TabVertex[8], 46);
	AL.insertEdge(TabVertex[3], TabVertex[2], 15);
	AL.insertEdge(TabVertex[3], TabVertex[7], 27);
	
	AL.insertEdge(TabVertex[4], TabVertex[0], 61);
	AL.insertEdge(TabVertex[4], TabVertex[1], 96);
	AL.insertEdge(TabVertex[4], TabVertex[3], 77);
	AL.insertEdge(TabVertex[4], TabVertex[5], 98);
	AL.insertEdge(TabVertex[4], TabVertex[9], 28);
	
	AL.insertEdge(TabVertex[5], TabVertex[8], 32);
	AL.insertEdge(TabVertex[5], TabVertex[1], 113);
	AL.insertEdge(TabVertex[5], TabVertex[3], 86);
	AL.insertEdge(TabVertex[5], TabVertex[9], 81);

	AL.insertEdge(TabVertex[6], TabVertex[0], 120);
	AL.insertEdge(TabVertex[6], TabVertex[2], 65);
	AL.insertEdge(TabVertex[6], TabVertex[3], 102);
	AL.insertEdge(TabVertex[6], TabVertex[5], 29);
	AL.insertEdge(TabVertex[6], TabVertex[8], 15);
	AL.insertEdge(TabVertex[6], TabVertex[9], 122);
	
	AL.insertEdge(TabVertex[7], TabVertex[1], 80);
	AL.insertEdge(TabVertex[7], TabVertex[3], 106);
	AL.insertEdge(TabVertex[7], TabVertex[5], 57);
	AL.insertEdge(TabVertex[7], TabVertex[6], 133);
	
	AL.insertEdge(TabVertex[8], TabVertex[1], 53);
	AL.insertEdge(TabVertex[8], TabVertex[4], 73);
	AL.insertEdge(TabVertex[8], TabVertex[6], 119);
	AL.insertEdge(TabVertex[8], TabVertex[7], 98);

	AL.insertEdge(TabVertex[9], TabVertex[8], 93);
	AL.insertEdge(TabVertex[9], TabVertex[3], 41);
	AL.insertEdge(TabVertex[9], TabVertex[5], 61);
	AL.insertEdge(TabVertex[9], TabVertex[7], 102);

	//AL.displayEdges();

	AL.DijkstraDistances(3);
	

	for (int i = 0; i < nbofvertices; i++)
	{
		delete TabVertex[i];
	}
	delete[] TabVertex;
	
}

