#include "AdjacencyMatrix.h"
#include <iostream>

Vertex* AdjacencyMatrix::endVertices(Edge E)
{

	Vertex* ArrayofVertices[2];

	ArrayofVertices[0] = E.getSource();
	ArrayofVertices[1] = E.getTarget();

	return *ArrayofVertices;
}

Vertex* AdjacencyMatrix::opposite(Vertex* V, Edge* E)
{
	if (V->getValue() == E->getSource()->getValue())
	{
		return E->getTarget();
	}
	else if (V->getValue() == E->getTarget()->getValue()) {
		return E->getSource();
	}
}

bool AdjacencyMatrix::areAdjacent(Vertex* V, Vertex* W)
{
	int index1, index2; 
	index1 = V->getValue();
	index2 = W->getValue();

	if (MatrixEdge[index1][index2] != NULL)
		return true;
	else
		return false;



}

Vertex* AdjacencyMatrix::insertVertex(int value)
{

	if (headVertex == NULL) {
		Vertex* V = new Vertex;
		V->setValue(value);
		V->setNext(headVertex);
		headVertex = V;
	}
	else if (headVertex->getValue() != value)
	{
		Vertex* V = new Vertex;
		V->setValue(value);
		V->setNext(headVertex);
		headVertex = V;
	}

	return headVertex;
}

void AdjacencyMatrix::insertEdge(Vertex* source, Vertex* target, int Weight)
{
	Edge* E = new Edge;
	E->setWeight(Weight);
	E->setSource(source);
	E->setTarget(target);

	int IndexOfVertexSource = source->getValue();
	int IndexOfVertexTarget = target->getValue();
	E->setNext(headEdge);
	MatrixEdge[IndexOfVertexSource][IndexOfVertexTarget] = E;
	MatrixEdge[IndexOfVertexTarget][IndexOfVertexSource] = E;
	headEdge = E;
	nbofEdges++;
}

Edge* AdjacencyMatrix::incidentEdges(Vertex* V)
{
	int value = V->getValue();
	Edge* head = NULL;
	std::cout << "Krawedzie:" << std::endl;

	for (int j = 0; j < nbofVertices; j++)
	{

		if (MatrixEdge[value][j] != NULL)
		{
			MatrixEdge[value][j]->setNext(head);
			head = MatrixEdge[value][j];
		}

	}
	return head;
}

void AdjacencyMatrix::displayVertices()
{
	Vertex* tmp = headVertex;
	std::cout << "Wierzcholki: " << std::endl;
	while (tmp)
	{
		std::cout << tmp->getValue() << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;

}

void AdjacencyMatrix::displayEdges()
{
	Edge* tmp = headEdge;
	std::cout << "Krawedzie:" << std::endl;

	while (tmp)
	{
		std::cout << "Source " << tmp->getSource()->getValue() << "Target " << tmp->getTarget()->getValue()
			<< "Weight " << tmp->getWeight() << std::endl;
		tmp = tmp->next;
	}

}

void AdjacencyMatrix::displayIncidentEdges(int value)
{
	Edge* head = NULL;
	std::cout << "Krawedzie:" << std::endl;

	for (int j = 0; j < nbofVertices; j++)
	{

		if (MatrixEdge[value][j]!=NULL)
		{
			MatrixEdge[value][j]->setNext(head);
			head = MatrixEdge[value][j];
		}

	}
	
	while (head)
	{
		std::cout << "Source " << head->getSource()->getValue() << "Target " << head->getTarget()->getValue()
			<< "Weight " << head->getWeight() << std::endl;
		head = head->next;
	}


}
