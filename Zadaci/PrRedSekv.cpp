#include<iostream>
#include<exception>
#include<cmath>
using namespace std;

/*
Elementi prioritetnog reda predstavljaju tačke u koordinatnom sistemu(u 2D prostoru).
Implementirajte kompletan Prioriteni red(sekvencijalna reprezentacija).Funkcija ukloni treba da ukloni tačku koja se nalazi najbliže tački A(5, 5).
*/


class Tacka2D {
	int x, y;

public:
	Tacka2D(int xx = 0, int yy = 0) :x(xx), y(yy) {}
	int getX()const { return x; }
	int getY()const { return y; }
	friend ostream& operator<<(ostream&, const Tacka2D&);
};
ostream& operator<<(ostream& COUT, const Tacka2D& t) {
	cout << "X: " << t.x << " - Y: " << t.y;
	return COUT;
}
class PrRedSek {
	Tacka2D* N;
	int max, brojac;
	int udaljenost(Tacka2D& t) {
		return (int)sqrt(pow(5 - t.getX(), 2) + pow(5 - t.getY(), 2));
	}

public:
	PrRedSek(int max = 5) {
		this->max = max;
		brojac = 0;
		N = new Tacka2D[max];
	}
	void dodaj(const Tacka2D& t) {
		if (JelPun())
			return;
		N[brojac++] = t;
	}
	void Ukloni() {
		if (JelPrazan())
			return;
		int najblizaI = 0;
		int najblizaV = udaljenost(N[0]);
		for (int i = 1; i < brojac; i++) {
			if (udaljenost(N[i]) < najblizaV) {
				najblizaI = i;
				najblizaV = udaljenost(N[i]);
			}
		}
		brojac--;
		N[najblizaI] = N[brojac];
	}
	bool JelPrazan() { return brojac == 0; }
	bool JelPun() { return brojac == max; }
	void Ispis() {
		for (int i = 0; i < brojac; i++)
			cout << N[i] << " udaljenost je " << udaljenost(N[i]) << endl;
	}

};
void main() {
	PrRedSek pr;
	pr.dodaj(Tacka2D(8, 2));
	pr.dodaj(Tacka2D(3, 9));
	pr.dodaj(Tacka2D(5, 7));
	pr.dodaj(Tacka2D(15, 1));
	cout << "\n------------------------------------------------------------\n";
	pr.Ispis();
	cout << "\n------------------------------------------------------------\n";
	pr.Ukloni();
	pr.Ispis();
}
