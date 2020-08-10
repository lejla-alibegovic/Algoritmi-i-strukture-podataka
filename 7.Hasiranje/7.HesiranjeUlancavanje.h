#pragma once
#include "ListaPov.h"

class HesiranjeUlancavanje
{
	int max_vel = 10;
	int brojac = 0;
	ListaPov* Niz = new ListaPov[max_vel];

	int hesfunkcija(int kljuc)
	{
		return kljuc % max_vel;
	}

public:
	HesiranjeUlancavanje()
	{}
	void Dodaj(int kljuc)
	{
		int p = hesfunkcija(kljuc);
		Niz[p].DodajNaKraj(kljuc);
		brojac++;
	}
	bool Ukloni(int kljuc)
	{
		int p = hesfunkcija(kljuc);
		return Niz[p].UkloniByKey(kljuc);
	}
	bool Pretraga(int kljuc)
	{
		int p = hesfunkcija(kljuc);
		return Niz[p].Pretrazi(kljuc);
	}
	bool JelPrazan()
	{
		return brojac == 0;
	}
};