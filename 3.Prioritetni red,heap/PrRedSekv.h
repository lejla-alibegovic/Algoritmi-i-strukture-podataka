#pragma once
#include "Cvor.h"
//prioritetni red
struct PrRedSekv {		//nesortirani niz je bolji nacin za sekvencijalnu reprezentaciju pr. reda sekv.,n citanja

	int max_size = 13;
	Tip* N = new Tip[max_size];
	int brojac = 0;		//identicno kao stekSekv,osim funkcije ukloni

	void Dodaj(Tip x){
		if (JeLiPuna()){
			cout << "Greska.Red je pun!" << endl;
			return;
		}
		N[brojac++] = x;
	}

	Tip Ukloni(){
		if (JeLiPrazna()){
			cout << "Greska.Red je prazan.";
			return 0;
		}

		Tip maxV = N[0];
		int maxI = 0;

		for (size_t i = 1; i < brojac; i++){
			if (N[i] > maxV) {
				maxV = N[i];
				maxI = i;
			}
		}
		brojac--;
		N[maxI] = N[brojac];
		return maxV;
	}

	bool JeLiPrazna() { return (brojac == 0); }

	bool JeLiPuna() { return (brojac == max_size); }

	void Print(){
		for (int i = 0; i < brojac; i++){
			cout << N[i] << endl;
		}
	};
};
