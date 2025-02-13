#include <iostream>
#include "Cvor.h"
#include "ListaPov.h"
#include "ListaSekv.h"
#include "StekSekv.h"
#include "StekPov.h"
#include "PrioriteniRedHeap.h"
#include "PrioriteniRedPov.h"
using namespace std;

//https://www.cs.usfca.edu/~galles/visualization/BucketSort.html

int GetMax(int* A, int n)
{
	int maxV = A[0];

	for (int i = 1; i < n; ++i)
	{
		if (A[i] > maxV)
			maxV = A[i];
	}

	return maxV;
}

void Sortiraj(int A[], int n)
{
	PrioriteniRedPov* X = new PrioriteniRedPov[n];

	int maxV = GetMax(A, n);
	for (int i = 0; i < n; ++i)
	{
		int value = A[i];
		int p = value * n / (maxV + 1);
		X[p].Dodaj(value);
	}

	int brojac = n-1;
	for (int i = n-1; i >=0; --i)
	{
		PrioriteniRedPov& x = X[i];
		while(!x.JeLiPrazna())
		{
			int value = x.Ukloni();
			A[brojac] = value;
			brojac--;
		}
	}
}

int main()
{
	int A[]{ 5, 9, 4, 8, 353, 2, 5, 9, 7, 55, 10, 98 ,44, 11, 87, 98, 14, 66 };
	int n = sizeof(A) / sizeof(A[0]);

	Sortiraj(A, n);

	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << "-";
	}

	system("pause");
}
