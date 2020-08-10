#pragma once
#include <iostream>
#include "Cvor.h"
using namespace std;

struct StekPov		//	povezani stek,iste funkcije kao dodaj i ukloni prvi kod povezane liste
{
	Cvor *prvi = nullptr;

	void DodajNaVrh(Tip x)
	{
		Cvor *temp = new Cvor(x, prvi);
		prvi = temp;
	}

	void Print()
	{
		Cvor * t = prvi;

		while (t != NULL) {
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

	Tip UkloniSaVrha()
	{
		if (JelPrazno())
		{
			cout << "Greska. Ne mozete ukloniti element iz prazne liste." << endl;
			return nullptr;
		}
		Cvor* stariP = prvi;

		prvi = prvi->link;
		Tip t = stariP->info;

		delete stariP;

		return t;
	}
};