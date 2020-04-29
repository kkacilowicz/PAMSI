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
	E1->setNext(ListofEdges[IndexOfVertexSource]);		//dodanie krawêdzi do listy incydencji danego wierzcho³ka
	ListofEdges[IndexOfVertexSource]=E1;				//ustawienie nowej "g³owy" listy
	nbofEdges++;
}

Edge* AdjacencyList::incidentEdges(Vertex* V)
{
	int index = V->getValue();
	Edge* head = NULL;

	head = ListofEdges[index]; //pobranie "mini-listy" ze wszystkimi krawêdziami incydentnymi wierzcho³ka
	
		
	return head;			//zwrócenie listy incydencji danego wierzcho³ka
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
	while (tmp)											//inicjowanie wartoœci wszystkich wierzcho³ków
	{
		if (tmp->getValue() == startVertex)
			tmp->setDistance(0);
		else
			tmp->setDistance(infinity);

		tmp = tmp->next;
	}

	PriorityQueue *PQ= new PriorityQueue(headVertex, nbofVertices);
	PQ->BuildHeapVertices();

	while (!PQ->empty())											//dopóki nie jest pusta
	{
		Vertex* V = PQ->RemoveMinVertex();
		Edge* E = incidentEdges(V);								//lista krawêdzi incydentnych
		while (E)
		{
			Vertex* Z = opposite(V, E);							//wierzcho³ek po drugiej stronie krawêdzi jest przetwarzany
			int route;
			route = V->getDistance() + E->getWeight();
			if (route < Z->getDistance()) {
				Z->setDistance(route);
			}
			PQ->BuildHeapVertices();
			E = E->next;										//sprawdŸ nastêpn¹ krawêdŸ
		}
	}
	delete PQ;
}

