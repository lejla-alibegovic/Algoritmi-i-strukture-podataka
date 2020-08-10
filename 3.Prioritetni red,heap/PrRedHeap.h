#pragma once
#include "Cvor.h"

class PrioritetniRedHeap {	// BINARNO STABLO //velicina predstavlja broj elemenata ne vel niza
					// Pravilo za HEAP -> RODITELJ UVIJEK MORA BITI VECI OD DJETETA
					// BubbleDown za uklanjanje | BubbleUp za dodavanje
private:

	int n = 0;
	int vel = 13;
	Tip *A = new Tip[vel + 1];

	bool JelKorjen(int i) { return i == 1; }
	bool JelImaLijevoDijete(int i) { return (i * 2) <= n; }
	int LijevoDijetePozicija(int i) { return i * 2; }
	bool JelImaDesnoDijete(int i) { return ((i * 2) + 1) <= n; }
	int DesnoDijetePozicija(int i) { return (i * 2) + 1; }
	bool JelList(int i) { return !JelImaLijevoDijete(i); }
	int RoditeljPozicija(int i) { return i / 2; }

	void RotirajPoReferenci(Tip& x, Tip& y) {
		int z = x;
		x = y;
		y = z;
	}
	void RotirajPoIndeksu(Tip i, Tip j) {
		Tip temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}

	void BubbleUp(int i) {
		if (JelKorjen(i))
			return;
		int r = RoditeljPozicija(i);
		if (A[i] > A[r]) {
			RotirajPoReferenci(A[r], A[i]);
			BubbleUp(r);
		}
	}

	void BubbleDown(int i) {
		if (JelList(i))
			return;
		int l = LijevoDijetePozicija(i);
		if (JelImaDesnoDijete(i))
		{
			int d = DesnoDijetePozicija(i);
			if (A[d] > A[l] && A[d] > A[i])
			{
				RotirajPoIndeksu(d, i);
				BubbleDown(d);
				return;
			}
		}
		else
		{
			if (A[l] > A[i]) {
				RotirajPoIndeksu(l, i);
				BubbleDown(l);
			}
		}
	}

public:

	void Dodaj(Tip x) {
		if (JelPun()) {
			cout << "Niz je pun." << endl;
			return;
		}
		n++;
		A[n] = x;
		BubbleUp(n);
	}

	Tip Ukloni() {
		if (JelPrazan()) {
			cout << "Niz je prazan.";
			return 0;
		}
		Tip x = A[1];
		A[1] = A[n];
		n--;
		BubbleDown(1);
		return x;
	}

	bool JelPun() { return n == vel; }
	bool JelPrazan() { return n == 0; }
};