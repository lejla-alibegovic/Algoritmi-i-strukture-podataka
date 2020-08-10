#pragma once
#include <iostream>

class HesiranjeOtvorenoAdresiranje
{
	int max_vel = 10;
	int brojac = 0;
	int* Niz = new int[max_vel];
	bool* Zauzeto = new bool[max_vel];

	int hesfunkcija(int kljuc)
	{
		return kljuc % max_vel;
	}

public:
	HesiranjeOtvorenoAdresiranje()
	{
		for (int i = 0; i < max_vel; ++i)
			Zauzeto[i] = false;
	}

	void Dodaj(int kljuc)
	{
		if (JelPun())
		{
			std::cout << "Greska. Nema mjesta." << std::endl;
			return;
		}

		int p = hesfunkcija(kljuc);

		while (Zauzeto[p])
		{
			p++;
			if (p == max_vel)
				p = 0;
		}

		Niz[p] = kljuc;
		Zauzeto[p] = true;
		brojac++;
	}

	bool Ukloni(int kljuc)
	{
		if (JelPrazan())
		{
			std::cout << "Greska. Nema elemenata." << std::endl;
			return false;
		}

		int p = hesfunkcija(kljuc);

		int pocetnoP = p;
		while (true)
		{
			if (Zauzeto[p] && Niz[p] == kljuc)
			{
				Zauzeto[p] = false;
				brojac--;
				return true;
			}
			p++;
			if (p == max_vel)
				p = 0;

			if (pocetnoP == p)
				return false;
		}
	}

	bool Pretrazi(int kljuc)
	{
		if (JelPrazan())
		{
			std::cout << "Greska. Nema elemenata." << std::endl;
			return false;
		}

		int p = hesfunkcija(kljuc);

		int pocetnoP = p;
		while (true)
		{
			if (Zauzeto[p] && Niz[p] == kljuc)
				return true;
			p++;
			if (p == max_vel)
				p = 0;

			if (pocetnoP == p)
				return false;
		}
	}

	bool JelPrazan()
	{
		return brojac == 0;
	}

	bool JelPun()
	{
		return brojac == max_vel;
	}
};

