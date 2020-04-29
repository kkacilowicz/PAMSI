#include "AdjacencyList.h"
#include <iostream>
#include <string>
Vertex* AdjacencyList::endVertices(Edge E)
{
	Vertex* ArrayofVertices[2];

	ArrayofVertices[0] = E.getSource();
	ArrayofVertices[1] = E.getTarget();

	return *ArrayofVertices;
}

Vertex* AdjacencyList::opposite(Vertex *V, Edge *E)
{
	if (V->getValue() == E->getSource()->getValue())
	{
		return E->getTarget();
	}

}

bool AdjacencyList::areAdjacent(Vertex *V, Vertex *W)
{
	int index = V->getValue();
	Edge* tmp = ListofEdges[index];
	int found = -1;
	while (tmp)
	{
		if (tmp->getSource()->getValue() == W->getValue()) {
			found = tmp->getSource()->getValue();
			return true;
		}
		if (tmp->getTarget()->getValue() == W->getValue()) {
			found = tmp->getSource()->getValue();
			return true;
		}

		tmp = tmp->next;
	}

	return false;
}

Vertex* AdjacencyList::insertVertex(int value)
{
	if (headVertex == NULL) {
		Vertex* V = new Vertex;
		V->setValue(value);
		V->setNext(headVertex);
		headVertex = V;
	}
	else if (headVertex->getValue()!=value)
	{
		Vertex* tmp = headVertex;
		while (tmp)
		{
			if (tmp->getValue()==value)
			{
				return headVertex;
			}
			tmp = tmp->next;
		}

		Vertex* V = new Vertex;
		V->setValue(value);
		V->setNext(headVertex);
		headVertex = V;
	}

	return headVertex;
}

void AdjacencyList::insertEdge(Vertex* source, Vertex* target, int Weight)
{
	
	Edge* E1 = new Edge;
	
	E1->setWeight(Weight);
	E1->setSource(source);
	E1->setTarget(target);

	int IndexOfVertexSource = source->getValue();
	int IndexOfVertexTarget = target->getValue();
	E1->setNext(ListofEdges[IndexOfVertexSource]);		//dodanie kraw�dzi do listy incydencji danego wierzcho�ka
	ListofEdges[IndexOfVertexSource]=E1;				//ustawienie nowej "g�owy" listy
	nbofEdges++;
}

Edge* AdjacencyList::incidentEdges(Vertex* V)
{
	int index = V->getValue();
	Edge* head = NULL;

	head = ListofEdges[index]; //pobranie "mini-listy" ze wszystkimi kraw�dziami incydentnymi wierzcho�ka
	
		
	return head;			//zwr�cenie listy incydencji danego wierzcho�ka
}

