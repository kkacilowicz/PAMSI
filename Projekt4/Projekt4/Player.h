#pragma once
#include"GameSpace.h";
class Player
{private:
	char Tag;			//znak okreœlaj¹cy jego znak - kó³ko czy krzy¿yk
	friend class GameSpace;
public:
	Player(char NewTag) {
		Tag = NewTag;
	}
	void MakeMove(GameSpace *GS, int Row, int Column) {GS->InsertElement(Tag, Row, Column);}	//wykonanie ruchu przez gracza
	int CheckScore(GameSpace *GS);						//funkcja heurystyczna badaj¹ca wynik dzia³ania gracza(czy wygra³, przegra³ itd)
};

