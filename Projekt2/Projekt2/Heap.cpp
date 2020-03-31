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

void Heap::display(int* data)
{
	int lvl = 1;

	for (int i = 1; i < size() + 1; i++)
	{
		std::cout << data[i] << " ";

		if (i == (pow(2, lvl) - 1))
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

void Heap::BuildHeap(int* data, int Size)
{
	int i = 1;
	while (i <= Size)
	{
		upheap(data, i);
		++i;
	}
}


int Heap::RemoveRoot()
{
	if (empty())
	{
		std::cout << "Kopiec pusty - nie mo¿na nic usunac" << std::endl;
	}
	else
	{
		int i = H[1];
		swap(&H[1], &H[size()]);
		size_counter--;
		MaxHeapify(1);
		return i;
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
		upheap(size());
	}
}

void Heap::upheap(int i)
{
	while (i>1 && H[Parent(i)]<H[i])
	{
		swap(&H[Parent(i)], &H[i]);
		i = Parent(i);
	}
}




void Heap::upheap(int tab[], int last)
{
	int i = last;
	if (i == 1)
		++i;
	while (i > 1)
	{
		if (tab[i] >= tab[Parent(i)])
			swap(&tab[i], &tab[Parent(i)]);
		i = Parent(i);
	}

}


void Heap::downheap(int tab[], int size, int i)
{
	int left = LeftSon(i);
	int right = RightSon(i);
	int largest;

	if (left <= size && tab[left] > tab[i])
		largest = left;
	else
		largest = i;

	if (right <= size && tab[right] > tab[largest])
		largest = right;

	if (largest != i && largest <= size)
	{
		swap(&tab[i], &tab[largest]);
		downheap(tab, size, largest);
	}

}


