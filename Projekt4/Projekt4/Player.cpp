#include "Player.h"
#include <iostream>


int Player::CheckScore(GameSpace *GS)
{
	int NbofRows, NbofColumns,DesiredScore;

	NbofRows = GS->Size;
	NbofColumns = GS->Size;
	DesiredScore = GS->Size;

//Zwyciêstwo w poziomie
	int j, counter;
	
	for (int i = 0; i < NbofRows; i++)
	{
		j = 0;
		counter = 0;
		while (j < NbofColumns+1)
		{
			j++;
			if ((GS->Space[i][j - 1] == GS->Space[i][j])&& (GS->Space[i][j - 1]=Tag))
				counter++;
			else
				j = NbofColumns;		//warunek, ¿eby zakoñczyæ while
		}
		if (counter == DesiredScore)
			return 10;
	}

	return 0;
}
