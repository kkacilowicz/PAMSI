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

int Player::MiniMax(Player Opponent, int Row, int Column, int Depth, bool isMaximizingPlayer)
{
	int BestValue, Value, NbofRows, NbofColumns;
	
	NbofRows = GS->Size;
	NbofColumns = GS->Size;
	
	int Score = CheckScore(Opponent);

	if (GS->IsSpaceFull())						//koniec gry, remis
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
					Value = MiniMax(Opponent, i, j, Depth + 1, false); //rekurencyjnie minimax - nastepny ruch ma minimizer
					UndoMove(i, j);								//zwolnij zajête miejsce (nielegalnie)
					BestValue = std::max(BestValue, Value);		//lepsza wartoœæ to ta mniejsza
				}
			}

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
					Value = MiniMax(Opponent, i, j, Depth + 1, true);	//rekurencyjnie minimax - nastêpny ruch ma maximize
					Opponent.UndoMove(i, j);						//zwolnij zajête wczeœniej miejsce
					BestValue = std::min(BestValue, Value);	//lepsza wartoœæ to ta mniejsza
				}
			}
		}
		return BestValue;
	}

}

int* Player::BestDecision(Player Opponent)
{
	int* Move= new int[2];
	int BestScore = -Infinity;
	int NbofRows, NbofColumns, Value;
	NbofColumns = GS->Size;
	NbofRows = GS->Size;

	Move[0] = -1;
	Move[1] = -1;
	

	for (int i = 0; i < NbofRows; i++)
	{
		for (int j = 0; j < NbofColumns; j++)
		{
			if (GS->IsPossibleMove(i,j))		//jeœli pole jest puste
			{
				MakeMove(i, j);
				Value = MiniMax(Opponent, i, j, 0, false);
				UndoMove(i, j);

				if (Value>BestScore)
				{
					Move[0] = i;
					Move[1] = j;
					BestScore = Value;
				}
			}
		}
	}

	std::cout << "Najlepsza decyzja wynosi " << BestScore <<std::endl;
	std::cout << "Wspó³rzêdne to " << Move[0] << Move[1] << std::endl;

	return Move;
}
