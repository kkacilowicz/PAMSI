#pragma once
#include"GameSpace.h"
#include<algorithm>
class Player
{private:
	char Tag;			//znak okreœlaj¹cy jego znak - kó³ko czy krzy¿yk
	GameSpace* GS;		//plansza na której gra gracz
	friend class GameSpace;
public:
	Player(char NewTag, GameSpace* NewGameSpace) {
		GS = NewGameSpace;
		Tag = NewTag;
	}
	void MakeMove(int Row, int Column) {GS->InsertElement(Tag, Row, Column);}	//wykonanie ruchu przez gracza
	void UndoMove(int Row, int Column) { GS->Space[Row][Column] = ' '; }	//cofniêcie ruchu
	bool VerticalWin();						//sprawdzenie zwyciêstwa pionowego
	bool HorizontalWin();					//sprawdzenie zwyciêstwa poziomego
	bool DiagonalWin();						//sprawdzenie zwyciêstwa diagonalnego (po przek¹tnych)
	bool IsWinner();						//ogólny bool, czy wygrana
	int CheckScore(Player Opponent);		//funkcja heurystyczna badaj¹ca wynik dzia³ania gracza(czy wygra³, przegra³ itd)
	int MiniMax(Player Opponent, int Row, int Column, int RecurenceDepth, int Alpha, int Beta, bool isMaximizer);	//minimax
	int* BestDecision(Player Opponent);		//podejmowanie decyzji najlepszej i wyznaczanie ruchu dla AI
};

