// Projekt3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <ctime>
#include<fstream>
#include <string>
#include<vector>
#include<chrono>
#include<cmath>
#include"PriorityQueue.h"
#include "AdjacencyList.h"
#include"AdjacencyMatrix.h"

using namespace std;

/* Wczytywanie grafu, wyszukiwania nakrótszej ścieżki dla algorytmu Dijkstra przez macierz sąsiedztwa oraz zapis do pliku wyjściowego*/
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

	return 1;
}

/* Wczytywanie grafu, wyszukiwania nakrótszej ścieżki dla algorytmu Dijkstra przez liste sąsiedztwa oraz zapis do pliku wyjściowego*/
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
	return 1;
}

/* Wczytywanie grafu, wyszukiwania nakrótszej ścieżki dla algorytmu Bellmana-Forda przez liste sąsiedztwa oraz zapis do pliku wyjściowego*/
int SPBellmanFordList(std::string InputName, std::string OutputName) {



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

	if (!AL.BellmanFordDistances(VStart, OutputName)) {
		cerr << "Ujemny cykl!";
	}


	for (int i = 0; i < nbofvertices; i++)
	{
		delete TabVertex[i];
	}
	delete[] TabVertex;

	return 1;
}

/* Wczytywanie grafu, wyszukiwania nakrótszej ścieżki dla algorytmu Bellmana-Forda przez macierz sąsiedztwa oraz zapis do pliku wyjściowego*/
int SPBellmanFordMatrix(std::string InputName, std::string OutputName) {

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

	if (!AM.BellmanFordDistances(VStart, OutputName)) {
		cerr << "Ujemny cykl!";
	}


	for (int i = 0; i < nbofvertices; i++)
	{
		delete TabVertex[i];
	}
	delete[] TabVertex;
	
	return 1;
}

/*Funkcja generująca plik wejściowy wg algorytmu random walk, w którym opisuje graf spójny, ważony, skierowany*/
void Generate_Input(string Inputname, int nbofvertices, int nbofedges)
{
	
	int** array = new int*[nbofvertices];			//taka trochę macierz sąsiedztwa
	for (int i = 0; i < nbofvertices; i++)
	{
		array[i] = new int[nbofvertices];
	}

	for (int i = 0; i < nbofvertices; i++)
	{
		for (int j = 0; j < nbofvertices; j++)		//inicjuję 0, tam się znajdują wagi krawędzi
		{
			array[i][j] = 0;
		}
	}

	ofstream Input;				//trochę mieszanka nazw, ale chodzi o to, że generuje się Input, czyli wejściowy opis krawędzi grafu
	Input.open(Inputname);
	Input.close();					//to robię po to, żeby mieć pewność, że plik z którego potem korzystam jest pusty
	Input.open(Inputname);


	Input << nbofvertices << "\t" << nbofedges << "\t" << 0 << "\n"; // zapis liczby wierzcholkow, liczby krawedzi i wierzcholek poczatkowy jako 0 

	for (int i = 0; i < nbofvertices - 1; i++)
	{
		int source = i; //losuje pierwszy wierzcholek - źródło
		int target = i + 1; //losuje drugi wierzcholek - cel
		int weight = rand();  // losuje wage krawedzi

		array[source][target] = weight;			//zapisuję wagę krawędzi w macierzy

	}
	for (int j = 0; j < nbofedges - nbofvertices + 1; j++)
	{
		int source = rand()%nbofvertices; //losuje pierwsz wierzcholek - źródło
		int target = rand()%nbofvertices; //losuje drugi wierzcholek - cel
		int weight = rand();  // losuje wage krawedzi

		if (source == target) {
			j--;							//nie udało się wykonanie
		}
		else if (target - source == 1) {	//ścieżka już zrobiona
			j--;
		}
		else if (source != target && target - source != 1) {			//ten drugi warunek się bierze z tego, że ścieżkę, już robiłem

			
			if (array[source][target]==0){
			
				array[source][target] = weight;			//zapisz wartość nowej krawędzi
				
			}
			else
				j--;
		}

	}
	for (int i = 0; i < nbofvertices; i++)
	{
		for (int j = 0; j < nbofvertices; j++)
		{
			if (array[i][j] != 0) {
				Input << i << "\t" << j << "\t" << array[i][j] << endl;
			}
		}
	}


	Input.close();

	for (int i = 0; i < nbofvertices; i++)
	{
		delete array[i];
	}
	delete[] array;
}

