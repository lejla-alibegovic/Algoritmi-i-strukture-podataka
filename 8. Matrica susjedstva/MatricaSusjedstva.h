#pragma once
#include <iostream>
#include <fstream>
#include "ListaSekv.h"
#include "Ivica.h"
using namespace std;

struct MatricaSusjedstva
{
public:
	int** matrica = new int*[20];
	const int _velicina;
	MatricaSusjedstva(int velicina):_velicina(velicina)
	{
		for (int i = 0; i < velicina; i++)
		{
			matrica[i] = new int[velicina];
			for (int j = 0; j < velicina; j++)
			{
				matrica[i][j] = 0;
			}

		}
	}
	void Ucitaj(string nazivFajla){
		int varijabla;
		ifstream fajl(nazivFajla);
		for (size_t i = 0; i < _velicina; i++) {
			for (size_t j = 0; j < _velicina; j++) {
				fajl >> varijabla;
				matrica[i][j] = varijabla;
			}
		}
		fajl.close();
	}

	void IspisMatrice()
	{
		for (int i=0; i < _velicina; i++)
		{
			for (int j = 0; j< _velicina; j++)
			{
				cout  << matrica[i][j] << " ";
			}
			cout << endl;
		}
	}

	int IzlazniStepenMax()
	{
		int maxI = 0;
		int maxV = IzlazniStepen(maxI);
		for (int i = 1; i < _velicina; i++)
		{
			int t = IzlazniStepen(i);
			if (maxV < t)
			{
				maxV = t;
				maxI = i;
			}
		}
		return maxI;
	}

	int UlazniStepenMax()
	{
		int maxI = 0;
		int maxV = UlazniStepen(maxI);
		for (int i = 1; i < _velicina; i++)
		{
			int t = UlazniStepen(i);
			if (maxV < t)
			{
				maxV = t;
				maxI = i;
			}
		}
		return maxI;
	}

	int UlazniStepen(int j)
	{
		//primaoci
		int suma = 0;
		for (int i = 0; i < _velicina; ++i)
		{
			suma += matrica[i][j];
		}
		return suma;
	}

	int IzlazniStepen(int i)
	{
		int suma = 0;
		for (int j = 0; j < _velicina; ++j)
		{
			suma += matrica[i][j];
		}
		return suma;
	}

	bool JelSusjed(int from, int to)
	{
		return matrica[from][to] != 0;
	}

	Lista<int>* SusjediTo(int x)
	{
		Lista<int>* obj = new ListaPov<int>;
		for (int i = 0; i < _velicina; i++) {
			if (JelSusjed(i, x)) {
				obj->DodajNaKraj(i);
			}
		}
		return obj;
	}

	Lista<int>* SusjediFrom(int x)
	{
		Lista<int>* obj = new ListaPov<int>;
		for (int i = 0; i < _velicina; i++) {
			if (JelSusjed(x, i)) {
				obj->DodajNaKraj(i);
			}
		}
		return obj;
	}

	int tezina(int from, int to)
	{
		return matrica[from][to];
	}

	int najbliziSusjedTo(int x)
	{
		Lista<int>* susjedi_to = SusjediTo(x);

		if (susjedi_to->getBrojac() == 0)
			throw exception("greska. nema susjeda");

		int minS = -1;
		int minTezina = INT_MAX;

		while(!susjedi_to->JeLiPrazna())
		{
			int s = susjedi_to->UkloniSaKraja();
			int t = tezina(s, x);

			if (t < minTezina)
			{
				minTezina = t;
				minS = s;
			}
		}

		return minS;
	}

	pair<Lista<int>**, int> NapraviPovezanuListuSusjedstva()
	{
		Lista<int>** listaSusjedstva = new Lista<int>*[_velicina];

		for (int i = 0; i < _velicina; ++i)
		{
			listaSusjedstva[i] = SusjediFrom(i);
		}

		return make_pair(listaSusjedstva, _velicina);
	}
};