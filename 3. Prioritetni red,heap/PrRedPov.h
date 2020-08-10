#pragma once
#include <iostream>
#include "Cvor.h"
using namespace  std;


struct PrRedPov {		// sortirana i nesortirana implementacija,n citanja + n/2 pisanja
						// SORTIRANO: Dodavanje -> O()n  || Uklanjanje -> O(1),za nesortirano obrnuto
	Cvor* prvi = nullptr;	// isto kao stek povezano,osim dodaj

	void Dodaj(Tip x){
		Cvor *t = prvi;
		Cvor *b = nullptr;

		while (t != nullptr) {
			if (t->info < x) {
				break;
			}
			b = t;
			t = t->next;
		}
		Cvor *n = new Cvor(x, t);
		if (b == nullptr) {
			prvi = n;
		}
		else{
			b->next = n;
		}
	}
	Tip Ukloni(){
		if (JeLiPrazna()){
			cout << "Greska !" << endl;
			return 0;
		}

		Cvor* t = prvi;
		prvi = prvi->next;
		Tip x = t->info;
		delete t;
		return x;
	}

	void Print(){
		Cvor * t = prvi;
		while (t != nullptr)
		{
			cout << t->info << endl;
			t = t->next;
		}
	};


	bool JeLiPrazna() { return (prvi == nullptr); }
};

