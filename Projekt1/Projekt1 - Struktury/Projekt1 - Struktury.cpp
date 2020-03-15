// Projekt1 - Struktury.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include"TabStack.h"
#include"TabQueue.h"
using namespace std;

//Wyswietlanie menu stosu
void Menu_Stack() {

    cout << "Menu" << endl;
    cout << "a - Dodanie na stos zadanego elementu" << endl;
    cout << "b - Usun element ze szczytu stosu" << endl;
    cout << "c - Wyswietl element ze szczytu stosu" << endl;
    cout << "d - Sprawdz czy stos jest pusty" << endl;
    cout << "e - Wyswietl liczbe elementow w stosie" << endl;
    cout << "f - Zakoncz" << endl;
}

//Wyswietlanie menu struktur
void Menu_Structures() {
    cout << "Menu" << endl;
    cout << "1 - Stos" << endl;
    cout << "2 - Kolejka" << endl;
    cout << "3 - Lista" << endl;
    cout << "4 - Zakoncz" << endl;
}

//Wyswietlanie menu kolejki
void Menu_Queue() {

    cout << "Menu" << endl;
    cout << "a - Dodanie na koniec kolejki elementu" << endl;
    cout << "b - Usun element z poczatku kolejki" << endl;
    cout << "c - Sprawdz czy kolejka jest pusta" << endl;
    cout << "d - Wyswietl pierwszy element" << endl;
    cout << "e - Wyswietl liczbe elementow kolejki" << endl;
    cout << "f - Zakoncz" << endl;

}


int main()
{
    TabStack TabSt(5);
    TabQueue TabQu(5);
    
    char Choice_struct, Choice_function;    //podejmowane decyzje od uzytkownika
    int Element;                            //Element dodawany do struktury

    Menu_Structures();
     cout << "Twoj wybor:" << endl;
     cin >> Choice_struct;
    
    if (Choice_struct == '1') {

        while (1) {


            Menu_Stack();
            cout << "Twoj wybor:" << endl;
            cin >> Choice_function;
            switch (Choice_function)
            {
            case 'a':

                cout << "Jaki element chcesz dodac?" << endl;
                cin >> Element;
                TabSt.push(Element);
                cout << "Dodano do stosu liczbe " << Element << endl;
                break;

            case 'b':
                if (!TabSt.isEmpty()) {
                    cout << "Usunieto ze stosu liczbe " << TabSt.onTop() << endl;
                    TabSt.pop();
                }
                else
                    cout << "Stos jest pusty - brak elementu do wyświetlenia" << endl;
                break;
            case 'c':
                if (!TabSt.isEmpty())
                    cout << "Na szczycie stosu znajduje sie elementow: " << TabSt.onTop() << endl;
                else
                    cout << "Stos jest pusty - brak elementu do wyswietlenia" << endl;
                break;
            case 'd':
                if (!TabSt.isEmpty()) {
                    cout << "Stos nie jest pusty" << endl;
                }
                else
                    cout << "Stos jest pusty" << endl;
                break;
            case 'e':
                cout << "Wielkosc stosu wynosi " << TabSt.size() << endl;
                break;
            case 'f':
                cout << "KONIEC" << endl;
                return 0;
            default:
                cout << "Error: Zly wybor funkcji" << endl;
                cout << "Wpisz litere od a do f, a potem wcisnij ENTER" << endl;

                return 0;
            }
        }
    }
    
    if (Choice_struct=='2')
    {
        while (1)
        {
            Menu_Queue();
            cout << "Twoj wybor:" << endl;
            cin >> Choice_function;
            switch (Choice_function)
            {
            case 'a':
                cout << "Jaki element chcesz dodac?" << endl;
                cin >> Element;
                TabQu.enqueue(Element);
                cout << "Dodano na koniec kolejki liczbe " << Element << endl;
                break;

            case 'b':
                if (!TabQu.isEmpty()) {
                    cout << "Usunieto z poczatku kolejki liczbe " << TabQu.infront() << endl;
                    TabQu.dequeue();
                }
                else
                    cout << "Kolejka jest pusta - brak elementu do wyswietlenia" << endl;
                break;

            case 'c':
                if (!TabQu.isEmpty()) {
                    cout << "Kolejka nie jest pusta" << endl;
                }
                else
                    cout << "Kolejka jest pusta" << endl;
                break;
  
            case 'd':
                if (!TabQu.isEmpty())
                    cout << "Na poczatku kolejki znajduje sie: " << TabQu.infront() << endl;
                else
                    cout << "Kolejka jest pusta - brak elementu do wyświetlenia" << endl;
                break;
            
            case 'e':
                cout << "Wielkosc kolejki wynosi " << TabQu.size() << endl;
                break;
            case 'f':
                cout << "KONIEC" << endl;
                return 0;
        
            default:
                cout << "Error: Zly wybor funkcji" << endl;
                cout << "Wpisz litere od a do f, a potem wcisnij ENTER" << endl;

                return 0;
            }
        }
    }
}
