#include "PriorityQueue.h"
#include <iostream>

void swap(int* x, int* y) {

	int tmp = *x;
	*x = *y;
	*y = tmp;

}

void swap(int x, int y) {

	int tmp = x;
	x = y;
	y = tmp;

}



void PriorityQueue::MinHeapify(int i)
{
	int smallest;
	int l = LeftSon(i);
	int r = RightSon(i);
	if (l <= size() && H[l] < H[i])
		smallest = l;
	else
		smallest = i;
	if (r <= size() && H[r] < H[smallest])
		smallest = r;
	if (smallest != i) {
		swap(&H[i], &H[smallest]);
		MinHeapify(smallest);
	}

}



void PriorityQueue::display()
{
	int lvl = 1;

	for (int i = 1; i < size() + 1; i++)
	{
		std::cout << H[i] << " ";

		if (i == (pow(2, lvl) - 1))
		{
			std::cout << std::endl;
			lvl++;
		}
	}
}


void PriorityQueue::BuildHeap()
{
	int v = capacity;
	while (v) {
		MinHeapify(v);
		v = v--;
	}
}



int PriorityQueue::RemoveMin()
{
	if (empty())
	{
		std::cout << "Kopiec pusty - nie mo¿na nic usunac" << std::endl;
		return 0;
	}
	else
	{
		int i = H[1];
		swap(&H[1], &H[size()]);
		size_counter--;
		MinHeapify(1);
		return i;
	}
}



void PriorityQueue::AddElement(int Element)
{
	if (size() == capacity)
	{
		std::cout << "Kopiec pelen - nie mozna nic dodac" << std::endl;
	}
	else
	{
		size_counter++;
		H[size()] = Element;
		upheap(size());
	}
}

void PriorityQueue::upheap(int i)
{
	while (i > 1 && H[Parent(i)] > H[i])
	{
		swap(&H[Parent(i)], &H[i]);
		i = Parent(i);
	}
}




