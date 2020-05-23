#pragma once
#include"GameSpace.h"
#include<algorithm>
class Player
{private:
	char Tag;			//znak okre�laj�cy jego znak - k�ko czy krzy�yk
	GameSpace* GS;		//plansza na kt�rej gra gracz
	friend class GameSpace;
public:
	Player(char NewTag, GameSpace* NewGameSpace) {
		GS = NewGameSpace;
		Tag = NewTag;
	}
	void MakeMove(int Row, int Column) {GS->InsertElement(Tag, Row, Column);}	//wykonanie ruchu przez gracza
	void UndoMove(int Row, int Column) { GS->Space[Row][Column] = ' '; }	//cofni�cie ruchu
	bool VerticalWin();						//sprawdzenie zwyci�stwa pionowego
	bool HorizontalWin();					//sprawdzenie zwyci�stwa poziomego
	bool DiagonalWin();						//sprawdzenie zwyci�stwa diagonalnego (po przek�tnych)
	bool IsWinner();						//og�lny bool, czy wygrana
	int CheckScore(Player Opponent);		//funkcja heurystyczna badaj�ca wynik dzia�ania gracza(czy wygra�, przegra� itd)
	int MiniMax(Player Opponent, int Row, int Column, int RecurenceDepth, int Alpha, int Beta, bool isMaximizer);	//minimax
	int* BestDecision(Player Opponent);		//podejmowanie decyzji najlepszej i wyznaczanie ruchu dla AI
};

