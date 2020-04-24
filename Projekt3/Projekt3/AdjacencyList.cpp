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

//tutaj trzeba jeszcze te funkcjonalnosc z powiekszaniem tablicy
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
	Edge* E = new Edge;
	Edge* E1 = new Edge;
	E->setWeight(Weight);
	E->setSource(source);
	E->setTarget(target);

	E1->setWeight(Weight);
	E1->setSource(source);
	E1->setTarget(target);

	int IndexOfVertexSource = source->getValue();
	int IndexOfVertexTarget = target->getValue();
	E->setNext(headEdge);
	E1->setNext(ListofEdges[IndexOfVertexSource]);
	ListofEdges[IndexOfVertexSource]=E1;
	headEdge = E;
	nbofEdges++;
}

Edge* AdjacencyList::incidentEdges(Vertex* V)
{
	int index = V->getValue();
	Edge* head = NULL;

	head = ListofEdges[index];
	
		
	return head;
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
	Edge* tmp =headEdge;
	std::cout << "Krawedzie:" << std::endl;
	while (tmp)
	{
		std::cout << "Source " << tmp->getSource()->getValue() << "Target " << tmp->getTarget()->getValue()
			<< "Weight " << tmp->getWeight() << std::endl;
		tmp = tmp->next;
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



void AdjacencyList::test(Vertex* V)
{
	
	Vertex* last = headVertex;
	while (last->next->next)
	{
		if (last->getValue() == V->getValue())
		{
			std::cout << "Udalo sie";
			break;
		}

		last = last->next;
	}
	

}

void AdjacencyList::DijkstraDistances(int startVertex)
{
	
	int infinity = INT_MAX;


	Vertex* tmp = headVertex;
	while (tmp)											//inicjowanie wartoœci wszystkich wierzcho³ków
	{
		if (tmp->getValue() == startVertex)
			tmp->setDistance(0);
		else
			tmp->setDistance(infinity);

		tmp = tmp->next;
	}

	PriorityQueue PQ(headVertex, nbofVertices);
	PQ.BuildHeapVertices();

	while (!PQ.empty())											//dopóki nie jest pusta
	{
		Vertex* V = PQ.RemoveMinVertex();
		Edge* E = incidentEdges(V);								//lista krawêdzi incydentnych
		while (E)
		{
			Vertex* Z = opposite(V, E);							//wierzcho³ek po drugiej stronie krawêdzi jest przetwarzany
			int route;
			route = V->getDistance() + E->getWeight();
			if (route < Z->getDistance()) {
				Z->setDistance(route);
			}
			PQ.BuildHeapVertices();
			E = E->next;										//sprawdŸ nastêpn¹ krawêdŸ
		}
	}
}

void AdjacencyList::DijkstraDistances(int startVertex, std::string OutputName)
{

	std::ofstream Output;
	std::string* line = new std::string[nbofVertices];
	Output.open(OutputName);

	if (Output.good() == false)
	{
		std::cerr << "Nie mo¿na otworzyæ pliku do zapisu";
	}

	Output << "source: " << startVertex << std::endl;

	int* path = new int[nbofVertices];				//œcie¿ka
	int* StackofPath = new int[nbofVertices];					//stos do wyœwietlania œcie¿ki
	int infinity = INT_MAX;

	for (int i = 0; i < nbofVertices; i++)
	{
		path[i] = -1;						//inicjowanie -1, bo ¿aden wierzcho³ek nie ma wartoœci -1;
		StackofPath[i] = -1;
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

	PriorityQueue PQ(headVertex, nbofVertices);
	PQ.BuildHeapVertices();

	while (!PQ.empty())											//dopóki nie jest pusta
	{
		Vertex* V = PQ.RemoveMinVertex();
		Edge* E = incidentEdges(V);								//lista krawêdzi incydentnych
		while (E)
		{
			Vertex* Z = opposite(V, E);							//wierzcho³ek po drugiej stronie krawêdzi jest przetwarzany
			int route;
			route = V->getDistance() + E->getWeight();
			if (route < Z->getDistance()) {
				Z->setDistance(route);
				path[Z->getValue()] = V->getValue();
			}
			PQ.BuildHeapVertices();
			E = E->next;										//sprawdŸ nastêpn¹ krawêdŸ
		}
	}
	int sptr = 0;
	Vertex* tmp1 = headVertex;
	for (int i = 0; i < nbofVertices; i++)
	{
		line[nbofVertices - (i + 1)].append(std::to_string(nbofVertices - (i + 1)));
		line[nbofVertices - (i + 1)].append("= [  ");

		for (int j = (nbofVertices - (i + 1)); j > -1; j = path[j]) StackofPath[sptr++] = j;

		while (sptr) {
			line[nbofVertices - (i + 1)].append(std::to_string(StackofPath[--sptr]));
			line[nbofVertices - (i + 1)].append(" ");
		}
		line[nbofVertices - (i + 1)].append("] ");
		line[nbofVertices - (i + 1)].append(std::to_string(tmp1->getDistance()));
		line[nbofVertices - (i + 1)].append("\n");
		tmp1 = tmp1->next;
	}
	for (int i = 0; i < nbofVertices; i++)
	{
		Output << line[i];
	}
	Output.close();


	delete[] line;
	delete[] StackofPath;
	delete[] path;
}

bool AdjacencyList::BellmanFordDistances(int startVertex)
{

	std::string* line = new std::string[nbofVertices];
	int* StackofPath = new int[nbofVertices];
	int infinity = INT_MAX - 1000;

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


	int sptr = 0;
	Vertex* tmp1 = headVertex;
	for (int i = 0; i < nbofVertices; i++)
	{
		line[nbofVertices - (i + 1)].append(std::to_string(nbofVertices - (i + 1)));
		line[nbofVertices - (i + 1)].append("= [  ");

		for (int j = (nbofVertices - (i + 1)); j > -1; j = Prev[j]) StackofPath[sptr++] = j;

		while (sptr) {
			line[nbofVertices - (i + 1)].append(std::to_string(StackofPath[--sptr]));
			line[nbofVertices - (i + 1)].append(" ");
		}
		line[nbofVertices - (i + 1)].append("] ");
		line[nbofVertices - (i + 1)].append(std::to_string(tmp1->getDistance()));
		line[nbofVertices - (i + 1)].append("\n");
		tmp1 = tmp1->next;
	}

	for (int i = 0; i < nbofVertices; i++)
	{
		std::cout << line[i];
	}

	return true;

	delete[] line;
	delete[] StackofPath;
	delete[] Prev;

}

bool AdjacencyList::BellmanFordDistances(int startVertex, std::string OutputName)
{

	std::ofstream Output;
	std::string* line = new std::string[nbofVertices];
	int* StackofPath = new int[nbofVertices];
	int infinity = INT_MAX - 1000;
	int* Prev = new int[nbofVertices];

	Output.open(OutputName);

	if (Output.good() == false)
	{
		std::cerr << "Nie mo¿na otworzyæ pliku do zapisu";
	}

	Output << "source: " << startVertex << std::endl;

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
				Output << "Error: Ujemny cykl!!!";
				Output.close();
				return false;
			}

			E = E->next;
		}

		X = X->next;
	}


	int sptr = 0;
	Vertex* tmp1 = headVertex;
	for (int i = 0; i < nbofVertices; i++)
	{
		line[nbofVertices - (i + 1)].append(std::to_string(nbofVertices - (i + 1)));
		line[nbofVertices - (i + 1)].append("= [  ");

		for (int j = (nbofVertices - (i + 1)); j > -1; j = Prev[j]) StackofPath[sptr++] = j;

		while (sptr) {
			line[nbofVertices - (i + 1)].append(std::to_string(StackofPath[--sptr]));
			line[nbofVertices - (i + 1)].append(" ");
		}
		line[nbofVertices - (i + 1)].append("] ");
		line[nbofVertices - (i + 1)].append(std::to_string(tmp1->getDistance()));
		line[nbofVertices - (i + 1)].append("\n");
		tmp1 = tmp1->next;
	}

	for (int i = 0; i < nbofVertices; i++)
	{
		Output << line[i];
	}
	Output.close();
	return true;

	delete[] line;
	delete[] StackofPath;
	delete[] Prev;
}
