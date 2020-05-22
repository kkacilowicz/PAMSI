// Projekt4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include<vector>
#include"GameSpace.h"
#include"Player.h"

int main()
{

    
    GameSpace* GS = new GameSpace(3);
    Player Player1('X',GS);
    Player Opponent('O', GS);
    int check,x,y;
    int* AIMove;


    //Opponent to ja
    //Player1 to komputer

    GS->display();

    while (1)
    {
        
        std::cout << std::endl;
        std::cin >> x >> y;
        Player1.MakeMove(x, y);
        AIMove = Opponent.BestDecision(Player1);
        Opponent.MakeMove(AIMove[0], AIMove[1]);
        GS->display();


        if (GS->IsSpaceFull()||Opponent.IsWinner()||Player1.IsWinner())
        {
            std::cout << Player1.CheckScore(Opponent) << std::endl;
            return 0;
        }
    }



    delete GS;
    

}

