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

void merge(int* data, int* buf, int first, int middle, int last) {

    int i1 = first;
    int i2 = middle;
    for (int i = first; i <=last; i++)
    {
        if (i1==middle || (i2<=last && data[i1]>data[i2]))
        {
            buf[i] = data[i2];
            i2++;
        }
        else
        {
            buf[i] = data[i1];
            i1++;
        }
    }
    for (int i=first; i <=last; i++)
    {
        data[i] = buf[i];
    }

}

void mergesort(int* data, int* buf, int first, int last) {

    int middle;
    middle = (first + last + 1) / 2;
    if (middle-first>1)
     mergesort(data,buf, first, middle - 1);
    if (last - middle > 0)
        mergesort(data,buf, middle, last);

    merge(data,buf, first, middle, last);

    

}

int Choose_pivotDesc(int* data, int first, int last) {
    int middle, pivot;
    middle = (first + last) / 2;
    if (data[middle] < data[first])
        swap(data[first], data[middle]);
        
    if (data[last] < data[first])
        swap(data[first], data[last]);

    if (data[middle] > data[last])
        swap(data[middle], data[last]);

    pivot = data[last];

    return pivot;
}

int Choose_pivotAsc(int* data, int first, int last) {
    int middle, pivot;
    middle = (first + last) / 2;
    if (data[middle] > data[first])
        swap(data[first], data[middle]);

    if (data[last] > data[first])
        swap(data[first], data[last]);

    if (data[middle] < data[last])
        swap(data[middle], data[last]);

    pivot = data[last];

    return pivot;
}

int partition_Hoare(int* data, int low, int high) {

   // int middle = (high + low) / 2;
    int pivot = Choose_pivotAsc(data,low,high);
    int i = low - 1, j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (data[i] < pivot);

        do
        {
            j--;
        } while (data[j] > pivot);
 
        if (i >= j)
            return j;

        swap(data[i], data[j]);
    }
}

void quicksort_Hoare(int* data, int left, int right) {

    if (left < right) {
        int p;
        p = partition_Hoare(data, left, right);
        quicksort_Hoare(data, left, p);
        quicksort_Hoare(data, p + 1, right);
    }

}



void heapsort(int tab[], int size)
{
    Heap Hp(size);
    Hp.BuildHeap(tab, size);
    while (size >= 2)
    {
        swap(tab[1], tab[size]);
        size--;
        Hp.downheap(tab, size, 1);
    }
}


void introsort(int* data, int*buf, int first, int last, int maxdepth)
{
    int i = 0;
    int x = last - first + 1;
    if (first < last) {
        if (maxdepth!=0)
        {
            i = partition_Hoare(data, first, last);;
            introsort(data, buf, first, i, maxdepth-1);
            introsort(data, buf, i + 1, last, maxdepth-1);
        }
        else
        {
            int a = first;
            int b = last;
            int i = 1;
            int size = b - a + 1;
            buf[0] = 0;

            while (a <= b)
            {
                buf[i] = data[a];
                ++a;
                ++i;
            }            
            heapsort(buf, size);
            i = 1;
            a = first;
            while (a <= b)
            {
                data[a] = buf[i];
                ++a;
                ++i;
            }
        }
    }
}

void introspectivesort(int* data, int* buf, int first, int last) {

    int maxdepth = log2(last);
    introsort(data, buf, first, last, maxdepth);
   // Insertion_Sort(data, last - first + 1);
}


bool checkIfCorrect(int* data, int *result,int*Array, int Size)
{
    
    std::copy(data, data + Size, Array);
    std::sort(Array, Array+Size);

    return std::equal(Array, Array+Size,
        result, result+Size);
}

int main()
{

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen1(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<int> dis(1, INT_MAX);

    auto gen = [&dis, &gen1]() {
        return dis(gen1);
    };
  
    int* buf = new int[Size_1M];                       //bufor do obliczen przy scalaniu
    int* ArraytocheckifCorrect = new int[Size_1M];     //bufor do realizacji sprawdzenia poprawnosci tablicy
    srand((unsigned)time(0));                          //tworzenie wartosci losowych
   
    int Random_Element;                                //Losowy element tablicy
    
   

    std::vector<int> nVector{ 10000, 50000, 100000,500000, 1000000 };          //wielkosc tablicy do posortowania
    std::vector<double> SortsType{ 0, 0.25, 0.5, 0.75, 0.95, 0.99, 0.997, -1}; //wektor oznaczjacy % posortowania przed testem (-1 oznacza reverse)
    const int nbOfExperiments = 100;                                           //ilosc eksperymentow

   

   
   


   
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
                    std::sort(Data_copy, Data_copy + HowMuch_sorted);
                }
                if (t == -1)
                {
                    std::sort(Data_copy, Data_copy + n);
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
                    std::sort(Data_copy, Data_copy + HowMuch_sorted);
                }
                if (t == -1)
                {
                    std::sort(Data_copy, Data_copy + n);
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
                    std::sort(Data_copy, Data_copy + HowMuch_sorted);
                }
                if (t == -1)
                {
                    std::sort(Data_copy, Data_copy + n);
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
                cout << "Czas trwania introsort dla 100 tablic posortowanych w " << t * 100 << " % o rozmiarze " << n << " wynosi: " << Sum << endl;
            else
                cout << "Czas trwania introsort dla 100 tablic posortowanych w odwrotnej kolejnosci o rozmiarze " << n << " wynosi: " << Sum << endl;

            delete[] data;
            delete[] Data_copy;

        }

    }


    delete[] buf;
    delete[] ArraytocheckifCorrect;
    
}

