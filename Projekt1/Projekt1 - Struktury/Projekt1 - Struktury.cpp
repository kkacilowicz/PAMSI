// Projekt1 - Struktury.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include<ctime>
#include"TabStack.h"
#include"TabQueue.h"
#include "SLinkedList.h"
#include "DLinkedList.h"
#include"Heap.h"
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
    cout << "3 - Lista jednokierunkowa" << endl;
    cout << "4 - Lista dwukierunkowa" << endl;
    cout << "5 - Kopiec" << endl;
    cout << "6 - Zakoncz" << endl;
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

//Wyswietlanie menu listy
void Menu_List() {
    cout << "Menu" << endl;
    cout << "a - Sprawdz czy lista jest pusta" << endl;
    cout << "b - Dodanie do listy na poczatek" << endl;
    cout << "c - Dodanie do listy na koniec" << endl;
    cout << "d - Wstaw element po elemencie z zadanym kluczem" << endl;
    cout << "e - Usun element z poczatku listy" << endl;
    cout << "f - Usun element z konca listy" << endl;
    cout << "g - Usun element z zadanym kluczem" << endl;
    cout << "h - Wyswietl cala liste" << endl;
    cout << "i - Wyswietl pierwszy element" << endl;
    cout << "j - Wyswietl ostatni element" << endl;
    cout << "k - Zakoncz" << endl;

}

