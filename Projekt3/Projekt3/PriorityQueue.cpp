#include "PriorityQueue.h"
#include <iostream>


void PriorityQueue::swapVertices(int value1, int value2)
{
	Vertex* tmp = TabVertex[value1];
	TabVertex[value1] = TabVertex[value2];
	TabVertex[value2] = tmp;
}

void PriorityQueue::MinHeapifyVertices(int i)
{

	int smallest;
	int l = LeftSon(i);
	int r = RightSon(i);
	if (l <= size() && TabVertex[l]->getDistance() < TabVertex[i]->getDistance())
		smallest = l;
	else
		smallest = i;
	if (r <= size() && TabVertex[r]->getDistance() < TabVertex[smallest]->getDistance())
		smallest = r;
	if (smallest != i) {
		swapVertices(i, smallest);
		MinHeapifyVertices(smallest);
	}

}


void PriorityQueue::displayVertices()
{
	int lvl = 1;

	for (int i = 1; i < size() + 1; i++)
	{
		std::cout << TabVertex[i]->getValue() << " (" << TabVertex[i]->getDistance() << ") ";

		if (i == (pow(2, lvl) - 1))
		{
			std::cout << std::endl;
			lvl++;
		}
	}
	std::cout << std::endl;
}
 
void PriorityQueue::BuildHeapVertices()
{
	int v = capacity;
	while (v) {
		MinHeapifyVertices(v);
		v = v--;
	}
}

Vertex* PriorityQueue::RemoveMinVertex()
{
	Vertex* tmp = TabVertex[1];
	swapVertices(1, size());
	size_counter--;
	MinHeapifyVertices(1);

	return tmp;
}




