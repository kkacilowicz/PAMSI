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
		Vertex* tmp = headVertex;
		while (tmp)
		{
			if (tmp->getValue() == value)
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
	headEdge = E;
	nbofEdges++;
}

Edge* AdjacencyMatrix::incidentEdges(Vertex* V)
{
	int value = V->getValue();
	Edge* head = NULL;

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

void AdjacencyMatrix::DijkstraDistances(int startVertex)
{
	int* path = new int[nbofVertices];					//ta tablica opisuje œcie¿kê do wybranego wierzcho³ka
	int* buf = new int[nbofVertices];					//przechowuje wartosc kosztów dojœcia do wierzcho³ka

	int infinity = INT_MAX;
	for (int i = 0; i < nbofVertices; i++)
	{
		path[i] = -1;						//¿aden wierzcho³ek nie ma wartoœci -1
		buf[i] = 0;							//nieznany jest koszt dojœcia do ka¿dego wierzcho³ka
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
	
	
	while (!PQ.empty())
	{
		Vertex* V = PQ.RemoveMinVertex();
		Edge* E = incidentEdges(V);
		while (E)
		{
			Vertex* Z = opposite(V, E);						
			int route;
			route = V->getDistance() + E->getWeight();
			if (route < Z->getDistance()) {
				Z->setDistance(route);
				path[Z->getValue()] = V->getValue();
			}
			PQ.BuildHeapVertices();
			E = E->next;
		}
	}
	Vertex* tmp1 = headVertex;
	while (tmp1)
	{
		std::cout << tmp1->getValue() << " = [ ";

		int k = tmp1->getValue();
		int i = 0;
		while (k)
		{
			buf[i] = path[k];
			k = path[k];
			i++;
		}
		while (i!=0)
		{
			std::cout << buf[--i] << " ";
		}

	    std::cout <<"] $ " << tmp1->getDistance() << std::endl;
		tmp1=tmp1->next;
	}
	//delete[] path;
	//delete[] buf;
}
