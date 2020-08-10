#pragma once
#include <string>
using namespace std;

struct Osoba
{
	int id;
	string ime;
	Osoba(int id, string ime)
	{
		this->ime = ime;
		this->id = id;
	}
};
