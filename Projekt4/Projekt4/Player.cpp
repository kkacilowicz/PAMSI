#include "Player.h"
#include <iostream>
#define Infinity 10000000

bool Player::VerticalWin()
{
	int NbofRows, NbofColumns, DesiredScore;

	NbofRows = GS->Size;
	NbofColumns = GS->Size;
	DesiredScore = GS->Size;

	//Zwyciêstwo w poziomie
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

	//Zwyciêstwo w poziomie
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
	int Driver1,Driver2;				//one s³u¿¹ do przemieszczania siê po krawêdziach
	int counter=0;			//do sprawdzenia iloœci powtórzeñ znaku - jeœli tyle co rozmiar tablicy to wygrana
	int DesiredScore;

	DesiredScore = GS->Size;

	Driver1 = 0;

	if (GS->Space[0][0] == Tag) {					//musi byæ w naro¿niku, ¿eby w ogóle zacz¹æ rozwa¿aæ
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
	

	if (GS->Space[Driver1][Driver2] == Tag) {					//musi byæ w naro¿niku, ¿eby w ogóle zacz¹æ rozwa¿aæ
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
				if (GS->IsPossibleMove(i,j))					//jeœli miejsce nie jest ju¿ zajête
				{
					MakeMove(i, j);								//wykonuje ruch - wstawia krzy¿yk
					Value = MiniMax(Opponent, i, j, ReccursionDepth -1,
						Alpha, Beta, false); //rekurencyjnie minimax - nastepny ruch ma minimizer
					Value = Value - ReccursionDepth;				//nasz AI szuka szybszej wygranej
					UndoMove(i, j);								//zwolnij zajête miejsce (nielegalnie)
					BestValue = std::max(BestValue, Value);		//lepsza wartoœæ to ta mniejsza
					Alpha = std::max(Alpha, BestValue);				//je¿eli alpha znalaz³a lepsz¹ opcjê
					if (Beta <= Alpha)							//odciêcie ga³êzi alpha
						break;
				}
			}
			if (Beta <= Alpha)							//to jest tak dla pewnoœci
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
				if (GS->IsPossibleMove(i, j))			//jeœli miejsce nie jest zajête
				{
					Opponent.MakeMove(i, j);						//ruch wykonany
					Value = MiniMax(Opponent, i, j, ReccursionDepth -1,
						Alpha, Beta, true);	//rekurencyjnie minimax - nastêpny ruch ma maximize
					Value = Value + ReccursionDepth;				//nasz AI szuka szybszej wygranej
																	//raczej bêdzie ogranicza³ iloœæ rekursji
					Opponent.UndoMove(i, j);						//zwolnij zajête wczeœniej miejsce
					BestValue = std::min(BestValue, Value);	//lepsza wartoœæ to ta mniejsza
					Beta = std::min(Beta, BestValue);				//je¿eli alpha znalaz³a lepsz¹ opcjê
					if (Beta <= Alpha)								//odciêcie ga³êzi alpha
						break;
				}
			}
			if (Beta <= Alpha)							//to tak dla pewnoœci
				break;
		}
		return BestValue;
	}


}

int* Player::BestDecision(Player Opponent)
{
	int* Move= new int[2];
	int BestScore = -Infinity;			//najpierw inicjowane -nieskoñczonoœæ
	int NbofRows, NbofColumns, Value, RecursionDepth;
	NbofColumns = GS->Size;
	NbofRows = GS->Size;

	Move[0] = -10;				//nie ma wspó³rzênych minusowych
	Move[1] = -10;
	

	if (GS->GetSize() <= 4)		//ustalanie g³êbokoœci rekurencji
		RecursionDepth = 6;		//g³êbokoœc rekurencji na 6- 3x3 bêdzie wygrywa³, w 4x4 stara siê nie przegraæ
	else
		RecursionDepth = 4;		//AI po prostu stara siê nie przegraæ w krytycznych momentach

	for (int i = 0; i < NbofRows; i++)
	{
		for (int j = 0; j < NbofColumns; j++)
		{
			if (GS->IsPossibleMove(i,j))		//jeœli pole jest puste
			{
				MakeMove(i, j);
				Value = MiniMax(Opponent, i, j, RecursionDepth,
					-Infinity, Infinity, false);	//przypisz wartoœæ rekurencyjnego wywo³ania
				UndoMove(i, j);								//zwolnij miejsce

				if (Value>BestScore)						//jeœli znaleziono lepsz¹ opcjê
				{
					Move[0] = i;							//przypisz wartoœci wspó³rzêdnych
					Move[1] = j;
					BestScore = Value;						//zapamiêtaj wartoœæ lepszej opcji
				}
			}
		}
	}

	return Move;
}
