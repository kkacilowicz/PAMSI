// Projekt1 - Kontenery.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cstdlib>
#include <stack>
#include <ctime>
#include<queue>
#include<list>
using namespace std;

//Wyswietlanie menu stosu
void Menu_Stack() {

    cout << "Menu" << endl;
    cout << "a - Dodanie na stos losowego elementu" << endl;
    cout << "b - Dodanie na stos m losowych elementow" << endl;
    cout << "c - Wyswietl element ze szczytu stosu" << endl;
    cout << "d - Usun element ze szczytu stosu" << endl;
    cout << "e - Usun k elementow ze szczytu stosu" << endl;
    cout << "f - Wyswietl liczbe elementow stosu" << endl;
    cout << "g - Zakoncz" << endl;
}

//Wyswietlanie menu kolejki
void Menu_Queue() {

    cout << "Menu" << endl;
    cout << "a - Dodanie na koniec kolejki losowego elementu" << endl;
    cout << "b - Dodanie na koniec kolejki m losowych elementow" << endl;
    cout << "c - Wyswietl pierwszy element" << endl;
    cout << "d - Usun element z poczatku kolejki" << endl;
    cout << "e - Usun k elementow ze poczatku kolejki" << endl;
    cout << "f - Wyswietl liczbe elementow kolejki" << endl;
    cout << "g - Zakoncz" << endl;

}


//Wyswietlanie menu listy

void Menu_List() {

    cout << "Menu" << endl;
    cout << "a - Wyswietl zawartosc listy" << endl;
    cout << "b - Wyswietl liczbe elementow listy" << endl;
    cout << "c - Wyswietl ostatni element" << endl;
    cout << "d - Wyswietl pierwszy element" << endl;
    cout << "e - Dodaj losowy element na poczatek listy" << endl;
    cout << "f - Dodaj losowy element na koniec listy" << endl;
    cout << "g - Dodaj k elementow na poczatek listy" << endl;
    cout << "h - Dodaj m elementow na koniec listy" << endl;
    cout << "i - Usun element z konca listy" << endl;
    cout << "j - Usun j elementow z konca listy" << endl;
    cout << "k - Usun wszystkie elementy listy" << endl;
    cout << "l - Zakoncz" << endl;

}


void Menu_Structures() {
    cout << "Menu" << endl;
    cout << "1 - Stos" << endl;
    cout << "2 - Kolejka" << endl;
    cout << "3 - Lista" << endl;
    cout << "4 - Zakoncz" << endl;
}

