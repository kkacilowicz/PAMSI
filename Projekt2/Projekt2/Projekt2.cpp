// Projekt2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <chrono>
#include <ctime>
#include "SLinkedList.h"
#include "Heap.h"

using namespace std;

int main()
{

    srand((unsigned)time(0));               //tworzenie wartosci losowych


    int SIZE = 10000;
    int Random_Element;

    SLinkedList SLL, S1, S2;



    for (int i = 0; i < SIZE; i++)
    {
        Random_Element = rand();
        SLL.addFront(Random_Element);
    }




    chrono::steady_clock sc;   // create an object of `steady_clock` class
    auto start = sc.now();     // start timer

 
    SLL.mergesort();

    auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
    auto time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
    cout << "Operation took: " << time_span.count() << " seconds !!!" << endl;;
   
    

    

}

