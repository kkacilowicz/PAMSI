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
        getline(plik, nazwa, ' ');
       // cout << nazwa << endl;

        
        for (int i = 0; i < 3; i++)
        {
            getline(plik, dane, ' ');
            boki[i] = atof(dane.c_str()); 
           // cout << boki[i] << " ";
            cout << dane << " ";
        }
        Tr.a = boki[0];
        Tr.b = boki[1];
        Tr.c = boki[2];

       // cout << Tr.Obwod(Tr) << endl;
       // cout << dane << endl;
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