void Menu_Representation() {

	cout << "Prosze wybrac reprezentacje grafu " << endl;
	cout << "M - macierz sasiedztwa" << endl;
	cout << "L - lista sasiedztwa" << endl;
	cout << "i - zmiana sciezki pliku wejsciowego" << endl;
	cout << "o - zmiana sciezki pliku do zapisu" << endl;
	cout << "x - zakoncz program" << endl;
}

void Menu_Algorithm() {

	cout << "Prosze wybrac algorytm najkrotszej sciezki: " << endl;
	cout << "B - algorytm Bellmana-Forda" << endl;
	cout << "D - algorytm Dijkstry" << endl;
	cout << "i - zmiana sciezki pliku wejsciowego" << endl;
	cout << "o - zmiana sciezki pliku do zapisu" << endl;
	cout << "x - zakoncz program" << endl;
}

void Menu_input() {

	cout << "Prosze podac sciezke do pliku zrodlowego:" << endl;
	cout << "Przyklad: " << endl;
	cout << "Sciezka: C:\\Users\\Lenovo\\Desktop\\graphV10Dens0.5.txt" << endl;
	cout << "Sciezka: ";
}

void Menu_output() {

	cout << "Prosze podac sciezke do pliku zapisu:" << endl;
	cout << "Przyklad: " << endl;
	cout << "Sciezka: C:\\Users\\Lenovo\\Desktop\\spV10Dens0.5.txt" << endl;
	cout << "Sciezka: ";
}

