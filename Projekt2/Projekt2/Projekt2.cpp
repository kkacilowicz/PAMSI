// Projekt2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <chrono>
#include <cmath>
#include <ctime>
#include "SLinkedList.h"
#include "Heap.h"

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

int Choose_pivot(int* data, int first, int last) {
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

//sortuje malejaco
int  partition_Lomuto(int* data, int left, int right) {

    int pivot = Choose_pivot(data,left,right);
    int i = left;

    for (int j = left; j < right; j++)
    {
        if (data[j] >= pivot)
        {
            swap(data[i], data[j]);
            i++;
        }
        
    }
    swap(data[i], data[right]);

    return i;
}   

void quicksort(int* data, int left, int right) {

    if (left < right) {
        int p;
        p= partition_Lomuto(data, left, right);
        quicksort(data, left, p-1);
        quicksort(data, p + 1, right);
    }
    
}

void heapsort(int* data, int Size) {

    Heap Hp(data, Size + 1);
    Hp.BuildHeap();
    for (int i = 1; i < Size + 1; i++)
    {
        data[i] = Hp.RemoveRoot();
    }
}



void introsort(int* data, int first, int last, int maxdepth) {

    int n = last;

    if (n <= 1)
    {
        return;
    }
    else if (maxdepth == 0)
    {
        heapsort(data, last);
    }
    else
    {
        int p;
        p = partition_Lomuto(data, first, last);
        introsort(data, first, p - 1, maxdepth - 1);
        introsort(data, p, last, maxdepth - 1);
    }

}

void introspectivesort(int* data, int first, int last) {

    int maxdepth = log2(last);
    introsort(data, first, last, maxdepth);

}



int main()
{
    int SIZE = 10;

    srand((unsigned)time(0));               //tworzenie wartosci losowych
   
    int Random_Element;

    int* buf = new int[SIZE];

    int* data = new int[SIZE+1];            //tak tworzymy dla heapsort
    for (int i = 0; i < SIZE; i++)
    {
        Random_Element = rand() ;
        data[i+1] = Random_Element;
    }
 
    
    chrono::steady_clock sc;   // create an object of `steady_clock` class
    auto start = sc.now();     // start timer

    heapsort(data, SIZE);
   
    auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
    auto time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
    cout << "Operation took: " << time_span.count() << " seconds !!!" << endl;;
 
    
    for (int i = 0; i < SIZE; i++)
    {
        cout << data[i+1] << endl;
    } /*
    for (int i = 0; i < SIZE; i++)
    {
        cout << data[i] << endl;
    }
    */
}

