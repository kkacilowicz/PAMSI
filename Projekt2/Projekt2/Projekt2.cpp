// Projekt2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <chrono>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <random>
#include "Heap.h"
#include<vector>

#define Size_1M 1000000


using namespace std;

/*Funkcja scalająca*/
void merge(int* data, int* buf, int first, int middle, int last) {

    int i1 = first;
    int i2 = middle;
    for (int i = first; i <=last; i++)
    {
        if (i1==middle || (i2<=last && data[i1]>data[i2]))      //jeżeli element z lewej jest większy od tego z prawej
        {
            buf[i] = data[i2];                                  //wstaw do bufora ten mniejszy
            i2++;
        }
        else                                                    //jeżeli element z lewej jest mniejszy od tego z prawej
        {
            buf[i] = data[i1];                                  //wstaw go do bufora
            i1++;
        }
    }
    for (int i=first; i <=last; i++)
    {
        data[i] = buf[i];                   //kopiowanie z powrotem z bufora
    }

}

/*Sortowanie przez scalanie*/
void mergesort(int* data, int* buf, int first, int last) {

    int middle;
    middle = (first + last + 1) / 2;
    if (middle-first>1)
        mergesort(data,buf, first, middle - 1);         //podział z lewej strony
    if (last - middle > 0)
        mergesort(data,buf, middle, last);              //podział z prawej strony

    merge(data,buf, first, middle, last);               //scalanie

    

}

/*Funkcja wyznaczająca medianę z trzech i wyznaczająca piwota dla sortowania malejącego*/
int Choose_pivotDesc(int* data, int first, int last) {
    int middle, pivot;
    middle = (first + last) / 2;
    if (data[middle] < data[first])
        swap(data[first], data[middle]);
        
    if (data[last] < data[first])
        swap(data[first], data[last]);

    if (data[middle] > data[last])
        swap(data[middle], data[last]);

    pivot = data[middle];

    return pivot;
}

/*Funkcja wyznaczająca medianę z trzech i wyznaczająca piwota dla sortowania rosnącego*/
int Choose_pivotAsc(int* data, int first, int last) {
    int middle, pivot;
    middle = (first + last) / 2;
    if (data[middle] > data[first])
        swap(data[first], data[middle]);

    if (data[last] > data[first])
        swap(data[first], data[last]);

    if (data[middle] < data[last])
        swap(data[middle], data[last]);

    pivot = data[middle];

    return pivot;
}

int partition_Hoare(int* data, int low, int high) {

   
    int pivot=Choose_pivotDesc(data,low,high);
    int i = low - 1, j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (data[i] < pivot);          //przeszukanie aż do elementu większego od piwota z lewej strony

        do
        {
            j--;
        } while (data[j] > pivot);          //przeszukanie aż do elementu mniejszego od piwota z prawej strony
 
        if (i >= j)                         //przypadek, gdy indeksy i oraz j się spotkają
            return j;

        swap(data[i], data[j]);             //zamień miejscami element wiekszy z lewej oraz mniejszy z prawej od piwota
    }
}

/*Sortowanie szybkie z wykorzystaniem algorytmu partition Hoare*/
void quicksort_Hoare(int* data, int left, int right) {

    if (left < right) {
        int p;
        p = partition_Hoare(data, left, right);
        quicksort_Hoare(data, left, p);
        quicksort_Hoare(data, p + 1, right);
    }

}

/*Sortowanie przez kopcowanie*/
void heapsort(int *data, int size)
{
    Heap Hp(size);                    
    Hp.BuildHeap(data, size);         //budowanie kopca z zadanej tablicy           
    while (size >= 2)
    {
        swap(data[1], data[size]);    //ustawienie korzenia na koniec kopca
        size--;                       //utrata "dostępu" do ostatniego elementu
        Hp.downheap(data, size, 1);   //przywrócenie własności kopca
    }
}

void introsort(int* data, int*buf, int first, int last, int maxdepth)
{
    int i = 0;
   
    if (first < last) {
        if (maxdepth!=0)                                        //jeżeli głębokość wywołań rekurencyjnych >0
        {
            i = partition_Hoare(data, first, last);
            introsort(data, buf, first, i, maxdepth-1);         //wykonuj quicksort
            introsort(data, buf, i + 1, last, maxdepth-1);
        }
        else
        {
            int a = first;
            int b = last;
            int i = 1;                           //korzeń kopca ma indeks 1
            int size = b - a + 1;                //rozmiar tablicy do sortowania przez kopcowanie
            buf[0] = 0;

            while (a <= b)                                      
            {
                buf[i] = data[a];                //kopiowanie danych do bufora w celu 
                ++a;                             //utworzenia mniejszego kopca do posortowania
                ++i;
            }            
            heapsort(buf, size);                 //sortowanie przez kopcowanie
            i = 1;
            a = first;
            while (a <= b)
            {
                data[a] = buf[i];                //przekopiowywanie posortowanych danych z bufora do glownej tablicy
                ++a;
                ++i;
            }
        }
    }
}

