#include <iostream>
using namespace std;


/*
Elementi prioritetnog reda predstavljaju ta?ke u koordinatnom sistemu (u 2D prostoru).
Implementirajte kompletan Prioriteni red (povezana reprezentacija). Funkcija ukloni treba da ukloni ta?ku koja se nalazi najbliže ta?ki A(10,-5).
Code mora biti funkcionalan - bez grešaka kompajliranja i runtime grešaka.

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
typedef Tacka2D Tip;
class Cvor {
public:
	Cvor* next;
	Tip vrijednost;
public:
	Cvor(Cvor* next, Tip vrijednost) {
		this->next = next;
		this->vrijednost = vrijednost;
	}
};
struct PrioritetniRedPov
{
	Cvor* prvi;
	int udaljenost(Tip t) { return (int)sqrt(pow(10 - t.getX(), 2) + pow(-5 - t.getY(), 2)); }
public:
	PrioritetniRedPov() { prvi = nullptr; }
	void Dodaj(Tip t) {
		Cvor* temp = prvi;
		Cvor* novi = new Cvor(nullptr, t);
		Cvor* pt = nullptr;

		while (temp != nullptr) {
			if (udaljenost(temp->vrijednost) < udaljenost(t)) {
				break;
			}
			pt = temp;
			temp = temp->next;
		}
		if (pt == nullptr)
			prvi = novi;
		else
			pt->next = novi;

		novi->next = temp;
	}
	bool JelPrazan() { return prvi == nullptr; }
	Tacka2D Ukloni() {
		Cvor* temp = prvi;
		Tacka2D vrijednost = temp->vrijednost;
		prvi = prvi->next;
		delete temp;
		return vrijednost;
	}
	void print() {
		Cvor* temp = prvi;
		while (temp != nullptr) {
			cout << temp->vrijednost << endl;
			temp = temp->next;
		}
		cout << endl;
	}
};
void main() {
	PrioritetniRedPov* r = new PrioritetniRedPov;
	r->Dodaj(Tacka2D(5, 6));
	r->Dodaj(Tacka2D(7, -6));
	r->Dodaj(Tacka2D(8, 7));
	r->print();
	r->Ukloni();
	cout << "-----------------------\n";
	r->print();

}