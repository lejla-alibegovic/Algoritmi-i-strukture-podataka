#pragma once
#include <iostream>
#include "Cvor.h"
using namespace std;

struct StekSekv		// sekvencijalni stek,iste funkcije kao dodaj i ukloni zadnji kod sekvencijalne liste
{
	int max_size = 10;
	Tip *niz = new Tip[max_size];
	int brojac = 0;

	void DodajNaVrh(Tip x)
	{
		if (brojac != max_size)
			niz[brojac++] = x;
	}

	void Print()
	{
		for (size_t i = 0; i < brojac; i++)
		{
			cout << niz[i]->id << " | " << niz[i]->ime << endl;
		}
	}

	bool ImaElemenata()
	{
		return !JelPrazno();
	}

	bool JelPrazno()
	{
		return brojac == 0;
	}

	Tip UkloniSaVrha()
	{
		brojac--;
		Tip x = niz[brojac];
		return x;
	}
};