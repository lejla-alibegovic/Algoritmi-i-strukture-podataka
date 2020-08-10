#pragma once

#include <iostream>
#include "BSCvor.h"
using namespace std;

template <class Kljuc>
class BinarnoStabloZaPretrazivanje
{
	void rekurzija_ReciklirajStablo(BSCvor<Kljuc>*&  cvor)
	{
		if (cvor != nullptr)
		{
			rekurzija_ReciklirajStablo(cvor->lijevoDijete);
			rekurzija_ReciklirajStablo(cvor->desnoDijete);
			delete cvor;
			cvor = nullptr;
		}
	}
	BSCvor<Kljuc>* rekurzija_Trazi(BSCvor<Kljuc>* &cvor, Kljuc value)
	{
		if (cvor == nullptr)
			return nullptr;

		if (IsJednako(cvor->value, value))
			return cvor;
		if (IsVece(cvor->value, value))//ili IsManje(value, cvor->value)
			return rekurzija_Trazi(cvor->lijevoDijete, value);
		else
			return rekurzija_Trazi(cvor->desnoDijete, value);
	}

	bool rekurzija_Dodaj(BSCvor<Kljuc>* &cvor, Kljuc value)
	{

		if (cvor == nullptr)
		{
			cvor = new BSCvor<Kljuc>(value);
			return true;
		}

		if (IsJednako(cvor->value,  value))
			return false;

		if (IsVece(cvor->value, value))	//ako je korjen veci od value poziva se rekurzija za lijevo dijete
		{
			if(cvor->lijevoDijete == nullptr)
				cvor->lijevoDijete = new BSCvor<Kljuc>(value);
			else
				rekurzija_Dodaj(cvor->lijevoDijete, value);
		}
		else
		{
			if(cvor->desnoDijete == nullptr)
				cvor->desnoDijete = new BSCvor<Kljuc>(value);
			else
				rekurzija_Dodaj(cvor->desnoDijete, value);
		}
		return true;
	}

public:

	BSCvor<Kljuc>*	korijen;
	
	BinarnoStabloZaPretrazivanje()
	{
		korijen = nullptr;
	}

	bool dodaj(Kljuc value)
	{
		return rekurzija_Dodaj(korijen, value);
	}

	void reciklirajStablo()
	{
		rekurzija_ReciklirajStablo(korijen);
	}

	BSCvor<Kljuc>* trazi(Kljuc value)
	{
		return rekurzija_Trazi(korijen, value);
	}

	bool sadrzi(Kljuc value)
	{
		return trazi(value) != nullptr;
	}

};