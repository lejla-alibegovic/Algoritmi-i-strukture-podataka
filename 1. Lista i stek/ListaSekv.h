#pragma once
#include <iostream>
#include <exception>
#include "Osoba.h"
using namespace std;

struct ListaSekv		// sekvencijalna lista
{
	int max_size = 10;
	Tip *niz = new Tip[max_size];
	int brojac = 0;

	void DodajPrvi(Tip x)
	{
		for (size_t i = 1; i < brojac; i++)
		{
			niz[i] = niz[i - 1];	//	pomjeramo unaprijed niz
		}
		niz[0] = x;
		brojac++;
	}

	void DodajZadnji(Tip x)
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

	Tip UkloniPrvi()
	{
		if (JelPrazno())
		{
			throw exception("Greska");
			return nullptr;
		}
		Tip x = niz[0];
		for (int i = 1; i < brojac; i++)
		{
			niz[i - 1] = niz[i];	// pomjeramo niz unazad
		}
		brojac--;
		return x;
	}

	Tip UkloniZadnji()
	{
		if (JelPrazno())
		{
			throw exception("Greska");
			return nullptr;
		}
		brojac--;
		Tip x = niz[brojac];
		return x;
	}
};