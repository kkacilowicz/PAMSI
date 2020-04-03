#pragma once
class Heap
{
private:
	int capacity;
	int *H;
	int size_counter;
public:
	Heap(int *A, int cap) {
		capacity = cap;								//cap oznacza n+1 wielkosc
													//capacity oznacza n
		H = new int[capacity];
		for (int i = 1; i < capacity; i++)
		{
			H[i] = A[i];
			
		}
		size_counter = capacity-1;
	}
	Heap(int cap) {
		H = 0;
		capacity = cap;
		size_counter = capacity;
	}
	~Heap() { delete[] H; }
	bool empty() { return size()==0; };
	int size() { return size_counter; } ;			//okreslanie wielkosci kopca
	int Parent(int i) { return i / 2; }				//zwraca rodzica elementu
	int LeftSon(int i) { return 2 * i; }			//zwraca lewego syna
	int RightSon(int i) { return (2 * i) + 1; }		//zwraca prawego syna
	void MaxHeapify(int i);							//przywracanie wlasnosci kopca
	void display();									//czytelne wyswietlenie kopca
	void display(int* data);						//wyswietlenie tablicy jako kopiec
	void BuildHeap();								//budowanie kopca
	void BuildHeap(int* data, int Size);			//budowanie kopca z zadanej tablicy i rozmiaru
	int RemoveRoot();								//usun korzen z kopca
	void AddElement(int Element);					//dodaj element do kopca
	void upheap(int i);								//przywracanie wlasnosci kopca w gore
	void upheap(int *data, int last);				//przywracanie wlasnosci kopca w gore
	void downheap(int *data, int size, int i);		//przywracanie wlasnosci kopca w dol
};

