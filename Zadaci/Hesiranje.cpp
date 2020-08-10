#include <iostream>
using namespace std;
/*
U klasi HashingOtvorenoAdresiranje implementirajte dvostruko otvoreno heširanje sa funkcijom koja minimizira koliziju - h(k, i).
Ulaz u hash funkciju čiji je tacka u 3D prostoru (objekat klase Tacka3D).
*/
class Tacka3D {
public:
	int a, b, c;


	bool operator == (Tacka3D t) {
		return a == t.a && b == t.b && c == t.c;
	}
};
typedef Tacka3D Tip;
int hash1(Tacka3D t) {
	return sqrt(pow(t.a + t.b + t.c, 2));
}
int hash2(Tacka3D t) {
	return sqrt(pow(t.a, 2) / 3 + pow(t.b, 2) / 3 + pow(t.c, 2) / 3);
}
class HashingOtvorenoAdresiranje {
	Tip* niz;
	int max;
	int brojac;
	bool* zauzeto;
	int hashFunkcija(Tacka3D t, int brojPokusaja) {
		return (hash1(t) + brojPokusaja * hash2(t)) % max;
	}
public:
	HashingOtvorenoAdresiranje(int max)
	{
		this->max = max;
		brojac = 0;
		niz = new Tip[max];
		zauzeto = new bool[max] {false};
	}
	void Dodaj(Tip t) {
		if (brojac == max) {
			throw exception("Hash tabela je puna");
		}
		int i = 0;
		int p;
		while (true) {
			i++;
			p = hashFunkcija(t, i);
			if (!zauzeto[p])
				break;
		}
		niz[p] = t;
		zauzeto[p] = true;
		brojac++;
	}
	bool Ukloni(Tip t) {
		if (brojac == 0) {
			throw exception("Hash tabela je puna");
		}
		int i = 0;
		int p;
		while (true) {
			i++;
			p = hashFunkcija(t, i);
			if (zauzeto[p] && niz[i] == t) {
				zauzeto[p] = false;
				brojac--;
				return true;
			}
		}
		return false;

	}


};
void main() {


	system("pause");
}
