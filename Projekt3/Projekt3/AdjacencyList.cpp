#include "AdjacencyList.h"

Vertex* AdjacencyList::endVertices(Edge E)
{
	Vertex* ArrayofVertices[2];

	ArrayofVertices[0] = E.getSource();
	ArrayofVertices[1] = E.getTarget();

	return *ArrayofVertices;
}

Vertex* AdjacencyList::opposite(Vertex V, Edge E)
{

	if (V.getValue()==E.getSource()->getValue())
	{
		return E.getTarget();
	}
	else if (V.getValue() == E.getTarget()->getValue()) {
		return E.getSource();
	}
}
