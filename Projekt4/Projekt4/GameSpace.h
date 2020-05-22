#pragma once
#include<vector>
class GameSpace
{
private:
	char** Space;			//plansza do gry
	int Size;				//rozmiar symetrycznej planszy do gry
	friend class Player;
public:
	GameSpace(int NewSize) {
		
		Space = new char* [NewSize];
		for (int i = 0; i < NewSize; i++)
		{
			Space[i] = new char[NewSize];
			for (int j = 0; j < NewSize; j++)
			{
				Space[i][j] = ' ';
			}
		}
		Size = NewSize;
	}
	~GameSpace() {
		for (int i = 0; i < Size; i++)
		{
			delete Space[i];
		}
		delete[] Space;
	}
	bool IsSpaceFull();		//czy jest mo¿liwe jeszcze wykonanie jakiegoœ ruchu
	bool IsPossibleMove(int Row, int Column);	//czy jest mo¿liwe wykonanie zadanego ruchu
	void InsertElement(char Element, int Row, int Column);	//dodanie elementu na planszê
	void ClearSpace();		//czyœci planszê
	void display();			//wyœwietlanie
};

