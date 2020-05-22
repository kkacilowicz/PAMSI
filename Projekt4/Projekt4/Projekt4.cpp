// Projekt4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include<vector>
#include"GameSpace.h"
#include"Player.h"

int main()
{

    
    GameSpace* GS = new GameSpace(3);
    Player P('X');
    int check;


    GS->display();
    std::cout << std::endl;
    P.MakeMove(GS, 0, 0);
    P.MakeMove(GS, 0, 1);
    P.MakeMove(GS, 0, 2);
    GS->display();
   
   //check= P.CheckScore(GS);

   //std::cout << check << std::endl;



    delete GS;
    

}

