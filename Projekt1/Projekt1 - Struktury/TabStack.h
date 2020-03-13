#pragma once
class TabStack
{
private:
	int capacity;							//poczatkowa maksymalna ilosc elementow na stosie (pojemnosc)
	int* S;									//do realizacji algorytmu stosu
	int top;								//zawiera dostep do elementu na szczycie stosu
public:
	TabStack(int cap) {						//konstruktor, przyjmuje warto�� wielko�ci stosu
		capacity = cap;
		S = new int[capacity];
		top = -1;
	}
	~TabStack() { delete []S; }
	bool isEmpty()	{ return top < 0; }		//sprawdza czy stos jest pusty
	int pop();								//usuwa element ze szczytu stosu
	void push(int e);						//dodaje element na szczyt stosu
	int size() {return top + 1;}			//wy�wietla ilo�� element�w na stosie
	void display();							//wy�wietla wszystkie elementy stosu
	int onTop() { return S[top]; }			//zwraca warto�� na szczycie stosu
};