void AdjacencyList::DijkstraDistances(int startVertex, std::string OutputName)
{

	std::ofstream Output;									//plik do zapisu
	std::string* line = new std::string[nbofVertices];		//to s³u¿y do wyœwietlenia œcie¿ki w poprawnej kolejnoœci w pliku
	Output.open(OutputName);

	if (Output.good() == false)
	{
		std::cerr << "Nie mo¿na otworzyæ pliku do zapisu";
	}

	Output << "source: " << startVertex << std::endl;

	int* path = new int[nbofVertices];							//œcie¿ka, zapisywani s¹ w niej poprzednicy
	int* StackofPath = new int[nbofVertices];					//stos do wyœwietlania œcie¿ki
	int infinity = 100000000;

	for (int i = 0; i < nbofVertices; i++)
	{
		path[i] = -1;						//inicjowanie -1, bo ¿aden wierzcho³ek nie ma wartoœci -1;
		StackofPath[i] = -1;
	}


	Vertex* tmp = headVertex;
	while (tmp)											//inicjowanie wartoœci wszystkich wierzcho³ków
	{
		if (tmp->getValue() == startVertex)
			tmp->setDistance(0);						//wierzcho³ek startowy na 0
		else
			tmp->setDistance(infinity);					//reszta na nieskoñczonoœæ

		tmp = tmp->next;
	}

	PriorityQueue *PQ=new PriorityQueue(headVertex, nbofVertices); //tworzenie kolejki priorytetowej i kopiowanie do niej ca³ej listy wierzcho³ków
	PQ->BuildHeapVertices();

	while (!PQ->empty())											//dopóki nie jest pusta
	{
		Vertex* V = PQ->RemoveMinVertex();
		Edge* E = incidentEdges(V);								//lista krawêdzi incydentnych danego wierzcho³ka
		while (E)
		{
			Vertex* Z = opposite(V, E);							//wierzcho³ek po drugiej stronie krawêdzi jest przetwarzany
			int route;
			route = V->getDistance() + E->getWeight();			//droga - wartoœæ œcie¿ki do poprzednika + waga krawêdzi miêdzy nimi
			if (route < Z->getDistance()) {						//jeœli znaleziono krótsz¹ œcie¿kê,
				Z->setDistance(route);							//ustaw now¹ wartoœæ dystansu
				path[Z->getValue()] = V->getValue();			//zapamiêtaj poprzednika
			}
			PQ->BuildHeapVertices();							//przywróæ w³asnoœæ kopca
			E = E->next;										//sprawdŸ nastêpn¹ krawêdŸ
		}
	}
	Vertex* tmp1 = headVertex;

	int i = 0;
	int sptr = 0;
	/*Tutaj znajduje siê zapis do pliku wszystkich œcie¿ek oraz ich wartoœci*/
	while (tmp1)
	{
		line[nbofVertices - (i + 1)].append(std::to_string(nbofVertices - (i + 1)));
		line[nbofVertices - (i + 1)].append("= [ ");

		for (int j = (nbofVertices - (i + 1)); j > -1; j = path[j]) {
			StackofPath[sptr] = j;				//zapis w stosie ka¿dego poprzednika, a¿ dojdzie do wierzcho³ka startowego
			sptr++;
		}

		while (sptr) {
			line[nbofVertices - (i + 1)].append(std::to_string(StackofPath[--sptr]));	//zapis œcie¿ki od wierzcho³ka do wierzcho³ka startowego
			line[nbofVertices - (i + 1)].append(" ");
		}

		line[nbofVertices - (i + 1)].append("] ");
		line[nbofVertices - (i + 1)].append(std::to_string(tmp1->getDistance()));		//zapis kosztu œcie¿ki
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
	while (tmp)											//inicjowanie wartoœci wszystkich wierzcho³ków
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
				Vertex* Z = opposite(V, E);							//wierzcho³ek po drugiej stronie krawêdzi jest przetwarzany
				int route;
				route = V->getDistance() + E->getWeight();
				if (route < Z->getDistance()) {
					Z->setDistance(route);
					Prev[Z->getValue()] = V->getValue();			//zapisuje poprzednika w œcie¿ce
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
			Vertex* Z = opposite(X, E);							//wierzcho³ek po drugiej stronie krawêdzi jest przetwarzany
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
	std::string* line = new std::string[nbofVertices];	//to s³u¿y do wyœwietlenia œcie¿ki w poprawnej kolejnoœci w pliku
	int* StackofPath = new int[nbofVertices];			//stos do przedstawienia pe³nej œcie¿ki do wierzcho³ka
	int infinity = 100000000;
	int* Prev = new int[nbofVertices];					//tablica poprzedniego

	Output.open(OutputName);

	if (Output.good() == false)
	{
		std::cerr << "Nie mo¿na otworzyæ pliku do zapisu";
	}

	Output << "source: " << startVertex << std::endl;

	for (int i = 0; i < nbofVertices; i++)
	{
		StackofPath[i] = -1;
		Prev[i] = -1;
	}

	Vertex* tmp = headVertex;
	while (tmp)											//inicjowanie wartoœci wszystkich wierzcho³ków
	{
		if (tmp->getValue() == startVertex)
			tmp->setDistance(0);						//wierzcho³ek startowy - dystans na 0
		else
			tmp->setDistance(infinity);					//wszystkie inne wierzcho³ki na nisekoñczonoœæ

		tmp = tmp->next;
	}


	for (int i = 1; i < nbofVertices; i++)				//zastosuj dla pozosta³ych V-1 wierzcho³ków
	{
		Vertex* V = headVertex;

		while (V)										//przeszukiwanie ca³ej listy wierzcho³ków
		{
			Edge* E = incidentEdges(V);

			while (E)									//przeszukanie wszystkich krawêdzi incydentnych tego wierzcho³ka (te które z niego wychodz¹)
			{
				Vertex* Z = opposite(V, E);							//wierzcho³ek po drugiej stronie krawêdzi jest przetwarzany
				int route;
				route = V->getDistance() + E->getWeight();			//droga - wartoœæ œcie¿ki do poprzednika + waga krawêdzi miêdzy nimi
				if (route < Z->getDistance()) {						//jeœli znaleziono krótsz¹ œcie¿kê,
					Z->setDistance(route);							//ustaw now¹ wartoœæ dystansu
					Prev[Z->getValue()] = V->getValue();			//zapisuje poprzednika w œcie¿ce
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
			Vertex* Z = opposite(X, E);							//wierzcho³ek po drugiej stronie krawêdzi jest przetwarzany
			int route;
			route = X->getDistance() + E->getWeight();
			if (Z->getDistance()!=infinity&&route < Z->getDistance()) { //jeœli warunek z poprzedniej funkcji dla któregokolwiek wierzcho³ka nie jest spe³niony
				std::cerr << "Error: Ujemny cykl!!!";					//oznacza wyst¹pienie ujemnego cyklu
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
	/*Tutaj znajduje siê zapis do pliku wszystkich œcie¿ek oraz ich wartoœci*/
	while (tmp1)
	{
		line[nbofVertices - (i + 1)].append(std::to_string(nbofVertices - (i + 1)));
		line[nbofVertices - (i + 1)].append("= [ ");
		
		for (int j = (nbofVertices - (i + 1)); j > -1; j = Prev[j]) {
			StackofPath[sptr] = j;			//zapis w stosie ka¿dego poprzednika, a¿ dojdzie do wierzcho³ka startowego
			sptr++;
		}

		while (sptr) {
			line[nbofVertices - (i + 1)].append(std::to_string(StackofPath[--sptr]));	//zapis œcie¿ki od wierzcho³ka do wierzcho³ka startowego
			line[nbofVertices - (i + 1)].append(" ");
		}

		line[nbofVertices - (i + 1)].append("] ");
		line[nbofVertices - (i + 1)].append(std::to_string(tmp1->getDistance()));	//zapis kosztu œcie¿ki
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
