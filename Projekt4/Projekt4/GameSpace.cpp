#include "GameSpace.h"
#include <iostream>

bool GameSpace::IsSpaceFull()
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			if (Space[i][j] == ' ')
				return false;
		}
	}
	return true;
}

bool GameSpace::IsPossibleMove(int Row, int Column)
{
	if (Space[Row][Column] == 'X' || Space[Row][Column] == 'O')
		return false;
	else
		return true;
}

void GameSpace::InsertElement(char Element, int Row, int Column)
{
	if (IsPossibleMove(Row, Column))
		Space[Row][Column] = Element;
	else
		std::cout << "To miejsce nie jest wolne, wybierz inne" << std::endl;
	
}

void GameSpace::ClearSpace()
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			Space[i][j] = ' ';
		}
	}
}

void GameSpace::display()
{
	for (int i = 0; i < Size; i++)
	{
		std::cout << "| ";
		for (int j = 0; j < Size; j++)
		{
			std::cout << Space[i][j] << " | ";
		}
		std::cout << std::endl;
	}
}
