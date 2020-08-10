#pragma once

#include "Osoba.h"
typedef Osoba* Tip;
struct Cvor
{
	Tip info;
	Cvor* link;

	Cvor(Tip i , Cvor* n)
	{
		info = i;
		link = n;
	}
};