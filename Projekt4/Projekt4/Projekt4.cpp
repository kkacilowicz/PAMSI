// Projekt4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include"GameSpace.h"
#include"Player.h"

bool EndGame(GameSpace* GS, Player Player1, Player Opponent)
{
    
    if (Player1.IsWinner())
    {
        std::cout << "Gratulacje! Gracz wygral :)" << std::endl;
        return true;
    }
    else if (Opponent.IsWinner())
    {
        std::cout << "Niestety! Porazka :(" << std::endl;
        return true;
    }
    else if (GS->IsSpaceFull())
    {
        std::cout << "Remis" << std::endl;
        return true;
    }

    return false;

}

bool OutOfRangeException(GameSpace* GS, int Row, int Column) {

    if (Row < 0 || Column < 0)
        return true;

    if (Row>(GS->GetSize()-1)||Column>(GS->GetSize()-1))
        return true;
   
    return false;
}

int main()
{
    int SizeOfGameSpace, x, y;
    int* AIMove;

    std::cout << "Podaj rozmiar planszy:" << std::endl;
    std::cin >> SizeOfGameSpace;

    GameSpace* GS = new GameSpace(SizeOfGameSpace);
    Player Player1('X',GS);
    Player Opponent('O', GS);

    GS->display();

    while (1)
    {
        std::cout << "Wykonaj ruch podajac wspolrzedne x y" << std::endl;
        std::cout << std::endl;
        std::cin >> x >> y;
        
        while (OutOfRangeException(GS, x, y))    //jeśli gracz chce wybrać pole już zajęte
        {
            std::cout << "Chcesz wybrac pole poza plansza" << std::endl;
            std::cout << "Sprobouj ponownie" << std::endl;
            std::cin >> x >> y;
        }
        while (!GS->IsPossibleMove(x, y))    //jeśli gracz chce wybrać pole już zajęte
        {
            std::cout << "To pole jest zajete, wybierz inne" << std::endl;
            std::cout << "Sprobouj ponownie" << std::endl;
            std::cin >> x >> y;
            while (OutOfRangeException(GS, x, y))    //jeśli gracz chce wybrać pole już zajęte
            {
                std::cout << "Chcesz wybrac pole poza plansza" << std::endl;
                std::cout << "Sprobouj ponownie" << std::endl;
                std::cin >> x >> y;
            }
        }
        
        Player1.MakeMove(x, y);

        if (EndGame(GS, Player1, Opponent))
            return 0;

        AIMove = Opponent.BestDecision(Player1);
        Opponent.MakeMove(AIMove[0], AIMove[1]);
        GS->display();


        if (EndGame(GS, Player1, Opponent))
            return 0;
    }

    delete GS;
   
}

