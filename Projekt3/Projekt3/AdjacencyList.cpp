#include "AdjacencyList.h"
#include <iostream>

Vertex* AdjacencyList::endVertices(Edge E)
{
	Vertex* ArrayofVertices[2];

	ArrayofVertices[0] = E.getSource();
	ArrayofVertices[1] = E.getTarget();

	return *ArrayofVertices;
}

Vertex* AdjacencyList::opposite(Vertex *V, Edge *E)
{

	if (V->getValue()==E->getSource()->getValue())
	{
		return E->getTarget();
	}
	else if (V->getValue() == E->getTarget()->getValue()) {
		return E->getSource();
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
	Edge* E2 = new Edge;
	E->setWeight(Weight);
	E->setSource(source);
	E->setTarget(target);

	E1->setWeight(Weight);
	E1->setSource(source);
	E1->setTarget(target);

	E2->setWeight(Weight);
	E2->setSource(source);
	E2->setTarget(target);

	int IndexOfVertexSource = source->getValue();
	int IndexOfVertexTarget = target->getValue();
	E->setNext(headEdge);
	E1->setNext(ListofEdges[IndexOfVertexSource]);
	E2->setNext(ListofEdges[IndexOfVertexTarget]);
	ListofEdges[IndexOfVertexSource]=E1;
	ListofEdges[IndexOfVertexTarget]=E2;
	headEdge = E;
	nbofEdges++;
}

Edge* AdjacencyList::incidentEdges(Vertex* V)
{
	int index = V->getValue();
	Edge* tmp = ListofEdges[index];

	return tmp;
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
