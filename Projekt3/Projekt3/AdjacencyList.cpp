#include "AdjacencyList.h"
#include <iostream>
#include <queue>
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

	std::queue<int>* st = new std::queue<int>[nbofVertices];

	
	int infinity = INT_MAX;
	for (int i = 0; i < nbofVertices; i++)
	{
		st[i].push(startVertex);					//nieznany jest koszt dojœcia do ka¿dego wierzcho³ka
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
				st[Z->getValue()].push(V->getValue());
			}
			PQ.BuildHeapVertices();
			E = E->next;										//sprawdŸ nastêpn¹ krawêdŸ
		}
	}

	Vertex* tmp1 = headVertex;
	while (tmp1)
	{
		std::cout << tmp1->getValue() << " = [ ";

		
		while (st[tmp1->getValue()].size()!=0)
		{
			std::cout << st[tmp1->getValue()].front() << " ";
			st[tmp1->getValue()].pop();
		}
		
		
		std::cout << "] " << tmp1->getDistance() << std::endl;
		tmp1 = tmp1->next;
	}
	

	delete[] st;
}
