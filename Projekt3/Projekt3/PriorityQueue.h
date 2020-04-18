#pragma once
class PriorityQueue
{
private:
	int capacity;
	int* H;
	int size_counter;
public:
	PriorityQueue(int* A, int cap) {
		capacity = cap;								//cap oznacza n+1 wielkosc
													//capacity oznacza n
		H = new int[capacity];
		for (int i = 1; i < capacity; i++)
		{
			H[i] = A[i];

		}
		size_counter = capacity - 1;
	}
	~PriorityQueue() { delete[] H; }
	bool empty() { return size() == 0; };			//czy jest pusty
	int size() { return size_counter; };			//okreslanie wielkosci kopca
	int Parent(int i) { return i / 2; }				//zwraca rodzica elementu
	int LeftSon(int i) { return 2 * i; }			//zwraca lewego syna
	int RightSon(int i) { return (2 * i) + 1; }		//zwraca prawego syna
	void MinHeapify(int i);							//przywracanie wartoœci kopca typu min
	void display();									//czytelne wyswietlenie kopca
	void BuildHeap();								//budowanie kopca
	int RemoveMin();								//usun wartoœæ najmniejsz¹ z kopca
	void AddElement(int Element);					//dodaj element do kopca
	void upheap(int i);								//przywracanie wlasnosci kopca w gore
};



