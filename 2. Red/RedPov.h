#pragma once

#include "Cvor.h"
using namespace std;

struct RedPov		/* Dodaj na kraj ukloni sa pocetka */
{
	Cvor *pocetak = nullptr;
	Cvor *kraj = nullptr;

	void Dodaj(Tip x)
	{
		Cvor *temp = new Cvor(x, nullptr);
		if (!JelPrazan())
			kraj->next = temp;
		else
			pocetak = temp;
		kraj = temp;
	}

	Tip Ukloni()
	{
		if (JelPrazan())
		{
			cout << "Red je prazan" << endl;
			return 0;
		}
		Cvor *temp = pocetak;
		pocetak = pocetak->next;
		Tip x = temp->info;
		delete temp;
		if (pocetak == nullptr)
			kraj = nullptr;

		return x;
	}

	bool JelPrazan()
	{
		return pocetak == nullptr;
	}

	void Print()
	{
		Cvor *t = pocetak;
		while (t != nullptr)
		{
			cout << t->info << endl;
			t = t->next;
		}
	}
};
