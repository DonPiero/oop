#pragma once
#include <initializer_list>
class Sort
{
    int* v, n;
public:
    Sort(int count, int mini, int maxi);
    Sort(std::initializer_list<int> Nume);
    Sort(int count, int a[]);
    Sort(int count, ...);
    Sort(const char* s);
    ~Sort();
    void InsertSort(bool ascendent = false);
    int partition(int low, int high, bool ascending);
    void quickSort(int low, int high, bool ascending);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
