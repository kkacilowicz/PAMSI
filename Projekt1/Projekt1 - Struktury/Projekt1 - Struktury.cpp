// Projekt1 - Struktury.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include"TabStack.h"
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




int main()
{
    TabStack TabSt(5);
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
                    cout << "Na szczycie stosu znajduje sie: " << TabSt.onTop() << endl;
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
