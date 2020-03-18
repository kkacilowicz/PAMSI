#include "Heap.h"
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

void Heap::MaxHeapify(int i)
{
	int largest;
	int l = LeftSon(i);
	int r = RightSon(i);
	if (l<=size() && H[l]>H[i] )
		 largest = l;
	else
		 largest = i;
	if (r <= size() && H[r] > H[largest])
		largest = r;
	if (largest != i) {
		swap(&H[i], &H[largest]);
		MaxHeapify(largest);
	}
	
}

void Heap::display()
{
	int lvl=1;

	for  (int i = 1; i < size()+1; i++)
	{
		std::cout << H[i] << " ";

		if (i==(pow(2,lvl)-1))
		{
			std::cout << std::endl;
			lvl++;
		}
	}
}

void Heap::BuildHeap()
{
	int v = capacity; 
	while (v) {
		MaxHeapify(v);
		v = v--;
	}
}

void Heap::RemoveRoot()
{
	if (empty())
	{
		std::cout << "Kopiec pusty - nie mo¿na nic usunac" << std::endl;
	}
	else
	{
		swap(&H[1], &H[size()]);
		size_counter--;
		MaxHeapify(1);
	}
}

void Heap::AddElement(int Element)
{
	if (size()==capacity)
	{
		std::cout << "Kopiec pelen - nie mozna nic dodac" << std::endl;
	}
	else
	{
		size_counter++;
		H[size()] = Element;
		uppheap(size());
	}
}

void Heap::uppheap(int i)
{
	while (i>1 && H[Parent(i)]<H[i])
	{
		swap(&H[Parent(i)], &H[i]);
		i = Parent(i);
	}
}