//Wyswietlanie menu kopca
void Menu_Heap() {
    cout << "Menu" << endl;
    cout << "a - Budowa kopca na podstawie n elementow" << endl;
    cout << "b - Przywracanie wlasnosci kopca" << endl;
    cout << "c - Dodanie elementu do kopca" << endl;
    cout << "d - Usuniecie korzenia do kopca" << endl;
    cout << "e - Wyswietl rozmiar kopca" << endl;
    cout << "f - Czytelne wyswietlenie elementow kopca" << endl;
    cout << "g - Zakoncz" << endl;
}
int main()
{
    TabStack TabSt(5);                       
    TabQueue TabQu(5);
    SLinkedList SLL;
    DLinkedList DLL;
   
    srand((unsigned)time(0));               //tworzenie wartosci losowych
  
    char Choice_struct, Choice_function;    //podejmowane decyzje od uzytkownika
    int Element;                            //Element dodawany do struktury
    int Key;                                //Klucz do obslugi list

    
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
    
    else if (Choice_struct=='2')
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
    else if (Choice_struct=='3')
    {

    while (1)
    {
        Menu_List();
        cout << "Twoj wybor:" << endl;
        cin >> Choice_function;
        switch (Choice_function)
        {
        case 'a':
            if (!SLL.empty()) {
                cout << "Lista nie jest pusta" << endl;
            }
            else
                cout << "Lista jest pusta" << endl;
            break;
        case 'b':

            cout << "Jaki element chcesz dodac z przodu?" << endl;
            cin >> Element;
            SLL.addFront(Element);
            cout << "Dodano na poczatek listy liczbe " << SLL.front() << endl;
            break;


        case 'c':

            cout << "Jaki element chcesz dodac na koniec listy?" << endl;
            cin >> Element;
            SLL.addRear(Element);
            cout << "Dodano na koniec listy liczbe " << SLL.rear() << endl;
            break;

        case 'd':

            cout << "Jaki element chcesz dodac do listy?" << endl;
            cin >> Element;
            cout << "Podaj klucz do elementu za ktorym chcesz wstawic nowy" << endl;
            cin >> Key;
            SLL.addAfterKey(Element,Key);
            break;

        case 'e':
            if (!SLL.empty()) {
                cout << "Usunieto z poczatku listy liczbe " << SLL.front() << endl;
                SLL.removeFront();
            }
            else
                cout << "Lista jest pusta - nie mozna nic usunac" << endl;
            break;
        case 'f':
            if (!SLL.empty()) {
                cout << "Usunieto z konca listy liczbe " << SLL.rear() << endl;
                SLL.removeRear();
            }
            else
                cout << "Lista jest pusta - nie mozna nic usunac" << endl;
            break;


        case 'g':
            if (!SLL.empty()) {

                cout << "Podaj klucz do elementu ktory chcesz usunac" << endl;
                cin >> Key;
                SLL.removeKey(Key);
            }
            else
                cout << "Lista jest pusta - nie mozna nic usunac" << endl;
            break;
        case 'h':
            if (!SLL.empty())
                SLL.display();
            else
                cout << "Lista jest pusta - brak elementu do wyświetlenia" << endl;
            break;
            

        case 'i':
            if (!SLL.empty())
                cout << "Na poczatku listy znajduje sie: " << SLL.front() << endl;
            else
                cout << "Lista jest pusta - brak elementu do wyświetlenia" << endl;
            break;

        case 'j':
            if (!SLL.empty())
                cout << "Na koncu listy znajduje sie: " << SLL.rear() << endl;
            else
                cout << "Lista jest pusta - brak elementu do wyświetlenia" << endl;
            break;

        case 'k':
            cout << "KONIEC" << endl;
            return 0;

        default:
            cout << "Error: Zly wybor funkcji" << endl;
            cout << "Wpisz litere od a do f, a potem wcisnij ENTER" << endl;

            return 0;
        }
    }
    
    

    }
    else if (Choice_struct == '4')
    {
    while (1)
    {
        Menu_List();
        cout << "Twoj wybor:" << endl;
        cin >> Choice_function;
        switch (Choice_function)
        {
        case 'a':
            if (!DLL.empty()) {
                cout << "Lista nie jest pusta" << endl;
            }
            else
                cout << "Lista jest pusta" << endl;
            break;
        case 'b':

            cout << "Jaki element chcesz dodac z przodu?" << endl;
            cin >> Element;
            DLL.addFront(Element);
            cout << "Dodano na poczatek listy liczbe " << DLL.front() << endl;
            break;


        case 'c':

            cout << "Jaki element chcesz dodac na koniec listy?" << endl;
            cin >> Element;
            DLL.addRear(Element);
            cout << "Dodano na koniec listy liczbe " << DLL.rear() << endl;
            break;

        case 'd':

            cout << "Jaki element chcesz dodac do listy?" << endl;
            cin >> Element;
            cout << "Podaj klucz do elementu za ktorym chcesz wstawic nowy" << endl;
            cin >> Key;
            DLL.addAfterKey(Element, Key);
            break;

        case 'e':
            if (!DLL.empty()) {
                cout << "Usunieto z poczatku listy liczbe " << DLL.front() << endl;
                DLL.removeFront();
            }
            else
                cout << "Lista jest pusta - nie mozna nic usunac" << endl;
            break;
        case 'f':
            if (!DLL.empty()) {
                cout << "Usunieto z konca listy liczbe " << DLL.rear() << endl;
                DLL.removeRear();
            }
            else
                cout << "Lista jest pusta - nie mozna nic usunac" << endl;
            break;


        case 'g':
            if (!DLL.empty()) {

                cout << "Podaj klucz do elementu ktory chcesz usunac" << endl;
                cin >> Key;
                DLL.removeKey(Key);
            }
            else
                cout << "Lista jest pusta - nie mozna nic usunac" << endl;
            break;
        case 'h':
            if (!DLL.empty())
                DLL.display();
            else
                cout << "Lista jest pusta - brak elementu do wyświetlenia" << endl;
            break;


        case 'i':
            if (!DLL.empty())
                cout << "Na poczatku listy znajduje sie: " << DLL.front() << endl;
            else
                cout << "Lista jest pusta - brak elementu do wyświetlenia" << endl;
            break;

        case 'j':
            if (!DLL.empty())
                cout << "Na koncu listy znajduje sie: " << DLL.rear() << endl;
            else
                cout << "Lista jest pusta - brak elementu do wyświetlenia" << endl;
            break;

        case 'k':
            cout << "KONIEC" << endl;
            return 0;

        default:
            cout << "Error: Zly wybor funkcji" << endl;
            cout << "Wpisz litere od a do f, a potem wcisnij ENTER" << endl;

            return 0;
        }
    }

    
    }
    else if (Choice_struct == '5') {

    //Wczytywanie elementow do klasy, ale jeszcze nie budowanie

    int SIZE;
    cout << "Z ilu elementow ma sie skladac kopiec?" << endl;
    cout << "Twoj wybor:" << endl;
    cin >> SIZE;
    int Random_Element;
    
    int* a = new int[SIZE + 1];
    for (int i = 1; i < SIZE + 1; i++)
    {
        Random_Element = rand() + 1;
        a[i] = Random_Element;
    }
    cout << endl;
    Heap Hp(a, SIZE + 1);


    while (1) {
       

        Menu_Heap();
        cout << "Twoj wybor:" << endl;
        cin >> Choice_function;
        switch (Choice_function)
        {
        case 'a':
            if (!Hp.empty())
            {
                Hp.BuildHeap();
            }
            else
            {
                cout << "Brak elementow z ktorych mozna zbudowac kopiec" << endl;
            }
            break;

        case 'b':
            if (!Hp.empty()) {
                cout << "Dla ktorego elementu chcesz przywrocic wlasnosc kopca?" << endl;
                int Which_one;
                cin >> Which_one;
                Hp.MaxHeapify(Which_one);
            }
            else
                cout << "Kopiec jest pusty - nie mozna przywrocic wlasnosci kopca" << endl;
            break;
        case 'c':
            cout << "Jaki element chcesz dodac do kopca?" << endl;
            cin >> Element;
            Hp.AddElement(Element);
            break;
        case 'd':
            if (!Hp.empty()) {
                Hp.RemoveRoot();
            }
            else
                cout << "Kopiec jest pusty - nie mozna usunac korzenia" << endl;
            break;
        case 'e':
            cout << "Wielkosc kopca wynosi " << Hp.size() << endl;
            break;
        case 'f':
            Hp.display();
            cout << endl;
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
    else if (Choice_struct == '6') {
    cout << "KONIEC" << endl;
    return 0;
    }
    else
    {
    cout << "Zly wybor struktury - wybierz liczbe od 1 do 6 " << endl;
    }

}
