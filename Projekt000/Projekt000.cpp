// Projekt000.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Trojkat.h"
using namespace std;

int main()
{
    fstream plik;               //plik z ktorego wczytujemy
    Trojkat Tr;                 //trojkat
    string dane, nazwa;         //dane wczytywane do strumienia
    double boki[3];             // do obliczenia obwodu i zapisania w klasie
    double obwod;               // zapis wartosci obwodu danego trojkata


    plik.open("trojkaty1.txt", ios::in);
    if (plik.good() == false) { cout << "Nie wczytano"; }
   

    while (!plik.eof())
    {
        while (plik >> nazwa >> Tr.a >> Tr.b >>Tr.c)
        {
            cout << "Trojkat " << nazwa << " " << Tr.Obwod(Tr) << endl;
        }
    }
    plik.close();

    }

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
