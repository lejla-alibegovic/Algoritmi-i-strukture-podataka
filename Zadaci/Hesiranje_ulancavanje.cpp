#pragma once
#include "ListaPov.h"
#include"Hashiranje.h"

/*
Implementirajte ATP Hashing sa ulančavanjem koristeći datu hash funkciju.
ℎ(𝑘)=√(((𝑥+𝑦+𝑧)^2)/3) 𝑚𝑜𝑑 𝑛

*/
class Tacka3D {
public:
	int a, b, c;
	Tacka3D(int aa = 0, int bb = 0, int cc = 0) {
		a = aa;
		b = bb;
		c = cc;
	}

};
int hes(Tacka3D t) {
	return sqrt((pow(t.a + t.b + t.c, 2)) / 3);
}
class HesiranjeUlancavanjem {
	ListaPov<Tacka3D>* Niz;
	int n;
	int hesfunkcija(Tacka3D& t) {
		return hes(t) % n;
	}
public:
	HesiranjeUlancavanjem(int n = 10) {
		this->n = n;
		Niz = new ListaPov<Tacka3D>[10];
	}
	void dodaj(const Tacka3D& k) {
		int i = hesfunkcija(*const_cast<Tacka3D*>(&k));
		ListaPov<Tacka3D>& lista = Niz[i];
		lista.dodaj(k);
	}
	bool ukloni(const Tacka3D& k) {
		int i = hesfunkcija(*const_cast<Tacka3D*>(&k));
		ListaPov<Tacka3D>& lista = Niz[i];
		return lista.ukloni(k);
	}
	void print() {
		for (int i = 0; i < n; i++)
		{
			cout << "Lista " << i << ": ";
			Niz[i].print();
		}
	}
};

