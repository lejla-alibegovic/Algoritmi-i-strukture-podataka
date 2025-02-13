#include <iostream>
using namespace std;
//https://www.cs.usfca.edu/~galles/visualization/RadixSort.html

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

void f(int* A, int n, int exp)
{
	int counter[10]  = {0};
	int* pomocni = new int[n];

	//1. faza
	for (int i = 0; i<n; i++)
	{
		int b = A[i];
		int c = (b / exp) % 10;
		counter[c]++;
	}

	//2. faza
	for (int i = 1; i <= 9; ++i)
	{
		counter[i] += counter[i - 1];
	}

	//3. faza
	for (int i = n - 1; i >= 0; --i)
	{
		int b = A[i];
		int c = (b / exp) % 10;
		int& p = counter[c];
		p--;
		pomocni[p] = b;
	}

	//4. faza
	for (int i = 0; i < n; i++)
	{
		A[i] = pomocni[i];
	}
}


void Sortiraj(int* A,  int n)
{
	int maxV = GetMax(A, n);
	//maxV = 49;

	int exp = 1;

	while(maxV>0)
	{
		f(A, n, exp);
		exp = exp * 10;
		maxV = maxV / 10;
	}

}

int main()
{
	int A[]  {5,9,4,  8, 353,2, 5, 9, 7, 55, 10, 98 ,44, 11, 87, 98, 14, 66};
	int n = sizeof(A) / sizeof(A[0]);

	Sortiraj(A, n);

	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << "-";
	}

    system("pause");
}