int main()
{


	srand((unsigned)time(0));                          //tworzenie wartosci losowych
	string InputName, OutputName;
	char Representation, Algorithm;


	cout << "Program sluzy do rozwiazywania problemu najkrotszej sciezki w grafie" << endl << endl << endl;

	Menu_input();
	cin >> InputName;
	cout << endl;

	Menu_output();
	cin >> OutputName;
	cout << endl;


	while (1)
	{
		Menu_Algorithm();
		cin >> Algorithm;

		switch (Algorithm)
		{
		case 'B':
			cout << "Wybrano algorytm Bellmana-Forda" << endl;

			Menu_Representation();
			cin >> Representation;
			cout << endl;
			switch (Representation)
			{
			case 'M':
				cout << "Wybrano algorytm Bellmana-Forda dla macierzy sasiedztwa" << endl;
				SPBellmanFordMatrix(InputName, OutputName);
				cout << endl;
				break;
			case 'L':

				cout << "Wybrano algorytm Bellmana-Forda dla listy sasiedztwa"<<endl;
				SPBellmanFordList(InputName, OutputName);
				cout << endl;
				break;
			case 'i':
				Menu_input();
				InputName.clear();
				cin >> InputName;
				break;
			case 'o':
				Menu_output();
				OutputName.clear();
				cin >> OutputName;
				break;
			case 'x':
				cout << "Koniec";
				return 0;
			default:
				cout << "Error: Nie zostala wybrana zadna z opcji reprezentacji z menu" << endl << endl;
				Menu_Representation();
				cin >> Representation;

				break;
			}
			break;
		case 'D':

			cout << "Wybrano algorytm Dijkstry" << endl;

			Menu_Representation();
			cin >> Representation;
			cout << endl;

			switch (Representation)
			{
			case 'M':
				cout << "Wybrano algorytm Dijkstry dla macierzy sasiedztwa" << endl;
				SPDijkstraMatrix(InputName, OutputName);
				cout << endl;
				break;
			case 'L':
				cout << "Wybrano algorytm Dijkstry dla listy sasiedztwa" << endl;
				SPDijkstraList(InputName, OutputName);
				cout << endl;
				break;
			case 'i':
				Menu_input();
				InputName.clear();
				cin >> InputName;
				break;
			case 'o':
				Menu_output();
				OutputName.clear();
				cin >> OutputName;
				break;
			case 'x':
				cout << "Koniec";
				return 0;
			default:
				cout << "Error: Nie zostala wybrana zadna z opcji reprezentacji z menu" << endl << endl;
				Menu_Representation();
				cin >> Representation;
				break;
			}
			break;

		case 'i':
			Menu_input();
			InputName.clear();
			cin >> InputName;
			break;
		case 'o':
			Menu_output();
			OutputName.clear();
			cin >> OutputName;
			break;
		case 'x':
			cout << "Koniec";
			return 0;
		default:
			Menu_Algorithm();
			cin >> Algorithm;
			break;
		}

	}

			
			

			//////////////////////////////////////////////////////TESTY	//////////////////////////////////////////////////////////////////////////

	/*

	int nbofEdges;
	double Sum;


	std::vector<int> nVector{10,25,50,75,100,150,200, 250,300 };        //wielkosc grafu do SP
	std::vector<float> Density{0.25,0.5,0.75,  1 }; //wektor oznaczjacy % gęstości grafu


	//Tests.append("TestyBFMatrix3.txt");
	//Tests.append("TestyBFList2.txt");
	//Tests.append("TestyDijkstraList.txt");
	//Tests.append("TestyDijkstraMatrix.txt");


	//ofstream Testfile;
	//Testfile.open(Tests);

	cout << "Dijkstra Macierz" << endl;

	//Testfile << "Dijkstra Macierz" << endl;
	for (const auto& n : nVector)
	{
		for (const auto& d : Density)
		{
			nbofEdges = d*n*(n-1);

			Sum = 0;
			for (int i = 0; i < 100; i++)
			{


				Generate_Input(InputName, n,nbofEdges);

				ifstream Input;               //plik z ktorego wczytujemy
				int VSource, VTarget, Weight;
				int nbofvertices, nbofedges, VStart;

				Input.open(InputName);
				if (Input.good() == false) {
					cout << "Nie wczytano";
					return 0;
				}

				Input >> nbofvertices >> nbofedges >> VStart;

				AdjacencyMatrix *AM=new AdjacencyMatrix(nbofvertices);

				Vertex** TabVertex = new Vertex * [nbofvertices];

				for (int i = 0; i < nbofvertices; i++)
				{
					TabVertex[i] = AM->insertVertex(i);
				}

				while (!Input.eof())
				{
					while (Input >> VSource >> VTarget >> Weight)
					{
						AM->insertEdge(TabVertex[VSource], TabVertex[VTarget], Weight);
					}
				}
				Input.close();

				auto start = std::chrono::system_clock::now();
				AM->DijkstraDistances(VStart);
				auto end = std::chrono::system_clock::now();

				std::chrono::duration<double> diff = end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
				double durationTime = diff.count(); // zmierzony czas zapisać do pliku lub zagregować, zapisać liczbę badanych elementów
				Sum += durationTime;


				delete AM;


				for (int i = 0; i < nbofvertices; i++)
				{
					delete TabVertex[i];
				}
				delete[] TabVertex;
			}

			cout << "Czas wyszukiwania najkrotszej sciezki dla 100 grafow o wielkosci " << n<<
				" i gestosci " << d* 100 << "% wynosi: " << Sum << endl;

			//Testfile << "Czas wyszukiwania najkrotszej sciezki dla 100 grafow o wielkosci " << n <<
				//" i gestosci " << d * 100 << "% wynosi: " << Sum << endl;
		}
	}
	//Testfile.close();
	*/


}

