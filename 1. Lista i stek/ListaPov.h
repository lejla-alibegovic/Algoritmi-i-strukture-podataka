#pragma once
#include <iostream>
#include "Cvor.h"
using namespace std;

struct ListaPov		//	povezana lista
{
	Cvor *prvi = nullptr;

	void DodajPrvi(Tip x)
	{
		Cvor *noviPrvi = new Cvor(x, prvi);		//kreiramo temp varijablu koja ce pokazivati na prvi clan
		prvi = noviPrvi;
	}

	void DodajZadnji(Tip x)
	{
		Cvor * t = prvi;		// pravimo temp koji ce zapamtiti adresu prvog

		if (t == NULL){		// ako je zadnji ujedno i prvi
			prvi = new Cvor(x, NULL);
			return;
		}

		while (t->link != NULL) {	// idemo do kraja cvora
			t = t->link;
		}

		Cvor * novi = new Cvor(x, NULL);	// alociramo novi zadnji
		t->link = novi;			// stari zadnji pokaziva na novi zadnji	
	}

	void Print()
	{	
		Cvor * t = prvi;
		
		while (t != NULL) {		// stavljamo samo da je t razlicito od null,ako stavimo t->link ne bi ispisalo zadnji
			cout << t->info->id << " | " << t->info->ime << endl;
			t = t->link;
		}

	}

	bool ImaElemenata()
	{
		return !JelPrazno();
	}

	bool JelPrazno()
	{
		return prvi == nullptr;
	}

	Tip UkloniPrvi()
	{
		if (JelPrazno())
		{
			cout << "Greska. Ne mozete ukloniti element iz prazne liste." << endl;
			return nullptr;
		}
		Cvor* stariPrvi = prvi;

		prvi = prvi->link;		// prvi stavljamo da je naredni,to jest onaj na kojega je on pokazivao
		Tip t = stariPrvi->info;

		delete stariPrvi;

		return t;
	}

	Tip UkloniZadnji()
	{
		if (JelPrazno())
		{
			cout << "Greska. Ne mozete ukloniti element iz prazne liste." << endl;
			return nullptr;
		}
		Cvor * t = prvi;
		
		Cvor * pretT = nullptr;

		while (t->link != NULL) {
			pretT = t;		// zapamtimo onoga prije zadnjeg
			t = t->link;
		}

		Tip x = t->info;

		pretT->link = nullptr;	// predzanji ce sada pokazivati na nullptr i on ce sada postati zadnji

		return x;
	}
};