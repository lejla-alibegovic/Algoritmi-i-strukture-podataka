#pragma once

#include "Cvor.h"
using namespace std;

struct RedSekv		// red sekvencijalno	 /* FIFO */
{
	int max_size = 10;
	int brojac = 0;
	int pocetakReda = 0;
	int krajReda = 0;
	Tip* niz = new Tip[max_size];

	void Dodaj(Tip x)	/* O(n) -> vrijeme izvršavanja */ /* broj koraka = vrijeme izvršavanja */
	{						
		if (JelPun()) {
			cout << "Red je pun" << endl;
			return;
		}
		brojac++;
		if (krajReda == max_size)
			krajReda = 0;
		niz[krajReda] = x;
		krajReda++;
	}

	Tip Ukloni()	/* O(1) */
	{
		if (JelPrazan())
		{
			cout << "Red je prazan" << endl;
			return 0;
		}
		Tip temp = niz[pocetakReda];
		pocetakReda++;
		brojac--;
		if (pocetakReda == max_size)
			pocetakReda = 0;
		return temp;
	}

	bool JelPrazan()
	{
		return brojac == 0;
	}

	bool JelPun()
	{
		return brojac == max_size;
	}

	void Print()
	{
		int t = pocetakReda;

		for (size_t i = 0; i < brojac; i++)
		{
			cout << niz[t++] << endl;
			if (t == max_size)
				t = 0;
		}
	}
};