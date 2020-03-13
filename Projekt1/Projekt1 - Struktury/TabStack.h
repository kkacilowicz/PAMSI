#pragma once
class TabStack
{
private:
	int capacity;							//poczatkowa maksymalna ilosc elementow na stosie (pojemnosc)
	int* S;									//do realizacji algorytmu stosu
	int top;								//zawiera dostep do elementu na szczycie stosu
public:
	TabStack(int cap) {						//konstruktor, przyjmuje wartoœæ wielkoœci stosu
		capacity = cap;
		S = new int[capacity];
		top = -1;
	}
	~TabStack() { delete []S; }
	bool isEmpty()	{ return top < 0; }		//sprawdza czy stos jest pusty
	int pop();								//usuwa element ze szczytu stosu
	void push(int e);						//dodaje element na szczyt stosu
	int size() {return top + 1;}			//wyœwietla iloœæ elementów na stosie
	void display();							//wyœwietla wszystkie elementy stosu
	int onTop() { return S[top]; }			//zwraca wartoœæ na szczycie stosu
};

