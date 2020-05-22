#pragma once
#include"GameSpace.h";
class Player
{private:
	char Tag;			//znak okre�laj�cy jego znak - k�ko czy krzy�yk
	friend class GameSpace;
public:
	Player(char NewTag) {
		Tag = NewTag;
	}
	void MakeMove(GameSpace *GS, int Row, int Column) {GS->InsertElement(Tag, Row, Column);}	//wykonanie ruchu przez gracza
	int CheckScore(GameSpace *GS);						//funkcja heurystyczna badaj�ca wynik dzia�ania gracza(czy wygra�, przegra� itd)
};

