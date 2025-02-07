#include "Player.h"
#include <iostream>
#define Infinity 10000000

bool Player::VerticalWin()
{
	int NbofRows, NbofColumns, DesiredScore;

	NbofRows = GS->Size;
	NbofColumns = GS->Size;
	DesiredScore = GS->Size;

	//Zwyci�stwo w poziomie
	int counter;

	counter = 0;
	for (int i = 0; i < NbofRows; i++)
	{
		if (GS->Space[0][i] == Tag)
		{
			for (int j = 0; j < NbofColumns; j++)
			{
				if (GS->Space[j][i] == Tag)
					counter++;
				else
					break;

			}
			if (counter == DesiredScore)
				return true;
			else
				counter = 0;

		}

	}

	return false;
}

bool Player::HorizontalWin()
{
	int NbofRows, NbofColumns, DesiredScore;

	NbofRows = GS->Size;
	NbofColumns = GS->Size;
	DesiredScore = GS->Size;

	//Zwyci�stwo w poziomie
	int  counter;

	counter = 0;
	for (int i = 0; i < NbofRows; i++)
	{
		if (GS->Space[i][0] == Tag)
		{
			for (int j = 0; j < NbofColumns; j++)
			{
				if (GS->Space[i][j] == Tag)
					counter++;
				else
					break;

			}
			if (counter == DesiredScore)
				return true;
			else
				counter = 0;
			
		}

	}

	return false;
}

bool Player::DiagonalWin()
{
	int Driver1,Driver2;				//one s�u�� do przemieszczania si� po kraw�dziach
	int counter=0;			//do sprawdzenia ilo�ci powt�rze� znaku - je�li tyle co rozmiar tablicy to wygrana
	int DesiredScore;

	DesiredScore = GS->Size;

	Driver1 = 0;

	if (GS->Space[0][0] == Tag) {					//musi by� w naro�niku, �eby w og�le zacz�� rozwa�a�
		while (Driver1 < GS->Size)
		{
			if (GS->Space[Driver1][Driver1] == Tag)
				counter++;
			else
				break;

			Driver1++;
		}
		if (counter == DesiredScore)
			return true;
		else
			counter = 0;
	}

	Driver1 = 0;
	Driver2 = GS->Size-1;
	

	if (GS->Space[Driver1][Driver2] == Tag) {					//musi by� w naro�niku, �eby w og�le zacz�� rozwa�a�
		while (Driver1<GS->Size)
		{
			if (GS->Space[Driver1][Driver2] == Tag)
				counter++;
			else
				break;

			Driver1++;
			Driver2--;
		}
		if (counter == DesiredScore)
			return true;
		else
			counter = 0;
	}





	return false;
}

bool Player::IsWinner()
{
	if (HorizontalWin() || VerticalWin() || DiagonalWin())
		return true;
	else
		return false;

}

int Player::CheckScore(Player Opponent)
{
	if (IsWinner())
		return 100;
	else if (Opponent.IsWinner())
		return -100;
	else
	return 0;
}

int Player::MiniMax(Player Opponent, int Row, int Column, int ReccursionDepth,
	int Alpha, int Beta, bool isMaximizingPlayer)
{
	int BestValue, Value, NbofRows, NbofColumns;
	
	NbofRows = GS->Size;
	NbofColumns = GS->Size;
	
	int Score = CheckScore(Opponent);

	if (GS->IsSpaceFull()||ReccursionDepth==0)	//koniec gry, remis
		return Score;


	if (Score == 100 || Score == -100)			//wygrana jednej ze stron
		return Score;


	if (isMaximizingPlayer)
	{
		BestValue = -Infinity;
		for (int i = 0; i <NbofRows ; i++)
		{
			for (int j = 0; j < NbofColumns; j++)
			{
				if (GS->IsPossibleMove(i,j))					//je�li miejsce nie jest ju� zaj�te
				{
					MakeMove(i, j);								//wykonuje ruch - wstawia krzy�yk
					Value = MiniMax(Opponent, i, j, ReccursionDepth -1,
						Alpha, Beta, false); //rekurencyjnie minimax - nastepny ruch ma minimizer
					Value = Value - ReccursionDepth;				//nasz AI szuka szybszej wygranej
					UndoMove(i, j);								//zwolnij zaj�te miejsce (nielegalnie)
					BestValue = std::max(BestValue, Value);		//lepsza warto�� to ta mniejsza
					Alpha = std::max(Alpha, BestValue);				//je�eli alpha znalaz�a lepsz� opcj�
					if (Beta <= Alpha)							//odci�cie ga��zi alpha
						break;
				}
			}
			if (Beta <= Alpha)							//to jest tak dla pewno�ci
				break;
		}
		return BestValue;
	}
	else
	{
		BestValue = Infinity;
		for (int i = 0; i < NbofRows; i++)
		{
			for (int j = 0; j < NbofColumns; j++)
			{
				if (GS->IsPossibleMove(i, j))			//je�li miejsce nie jest zaj�te
				{
					Opponent.MakeMove(i, j);						//ruch wykonany
					Value = MiniMax(Opponent, i, j, ReccursionDepth -1,
						Alpha, Beta, true);	//rekurencyjnie minimax - nast�pny ruch ma maximize
					Value = Value + ReccursionDepth;				//nasz AI szuka szybszej wygranej
																	//raczej b�dzie ogranicza� ilo�� rekursji
					Opponent.UndoMove(i, j);						//zwolnij zaj�te wcze�niej miejsce
					BestValue = std::min(BestValue, Value);	//lepsza warto�� to ta mniejsza
					Beta = std::min(Beta, BestValue);				//je�eli alpha znalaz�a lepsz� opcj�
					if (Beta <= Alpha)								//odci�cie ga��zi alpha
						break;
				}
			}
			if (Beta <= Alpha)							//to tak dla pewno�ci
				break;
		}
		return BestValue;
	}


}

int* Player::BestDecision(Player Opponent)
{
	int* Move= new int[2];
	int BestScore = -Infinity;			//najpierw inicjowane -niesko�czono��
	int NbofRows, NbofColumns, Value, RecursionDepth;
	NbofColumns = GS->Size;
	NbofRows = GS->Size;

	Move[0] = -10;				//nie ma wsp�rz�nych minusowych
	Move[1] = -10;
	

	if (GS->GetSize() <= 4)		//ustalanie g��boko�ci rekurencji
		RecursionDepth = 6;		//g��boko�c rekurencji na 6- 3x3 b�dzie wygrywa�, w 4x4 stara si� nie przegra�
	else
		RecursionDepth = 4;		//AI po prostu stara si� nie przegra� w krytycznych momentach

	for (int i = 0; i < NbofRows; i++)
	{
		for (int j = 0; j < NbofColumns; j++)
		{
			if (GS->IsPossibleMove(i,j))		//je�li pole jest puste
			{
				MakeMove(i, j);
				Value = MiniMax(Opponent, i, j, RecursionDepth,
					-Infinity, Infinity, false);	//przypisz warto�� rekurencyjnego wywo�ania
				UndoMove(i, j);								//zwolnij miejsce

				if (Value>BestScore)						//je�li znaleziono lepsz� opcj�
				{
					Move[0] = i;							//przypisz warto�ci wsp�rz�dnych
					Move[1] = j;
					BestScore = Value;						//zapami�taj warto�� lepszej opcji
				}
			}
		}
	}

	return Move;
}