/*Sortowanie introspektywne */
void introspectivesort(int* data, int* buf, int first, int last) {

    int maxdepth = 2*log2(last);                    //Określenie głębokości rekurencyjnej
    introsort(data, buf, first, last, maxdepth); 

}

/*Funkcja sprawdzajaca poprawnosc sortowania tablicy*/
bool checkIfCorrect(int* data, int *result,int*Array, int Size)
{
    
    std::copy(data, data + Size, Array);
    std::sort(Array, Array+Size);

    return std::equal(Array, Array+Size,
        result, result+Size);
}

int main()
{

    std::random_device rd;                                  //To jest 'seed' do silnika
    std::mt19937 gen1(rd());                                //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<int> dis(1, INT_MAX);     //rozklad danych oraz jego zakres do testow
    std::uniform_int_distribution<int> distest(1, 100);     //rozklad danych oraz jego zakres do prezentacji dzialania

    auto gen = [&dis, &gen1]() {                         //generator liczb losowych do testow
        return dis(gen1);
    };

    auto gentest = [&distest, &gen1]() {                //generator liczb losowych do testow
        return distest(gen1);
    };


    int* buf = new int[Size_1M];                       //bufor do obliczen przy scalaniu i introsorcie
    int* ArraytocheckifCorrect = new int[Size_1M];     //bufor do realizacji sprawdzenia poprawnosci tablicy
    srand((unsigned)time(0));                          //tworzenie wartosci losowych
   
    
    std::vector<int> nVector{ 10000, 50000, 100000,500000, 1000000 };          //wielkosc tablicy do posortowania
    std::vector<double> SortsType{ 0, 0.25, 0.5, 0.75, 0.95, 0.99, 0.997, -1}; //wektor oznaczjacy % posortowania przed testem (-1 oznacza reverse)
    const int nbOfExperiments = 100;                                           //ilosc eksperymentow



 ////////////////////////////////////////////////////Prezentacja dzialania algorytmow/////////////////////////////////////////////////////////////////////////////

    int Size = 30;

    int* data1 = new int[Size];                      //tablica do sortowania
    int* Data_copy1 = new int[Size];                 //kopia, ktora zostaie posortowana

    int* data2 = new int[Size];                      //tablica do sortowania
    int* Data_copy2 = new int[Size];                 //kopia, ktora zostaie posortowana

    int* data3 = new int[Size];                      //tablica do sortowania
    int* Data_copy3 = new int[Size];                 //kopia, ktora zostaie posortowana

    std::generate(data1, data1 + Size, gentest);     //wypelnianie tablicy losowymi liczbami
    std::generate(data2, data2 + Size, gentest);     //wypelnianie tablicy losowymi liczbami
    std::generate(data3, data3 + Size, gentest);     //wypelnianie tablicy losowymi liczbami

    std::copy(data1, data1 + Size, Data_copy1);      //kopiowanie tablicy
    std::copy(data2, data2 + Size, Data_copy2);      //kopiowanie tablicy
    std::copy(data3, data3 + Size, Data_copy3);      //kopiowanie tablicy

    
    cout << "Tablica przed sortowaniem:  " << endl;

    for (int i = 0; i < Size; i++)
        cout << Data_copy1[i] << " ";

    cout << endl;

    if (checkIfCorrect(data1, Data_copy1, ArraytocheckifCorrect, Size))
        cout << "Tablica jest posortowana" << endl;
    else
        cout << "Tablica jest nieposortowana" << endl;

    mergesort(Data_copy1, buf, 0, Size - 1);
    
    cout << endl;

    cout << "Tablica po sortowaniu przez scalanie:  " << endl;

    for (int i = 0; i < Size; i++)
        cout << Data_copy1[i] << " ";

    cout << endl;

    if (checkIfCorrect(data1, Data_copy1, ArraytocheckifCorrect, Size))
        cout << "Tablica jest posortowana" << endl;
    else
        cout << "Tablica jest nieposortowana" << endl;

    cout << endl;
    
    delete[]data1;
    delete[]Data_copy1;


    cout << "Tablica przed sortowaniem:  " << endl;

    for (int i = 0; i < Size; i++)
        cout << Data_copy2[i] << " ";

    cout << endl;

    if (checkIfCorrect(data2, Data_copy2, ArraytocheckifCorrect, Size))
        cout << "Tablica jest posortowana" << endl;
    else
        cout << "Tablica jest nieposortowana" << endl;

    quicksort_Hoare(Data_copy2, 0, Size - 1);

    cout << endl;

    cout << "Tablica po sortowaniu szybkim:  " << endl;

    for (int i = 0; i < Size; i++)
        cout << Data_copy2[i] << " ";

    cout << endl;

    if (checkIfCorrect(data2, Data_copy2, ArraytocheckifCorrect, Size))
        cout << "Tablica jest posortowana" << endl;
    else
        cout << "Tablica jest nieposortowana" << endl;

    cout << endl;

    delete[]data2;
    delete[]Data_copy2;


    cout << "Tablica przed sortowaniem:  " << endl;

    for (int i = 0; i < Size; i++)
        cout << Data_copy3[i] << " ";

    cout << endl;

    if (checkIfCorrect(data3, Data_copy3, ArraytocheckifCorrect, Size))
        cout << "Tablica jest posortowana" << endl;
    else
        cout << "Tablica jest nieposortowana" << endl;

    introspectivesort(Data_copy3, buf, 0, Size - 1);

    cout << endl;

    cout << "Tablica po sortowaniu introspektywnym:  " << endl;

    for (int i = 0; i < Size; i++)
        cout << Data_copy3[i] << " ";

    cout << endl;

    if (checkIfCorrect(data3, Data_copy3, ArraytocheckifCorrect, Size))
        cout << "Tablica jest posortowana" << endl;
    else
        cout << "Tablica jest nieposortowana" << endl;

    cout << endl;

    delete[]data3;
    delete[]Data_copy3;


    
 //////////////////////////////////////////////////////////////////////Mergesort/////////////////////////////////////////////////////////////////////  
    /*
    //Okreslenie  ile elementow ma byc juz posortowanych przed testami
    for (const auto& t : SortsType)
    {

        //Badanie dla każdego rozmiaru tablicy n
        for (const auto& n : nVector)
        {
            int* data = new int[n];                      //tablica do sortowania
            int* Data_copy = new int[n];                 //kopia, ktora zostaie posortowana

            double Sum = 0;
            //Wykonanie eksperymentu nbOfExperiments razy dla tablic o rozmiarze n
            for (int i = 0; i < nbOfExperiments; ++i)
            {
                
                
                std::generate(data, data + n, gen);


                std::copy(data, data + n, Data_copy);               //kopiowanie tablicu

                if (t != 0 && t != -1)                              //sortowanie zadanych elementow tablicy (jesli trzeba)
                {
                    int HowMuch_sorted;
                    HowMuch_sorted = t * n;                  //ile elementow ma byc juz posortowanych
                    mergesort(Data_copy,buf,0,  HowMuch_sorted-1);
                }
                if (t == -1)
                {
                    mergesort(Data_copy,buf, 0, n-1);
                    std::reverse(Data_copy, Data_copy + n);
                }

                auto start = std::chrono::system_clock::now();
                mergesort(Data_copy, buf, 0, n - 1);
                auto end = std::chrono::system_clock::now();

                std::chrono::duration<double> diff = end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
                double durationTime = diff.count(); // zmierzony czas zapisać do pliku lub zagregować, zapisać liczbę badanych elementów

                
                if (!checkIfCorrect(data, Data_copy, ArraytocheckifCorrect, n))
                {
                    cout << "Cos poszlo nie tak dla tablicy nr " << i;
                    return 0;
                }
                
                Sum += durationTime;

                                

            }
            if (t != -1)
                cout << "Czas trwania mergesort dla 100 tablic posortowanych w " << t * 100 << " % o rozmiarze " << n << " wynosi: " << Sum << endl;
            else 
                cout << "Czas trwania mergesort dla 100 tablic posortowanych w odwrotnej kolejnosci o rozmiarze " << n << " wynosi: " << Sum << endl;
            
            delete[] data;
            delete[] Data_copy;

        }

    }
*/


 //////////////////////////////////////////////////////////////////////Quicksort/////////////////////////////////////////////////////////////////////  
 /*
       //Okreslenie  ile elementow ma byc juz posortowanych przed testami
    for (const auto& t : SortsType)
    {

        //Badanie dla każdego rozmiaru tablicy n
        for (const auto& n : nVector)
        {
            int* data = new int[n];                      //tablica do sortowania
            int* Data_copy = new int[n];                 //kopia, ktora zostaie posortowana

            double Sum = 0;
            //Wykonanie eksperymentu nbOfExperiments razy dla tablic o rozmiarze n
            for (int i = 0; i < nbOfExperiments; ++i)
            {


                std::generate(data, data + n, gen);


                std::copy(data, data + n, Data_copy);               //kopiowanie tablicu

                if (t != 0 && t != -1)                              //sortowanie zadanych elementow tablicy (jesli trzeba)
                {
                    
                    int HowMuch_sorted;
                    HowMuch_sorted = t * n;                  //ile elementow ma byc juz posortowanych
                    quicksort_Hoare(Data_copy, 0, HowMuch_sorted - 1);
                }
                if (t == -1)
                {
                    quicksort_Hoare(Data_copy, 0, n - 1);
                    std::reverse(Data_copy, Data_copy + n);
                }

                auto start = std::chrono::system_clock::now();
                quicksort_Hoare(Data_copy, 0, n - 1);
                auto end = std::chrono::system_clock::now();

                std::chrono::duration<double> diff = end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
                double durationTime = diff.count(); // zmierzony czas zapisać do pliku lub zagregować, zapisać liczbę badanych elementów

                
                if (!checkIfCorrect(data, Data_copy, ArraytocheckifCorrect, n))
                {
                    cout << "Cos poszlo nie tak dla tablicy nr " << i;
                    return 0;
                }
                
                Sum += durationTime;
                


            }
            if (t != -1)
                cout << "Czas trwania quicksort dla 100 tablic posortowanych w " << t * 100 << " % o rozmiarze " << n << " wynosi: " << Sum << endl;
            else
                cout << "Czas trwania quicksort dla 100 tablic posortowanych w odwrotnej kolejnosci o rozmiarze " << n << " wynosi: " << Sum << endl;

            delete[] data;
            delete[] Data_copy;

        }

    }
    
   */ 


    //////////////////////////////////////////////////////////////////////Introsort/////////////////////////////////////////////////////////////////////  
/*
       //Okreslenie  ile elementow ma byc juz posortowanych przed testami
    for (const auto& t : SortsType)
    {

        //Badanie dla każdego rozmiaru tablicy n
        for (const auto& n : nVector)
        {
            int* data = new int[n];                      //tablica do sortowania
            int* Data_copy = new int[n];                 //kopia, ktora zostaie posortowana

            double Sum = 0;
            //Wykonanie eksperymentu nbOfExperiments razy dla tablic o rozmiarze n
            for (int i = 0; i < nbOfExperiments; ++i)
            {


                std::generate(data, data + n, gen);


                std::copy(data, data + n, Data_copy);               //kopiowanie tablicu

                if (t != 0 && t != -1)                              //sortowanie zadanych elementow tablicy (jesli trzeba)
                {
                    int HowMuch_sorted;
                    HowMuch_sorted = t * n;                  //ile elementow ma byc juz posortowanych
                    introspectivesort(Data_copy, buf, 0, HowMuch_sorted - 1);
                }
                if (t == -1)
                {
                    introspectivesort(Data_copy, buf, 0, n - 1);
                    std::reverse(Data_copy, Data_copy + n);
                }

                auto start = std::chrono::system_clock::now();
                introspectivesort(Data_copy, buf, 0, n - 1);
                auto end = std::chrono::system_clock::now();

                std::chrono::duration<double> diff = end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
                double durationTime = diff.count(); // zmierzony czas zapisać do pliku lub zagregować, zapisać liczbę badanych elementów

                
                if (!checkIfCorrect(data, Data_copy, ArraytocheckifCorrect, n))
                {
                    cout << "Cos poszlo nie tak dla tablicy nr " << i;
                    return 0;
                }
                
                Sum += durationTime;
                
                

            }
            if (t != -1)
                cout << "Czas trwania introsort dla 100 tablic posortowanych w " << t * 100 << " % o rozmiarze " << n << " wynosi: " << Sum << endl;
            else
                cout << "Czas trwania introsort dla 100 tablic posortowanych w odwrotnej kolejnosci o rozmiarze " << n << " wynosi: " << Sum << endl;

            delete[] data;
            delete[] Data_copy;

        }

    }
   */

    delete[] buf;
    delete[] ArraytocheckifCorrect;
    
}

