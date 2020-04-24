// Projekt3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <ctime>
#include<fstream>
#include <string>
#include<vector>
#include"PriorityQueue.h"
#include "AdjacencyList.h"
#include"AdjacencyMatrix.h"

using namespace std;


int SPDijkstraMatrix(std::string InputName, std::string OutputName) {


	ifstream Input;               //plik z ktorego wczytujemy
	int VSource, VTarget, Weight;
	int nbofvertices, nbofedges, VStart;


	Input.open(InputName);
	if (Input.good() == false) {
		cout << "Nie wczytano";
		return 0;
	}

	Input >> nbofvertices >> nbofedges >> VStart;

	AdjacencyMatrix AM(nbofvertices);

	Vertex** TabVertex = new Vertex * [nbofvertices];

	for (int i = 0; i < nbofvertices; i++)
	{
		TabVertex[i] = AM.insertVertex(i);
	}

	while (!Input.eof())
	{
		while (Input >> VSource >> VTarget >> Weight)
		{
			AM.insertEdge(TabVertex[VSource], TabVertex[VTarget], Weight);
		}
	}
	Input.close();

	AM.DijkstraDistances(VStart, OutputName);

	for (int i = 0; i < nbofvertices; i++)
	{
		delete TabVertex[i];
	}
	delete[] TabVertex;
}


int SPDijkstraList(std::string InputName, std::string OutputName) {


	ifstream Input;               //plik z ktorego wczytujemy
	int VSource, VTarget, Weight;
	int nbofvertices, nbofedges, VStart;




	Input.open(InputName);
	if (Input.good() == false) {
		cout << "Nie wczytano";
		return 0;
	}


	Input >> nbofvertices >> nbofedges >> VStart;

	AdjacencyList AL(nbofvertices);

	Vertex** TabVertex = new Vertex * [nbofvertices];

	for (int i = 0; i < nbofvertices; i++)
	{
		TabVertex[i] = AL.insertVertex(i);
	}

	while (!Input.eof())
	{
		while (Input >> VSource >> VTarget >> Weight)
		{
			AL.insertEdge(TabVertex[VSource], TabVertex[VTarget], Weight);
		}
	}
	Input.close();



	AL.DijkstraDistances(VStart, OutputName);





	for (int i = 0; i < nbofvertices; i++)
	{
		delete TabVertex[i];
	}
	delete[] TabVertex;
}



int main()
{

	int nbofvertices = 6;

	AdjacencyList AL(nbofvertices);

	Vertex** TabVertex = new Vertex * [nbofvertices];

	for (int i = 0; i < nbofvertices; i++)
	{
		TabVertex[i] = AL.insertVertex(i);
	}

	string Output;
	Output = "test.txt";

	AL.insertEdge(TabVertex[0], TabVertex[1], 3);
	AL.insertEdge(TabVertex[0], TabVertex[4], 3);
	AL.insertEdge(TabVertex[1], TabVertex[2], 1);
	AL.insertEdge(TabVertex[2], TabVertex[3], 3);
	AL.insertEdge(TabVertex[2], TabVertex[5], 1);
	AL.insertEdge(TabVertex[3], TabVertex[1], 3);
	AL.insertEdge(TabVertex[4], TabVertex[5], 2);
	AL.insertEdge(TabVertex[5], TabVertex[0], 6);
	AL.insertEdge(TabVertex[5], TabVertex[3], 1);
	AL.displayEdges();
	AL.displayVertices();
	
	AL.BellmanFordDistances(0, Output);

	////////////////Tutaj są rzeczy do testowania z plików///////////////////////
	/*
	string InputName, OutputName;
	std::vector<int> nVector{ 10, 15, 20, 30, 50, 70, 100, 150, 200 };          //wielkosc tablicy do posortowania
	std::vector<string> Density{ "0.25", "0.5","0.75", "1"}; //wektor oznaczjacy % posortowania przed testem (-1 oznacza reverse)


	
	for (const auto& n : nVector)
	{
		for (const auto& D : Density)
		{

			InputName.append("C:\\Users\\Lenovo\\source\\repos\\kacperowekar\\PAMSI\\Projekt3\\Projekt3\\src\\graphV");
			InputName.append("200");
			InputName.append("Dens");
			InputName.append("1");
			InputName.append(".txt");

			OutputName.append("C:\\Users\\Lenovo\\source\\repos\\kacperowekar\\PAMSI\\Projekt3\\Projekt3\\results\\spV");
			OutputName.append("200");
			OutputName.append("Dens");
			OutputName.append("1");
			OutputName.append(".txt");

			SPDijkstraMatrix(InputName, OutputName);

			InputName.clear();
			OutputName.clear();
		}
	}
	*/
}