int main()
{
    stack <int> s;
    queue <int> q;
    list <int> l;
    int Random_Element = 0;                 //do wprowadzania losowych wartosci do struktur
    char Choice_struct, Choice_function;    //podejmowane decyzje od uzytkownika
    int How_many;                           //do ilosci powtorzen - np ile elementow ma byc usuniete



    srand((unsigned)time(0));               //tworzenie wartosci losowych



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
                Random_Element = (rand() % 100) + 1;
                s.push(Random_Element);
                cout << "Dodano do stosu liczbe " << Random_Element << endl;
                break;
            case 'b':
                cout << "Ile elementow chcesz dodac?" << endl;
                cin >> How_many;
                for (int i = 0; i < How_many; i++)
                {
                    Random_Element = (rand() % 100) + 1;
                    s.push(Random_Element);
                }
                break;

            case 'c':
                if (!s.empty())
                    cout << "Na szczycie stosu znajduje sie: " << s.top() << endl;
                else
                    cout << "Stos jest pusty - brak elementu do wyswietlenia" << endl;
                break;
            case 'd':
                if (!s.empty()) {
                    cout << "Usunieto ze stosu liczbe " << s.top() << endl;
                    s.pop();
                }
                else
                    cout << "Stos jest pusty - brak elementu do wyświetlenia" << endl;
                break;
            case 'e':
                cout << "Ile elementow chcesz usunac?" << endl;
                cin >> How_many;
                for (int i = 0; i < How_many; i++) {
                    if (!s.empty())
                        s.pop();
                    else {
                        cout << "Stos jest juz pusty" << endl;
                        cout << "Usunieto " << i << " elementow" << endl;
                        break;
                    }
                }
                break;
            case 'f':
                cout << "Wielkosc stosu wynosi " << s.size() << endl;
                break;
            case 'g':
                cout << "KONIEC" << endl;
                return 0;
            default:
                cout << "Error: Zly wybor funkcji" << endl;
                cout << "Wpisz litere od a do g, a potem wcisnij ENTER" << endl;

                return 0;
            }
        }
    }
    else if (Choice_struct == '2')
    {
        while (1)
        {
            Menu_Queue();
            cout << "Twoj wybor:" << endl;
            cin >> Choice_function;
            switch (Choice_function)
            {
            case 'a':
                Random_Element = (rand() % 100) + 1;
                q.push(Random_Element);
                cout << "Dodano na koniec kolejki liczbe " << Random_Element << endl;
                break;
            case 'b':
                cout << "Ile elementow chcesz dodac?" << endl;
                cin >> How_many;
                for (int i = 0; i < How_many; i++)
                {
                    Random_Element = (rand() % 100) + 1;
                    q.push(Random_Element);
                }
                break;

            case 'c':
                if (!q.empty())
                    cout << "Na poczatku kolejki znajduje sie: " << q.front() << endl;
                else
                    cout << "Kolejka jest pusta - brak elementu do wyświetlenia" << endl;
                break;
            case 'd':
                if (!q.empty()) {
                    cout << "Usunieto z poczatku kolejki liczbe " << q.front() << endl;
                    q.pop();
                }
                else
                    cout << "Kolejka jest pusta - brak elementu do wyswietlenia" << endl;
                break;
            case 'e':
                cout << "Ile elementow chcesz usunac?" << endl;
                cin >> How_many;
                for (int i = 0; i < How_many; i++) {
                    if (!q.empty())
                        q.pop();
                    else {
                        cout << "Kolejka jest juz pusta" << endl;
                        cout << "Usunieto " << i << " elementow" << endl;
                        break;
                    }
                }
                break;
            case 'f':
                cout << "Wielkosc kolejki wynosi " << q.size() << endl;
                break;
            case 'g':
                cout << "KONIEC" << endl;
                return 0;
            default:
                cout << "Error: Zly wybor funkcji" << endl;
                cout << "Wpisz litere od a do g, a potem wcisnij ENTER" << endl;

                return 0;
            }
        }
    }
    else if (Choice_struct == '3') {

        while (1)
        {
            Menu_List();
            cout << "Twoj wybor:" << endl;
            cin >> Choice_function;
            switch (Choice_function)
            {
            case 'a':

                if (!l.empty())
                {
                    for (int n : l)
                    {
                        cout << n << "\t";
                    }
                }
                else
                {
                    cout << "Lista jest pusta - brak elementow do wyswietlenia" << endl;
                }
                cout << endl;
                break;
            case 'b':
                cout << "Liczba elementow listy wynosi " << l.size() << endl;
                break;

            case 'c':
                if (!l.empty())
                    cout << "Na koncu listy znajduje sie: " << l.back() << endl;
                else
                    cout << "Lista jest pusta - brak elementow do wyswietlenia" << endl;
                break;
            case 'd':
                if (!l.empty())
                    cout << "Na poczatku listy znajduje sie: " << l.front() << endl;
                else
                    cout << "Kolejka jest pusta - brak elementu do wyswietlenia" << endl;
                break;



            case 'e':
                Random_Element = (rand() % 100) + 1;
                l.push_front(Random_Element);
                cout << "Dodano na poczatek listy liczbe " << Random_Element << endl;
                break;

            case 'f':
                Random_Element = (rand() % 100) + 1;
                l.push_back(Random_Element);
                cout << "Dodano na koniec listy liczbe " << Random_Element << endl;
                break;
            case 'g':
                cout << "Ile elementow chcesz dodac na poczatek listy?" << endl;
                cin >> How_many;
                for (int i = 0; i < How_many; i++)
                {
                    Random_Element = (rand() % 100) + 1;
                    l.push_front(Random_Element);
                }
                break;
            case 'h':
                cout << "Ile elementow chcesz dodac na koniec listy?" << endl;
                cin >> How_many;
                for (int i = 0; i < How_many; i++)
                {
                    Random_Element = (rand() % 100) + 1;
                    l.push_back(Random_Element);
                }
                break;
            case 'i':

                if (!l.empty()) {
                    cout << "Usunięto z konca listy liczbe " << l.back() << endl;
                    l.pop_back();
                }
                else
                    cout << "Kolejka jest pusta - brak elementu do wyswietlenia" << endl;
                break;

            case 'j':
                cout << "Ile elementow chcesz usunac z konca listy?" << endl;
                cin >> How_many;
                for (int i = 0; i < How_many; i++) {
                    if (!l.empty())
                        l.pop_back();
                    else {
                        cout << "Lista jest juz pusta" << endl;
                        cout << "Usunieto " << i << " elementow" << endl;
                        break;
                    }
                }
                break;
            case 'k':

                l.clear();
                cout << "Lista została wyczyszczona " << endl;
                break;
            case 'l':
                cout << "KONIEC" << endl;
                return 0;
            default:
                cout << "Error: Zly wybor funkcji" << endl;
                cout << "Wpisz litere od a do l, a potem wcisnij ENTER" << endl;

                return 0;
            }
        }

    }
    else if (Choice_struct == '4') {
        cout << "KONIEC" << endl;
        return 0;
    }
    else
    {
        cout << "Error: Zly wybor struktury" << endl;
        cout << "Wpisz liczbe od 1 do 4 a potem wcisnij ENTER" << endl;

        return 0;
    }

}

