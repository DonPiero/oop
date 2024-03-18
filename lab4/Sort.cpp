#include "Sort.h";
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cstdarg>
#include <cstring>
#include <initializer_list>
Sort::Sort(int count, int mini, int maxi)
{
	this->v = new int[count];
	this->n = count;
	srand(time(0));
	for (int i = 0; i < count; i++)
		this->v[i] = mini + rand() % (maxi - mini + 1);

}
Sort::Sort(std::initializer_list<int> name)
{
	this->n = name.size();
	v = new int[this->n];
	int i = 0;
	for (auto it = name.begin(); it != name.end(); ++it)
		v[i++] = *it;
	
}
Sort::Sort(int count, int *a)
{
	this->v = new int[count];
	this->n = count;
	for (int i = 0; i < count; i++)
		this->v[i] = a[i];
}
Sort::Sort(int count, ...)
{
	va_list list;
	va_start(list,count);
	this->v = new int[count];
	this->n = count;
	for (int i = 0; i < count; i++)
		this->v[i] = va_arg(list, int);
	va_end(list);


}
Sort::Sort(const char* s)
{
	int n = 0;
	char* aux;
	int k = 0;
	while (s[k] != ',')k++;
	aux = new char[k + 1];
	int count = 1;
	int b = strlen(s);
	for (int i = 0; i < b; i++)
		if (s[i] == ',') count++;
	this->v = new int[count];
	this->n = count;
	int l = 0,i=0;
	for (i = 0; i < b; i++)
	{
		if (s[i] != ',')aux[l++] = s[i];
		else {
			aux[l] = NULL;
			int c = 0;
			for (int j = 0; j < l; j++)
				c= c * 10 + (aux[j] - '0');
			this->v[n++] = c;
			l = 0;
			k = i + 1;
			while (s[k] != ',' && s[k] != '\0') k++;
			delete[] aux;
			aux = new char[k - i];
		}
	}
	aux[l] = NULL;
	int c = 0;
	for (int j = 0; j < l; j++)
		c = c * 10 + (aux[j] - '0');
	delete[] aux;
	this->v[n] = c;

}
void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < GetElementsCount(); i++)
	{
		int key = this->v[i];
		int j = i - 1;

		while (j >= 0 && ((ascendent && this->v[j] > key) || (!ascendent && this->v[j] < key)))
		{
			this->v[j + 1] = this->v[j];
			j = j - 1;
		}
		this->v[j + 1] = key;
	}
}
int Sort::partition(int low, int high, bool ascending) {
	int pivot = v[high];
	int i = low - 1;

	for (int j = low; j < high; ++j) {
		if (ascending ? v[j] <= pivot : v[j] >= pivot) {
			++i;
			int aux1 = this->v[i];
			this->v[i] = this->v[j];
			this->v[j] = aux1;
		}
	}
	
	int aux2 = this->v[i + 1];
	this->v[i + 1] = this->v[high];
	this->v[high] = aux2;
	return i + 1;
}
void Sort::quickSort(int low, int high, bool ascending) {
	if (low < high) {
		int pi = partition(low, high, ascending);
		quickSort(low, pi - 1, ascending);
		quickSort(pi + 1, high, ascending);
	}
}
void Sort::QuickSort(bool ascendent) {
	quickSort(0, GetElementsCount() - 1, ascendent);
}
void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < GetElementsCount()-1; i++)
		for (int j = 0; j < GetElementsCount()-i-1; j++)
			if (ascendent ? v[j] > v[j + 1] : v[j] < v[j + 1])
			{
				int aux = this->v[j];
				this->v[j] = this->v[j+1];
				this->v[j+1] = aux;
			}
			
	
}
Sort::~Sort()
{
	delete[] this->v;
}
void Sort::Print()
{
	for (int i = 0; i < GetElementsCount(); i++)
		printf("%d ", this->v[i]);
	printf("\n");
}
int Sort::GetElementsCount()
{
	return this->n;
}
int Sort::GetElementFromIndex(int index)
{
	return this->v[index];
}