void AdjacencyList::displayVertices()
{

	Vertex* tmp = headVertex;
	std::cout << "Wierzcholki: " <<std::endl;
	while (tmp)
	{
		std::cout << tmp->getValue() << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

void AdjacencyList::displayEdges()
{
	for (int i = 0; i < nbofEdges; i++)
	{
		Edge* tmp = ListofEdges[i];
		std::cout << "Krawedzie:" << std::endl;
		while (tmp)
		{
			std::cout << "Source " << tmp->getSource()->getValue() << "Target " << tmp->getTarget()->getValue()
				<< "Weight " << tmp->getWeight() << std::endl;
			tmp = tmp->next;
		}
	}
}

void AdjacencyList::displayIncidentEdges(int value)
{
	Edge* tmp = ListofEdges[value];
	std::cout << "Krawedzie:" << std::endl;
	
	while (tmp)
	{
		std::cout << "Source " << tmp->getSource()->getValue() << "Target " << tmp->getTarget()->getValue()
			<< "Weight " << tmp->getWeight() << std::endl;
		tmp = tmp->next;
	}

}

void AdjacencyList::DijkstraDistances(int startVertex)
{
	
	int infinity = 100000000;


	Vertex* tmp = headVertex;
	while (tmp)											//inicjowanie warto�ci wszystkich wierzcho�k�w
	{
		if (tmp->getValue() == startVertex)
			tmp->setDistance(0);
		else
			tmp->setDistance(infinity);

		tmp = tmp->next;
	}

	PriorityQueue *PQ= new PriorityQueue(headVertex, nbofVertices);
	PQ->BuildHeapVertices();

	while (!PQ->empty())											//dop�ki nie jest pusta
	{
		Vertex* V = PQ->RemoveMinVertex();
		Edge* E = incidentEdges(V);								//lista kraw�dzi incydentnych
		while (E)
		{
			Vertex* Z = opposite(V, E);							//wierzcho�ek po drugiej stronie kraw�dzi jest przetwarzany
			int route;
			route = V->getDistance() + E->getWeight();
			if (route < Z->getDistance()) {
				Z->setDistance(route);
			}
			PQ->BuildHeapVertices();
			E = E->next;										//sprawd� nast�pn� kraw�d�
		}
	}
	delete PQ;
}

void AdjacencyList::DijkstraDistances(int startVertex, std::string OutputName)
{

	std::ofstream Output;									//plik do zapisu
	std::string* line = new std::string[nbofVertices];		//to s�u�y do wy�wietlenia �cie�ki w poprawnej kolejno�ci w pliku
	Output.open(OutputName);

	if (Output.good() == false)
	{
		std::cerr << "Nie mo�na otworzy� pliku do zapisu";
	}

	Output << "source: " << startVertex << std::endl;

	int* path = new int[nbofVertices];							//�cie�ka, zapisywani s� w niej poprzednicy
	int* StackofPath = new int[nbofVertices];					//stos do wy�wietlania �cie�ki
	int infinity = 100000000;

	for (int i = 0; i < nbofVertices; i++)
	{
		path[i] = -1;						//inicjowanie -1, bo �aden wierzcho�ek nie ma warto�ci -1;
		StackofPath[i] = -1;
	}


	Vertex* tmp = headVertex;
	while (tmp)											//inicjowanie warto�ci wszystkich wierzcho�k�w
	{
		if (tmp->getValue() == startVertex)
			tmp->setDistance(0);						//wierzcho�ek startowy na 0
		else
			tmp->setDistance(infinity);					//reszta na niesko�czono��

		tmp = tmp->next;
	}

	PriorityQueue *PQ=new PriorityQueue(headVertex, nbofVertices); //tworzenie kolejki priorytetowej i kopiowanie do niej ca�ej listy wierzcho�k�w
	PQ->BuildHeapVertices();

	while (!PQ->empty())											//dop�ki nie jest pusta
	{
		Vertex* V = PQ->RemoveMinVertex();
		Edge* E = incidentEdges(V);								//lista kraw�dzi incydentnych danego wierzcho�ka
		while (E)
		{
			Vertex* Z = opposite(V, E);							//wierzcho�ek po drugiej stronie kraw�dzi jest przetwarzany
			int route;
			route = V->getDistance() + E->getWeight();			//droga - warto�� �cie�ki do poprzednika + waga kraw�dzi mi�dzy nimi
			if (route < Z->getDistance()) {						//je�li znaleziono kr�tsz� �cie�k�,
				Z->setDistance(route);							//ustaw now� warto�� dystansu
				path[Z->getValue()] = V->getValue();			//zapami�taj poprzednika
			}
			PQ->BuildHeapVertices();							//przywr�� w�asno�� kopca
			E = E->next;										//sprawd� nast�pn� kraw�d�
		}
	}
	Vertex* tmp1 = headVertex;

	int i = 0;
	int sptr = 0;
	/*Tutaj znajduje si� zapis do pliku wszystkich �cie�ek oraz ich warto�ci*/
	while (tmp1)
	{
		line[nbofVertices - (i + 1)].append(std::to_string(nbofVertices - (i + 1)));
		line[nbofVertices - (i + 1)].append("= [ ");

		for (int j = (nbofVertices - (i + 1)); j > -1; j = path[j]) {
			StackofPath[sptr] = j;				//zapis w stosie ka�dego poprzednika, a� dojdzie do wierzcho�ka startowego
			sptr++;
		}

		while (sptr) {
			line[nbofVertices - (i + 1)].append(std::to_string(StackofPath[--sptr]));	//zapis �cie�ki od wierzcho�ka do wierzcho�ka startowego
			line[nbofVertices - (i + 1)].append(" ");
		}

		line[nbofVertices - (i + 1)].append("] ");
		line[nbofVertices - (i + 1)].append(std::to_string(tmp1->getDistance()));		//zapis kosztu �cie�ki
		line[nbofVertices - (i + 1)].append("\n");

		i++;
		tmp1 = tmp1->next;
	}

	for (int i = 0; i < nbofVertices; i++)
	{
		Output << line[i];				//zapis do pliku
	}
	Output.close();

	delete PQ;
	delete[] line;
	delete[] StackofPath;
	delete[] path;
}

bool AdjacencyList::BellmanFordDistances(int startVertex)
{

	int infinity =  100000000;

	int* Prev = new int[nbofVertices];

	for (int i = 0; i < nbofVertices; i++)
	{
		Prev[i] = -1;
	}

	Vertex* tmp = headVertex;
	while (tmp)											//inicjowanie warto�ci wszystkich wierzcho�k�w
	{
		if (tmp->getValue() == startVertex)
			tmp->setDistance(0);
		else
			tmp->setDistance(infinity);

		tmp = tmp->next;
	}


	for (int i = 1; i < nbofVertices; i++)
	{
		Vertex* V = headVertex;

		while (V)
		{
			Edge* E = incidentEdges(V);

			while (E)
			{
				Vertex* Z = opposite(V, E);							//wierzcho�ek po drugiej stronie kraw�dzi jest przetwarzany
				int route;
				route = V->getDistance() + E->getWeight();
				if (route < Z->getDistance()) {
					Z->setDistance(route);
					Prev[Z->getValue()] = V->getValue();			//zapisuje poprzednika w �cie�ce
				}

				E = E->next;
			}

			V = V->next;
		}
	}

	Vertex* X = headVertex;

	while (X)
	{
		Edge* E = incidentEdges(X);

		while (E)
		{
			Vertex* Z = opposite(X, E);							//wierzcho�ek po drugiej stronie kraw�dzi jest przetwarzany
			int route;
			route = X->getDistance() + E->getWeight();
			if (route < Z->getDistance()) {
				std::cerr << "Error: Ujemny cykl!!!";
				return false;
			}

			E = E->next;
		}

		X = X->next;
	}

	return true;

	delete[] Prev;

}

bool AdjacencyList::BellmanFordDistances(int startVertex, std::string OutputName)
{

	std::ofstream Output;								//plik zapisowy
	std::string* line = new std::string[nbofVertices];	//to s�u�y do wy�wietlenia �cie�ki w poprawnej kolejno�ci w pliku
	int* StackofPath = new int[nbofVertices];			//stos do przedstawienia pe�nej �cie�ki do wierzcho�ka
	int infinity = 100000000;
	int* Prev = new int[nbofVertices];					//tablica poprzedniego

	Output.open(OutputName);

	if (Output.good() == false)
	{
		std::cerr << "Nie mo�na otworzy� pliku do zapisu";
	}

	Output << "source: " << startVertex << std::endl;

	for (int i = 0; i < nbofVertices; i++)
	{
		StackofPath[i] = -1;
		Prev[i] = -1;
	}

	Vertex* tmp = headVertex;
	while (tmp)											//inicjowanie warto�ci wszystkich wierzcho�k�w
	{
		if (tmp->getValue() == startVertex)
			tmp->setDistance(0);						//wierzcho�ek startowy - dystans na 0
		else
			tmp->setDistance(infinity);					//wszystkie inne wierzcho�ki na niseko�czono��

		tmp = tmp->next;
	}


	for (int i = 1; i < nbofVertices; i++)				//zastosuj dla pozosta�ych V-1 wierzcho�k�w
	{
		Vertex* V = headVertex;

		while (V)										//przeszukiwanie ca�ej listy wierzcho�k�w
		{
			Edge* E = incidentEdges(V);

			while (E)									//przeszukanie wszystkich kraw�dzi incydentnych tego wierzcho�ka (te kt�re z niego wychodz�)
			{
				Vertex* Z = opposite(V, E);							//wierzcho�ek po drugiej stronie kraw�dzi jest przetwarzany
				int route;
				route = V->getDistance() + E->getWeight();			//droga - warto�� �cie�ki do poprzednika + waga kraw�dzi mi�dzy nimi
				if (route < Z->getDistance()) {						//je�li znaleziono kr�tsz� �cie�k�,
					Z->setDistance(route);							//ustaw now� warto�� dystansu
					Prev[Z->getValue()] = V->getValue();			//zapisuje poprzednika w �cie�ce
				}

				E = E->next;
			}

			V = V->next;
		}
	}

	
	Vertex* X = headVertex;

	while (X)
	{
		Edge* E = incidentEdges(X);

		while (E)
		{
			Vertex* Z = opposite(X, E);							//wierzcho�ek po drugiej stronie kraw�dzi jest przetwarzany
			int route;
			route = X->getDistance() + E->getWeight();
			if (Z->getDistance()!=infinity&&route < Z->getDistance()) { //je�li warunek z poprzedniej funkcji dla kt�regokolwiek wierzcho�ka nie jest spe�niony
				std::cerr << "Error: Ujemny cykl!!!";					//oznacza wyst�pienie ujemnego cyklu
				Output << "Error: Ujemny cykl!!!";
				Output << "Error: Ujemny cykl!!!";
				Output.close();
				return false;
			}

			E = E->next;
		}

		X = X->next;
	}
	

	
	Vertex* tmp1 = headVertex;

	int i = 0;
	int sptr = 0;
	/*Tutaj znajduje si� zapis do pliku wszystkich �cie�ek oraz ich warto�ci*/
	while (tmp1)
	{
		line[nbofVertices - (i + 1)].append(std::to_string(nbofVertices - (i + 1)));
		line[nbofVertices - (i + 1)].append("= [ ");
		
		for (int j = (nbofVertices - (i + 1)); j > -1; j = Prev[j]) {
			StackofPath[sptr] = j;			//zapis w stosie ka�dego poprzednika, a� dojdzie do wierzcho�ka startowego
			sptr++;
		}

		while (sptr) {
			line[nbofVertices - (i + 1)].append(std::to_string(StackofPath[--sptr]));	//zapis �cie�ki od wierzcho�ka do wierzcho�ka startowego
			line[nbofVertices - (i + 1)].append(" ");
		}

		line[nbofVertices - (i + 1)].append("] ");
		line[nbofVertices - (i + 1)].append(std::to_string(tmp1->getDistance()));	//zapis kosztu �cie�ki
		line[nbofVertices - (i + 1)].append("\n");

		i++;
		tmp1 = tmp1->next;
	}


	for (int i = 0; i < nbofVertices; i++)
	{
		Output << line[i];	//zapis do pliku
	}
	Output.close();
	return true;

	delete[] line;
	delete[] StackofPath;
	delete[] Prev;
}
