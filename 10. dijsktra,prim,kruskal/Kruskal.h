class KruskalAlgoritam
{
private:
	KruskalAlgoritam(MatricaSusjedstva* M)
	{
		//ulazna matrica susjedstva
		grafMatrica = M;

		//PR koji čuva sortirane ivice koje su formirane na osnovu ulazne matrice susjedstva 
		grafIvice = new PrioritetniPov<Ivica*>;

		//ovo je rezultat algoritma (stablo minimalnog raspona, MST)
		stabloIvice = new ListaPov<Ivica*>;

		//pomoća matrica susjedstva za stablo (MST) koja se koristi radi Dfs i Bfs algoritma kod provjere ciklusa	
		stabloMatrica = new MatricaSusjedstva(M->velicina);
	}

	MatricaSusjedstva* grafMatrica;
	PrioritetniRed<Ivica*>* grafIvice;
	Lista<Ivica*>* stabloIvice;
	MatricaSusjedstva* stabloMatrica;

	void pripremiIvice()
	{
		for (int fromVrh = 0; fromVrh < grafMatrica->velicina; fromVrh++)
		{
			for (int toVrh = 0; toVrh < grafMatrica->velicina; toVrh++)
			{
				if (grafMatrica->isSusjed(fromVrh, toVrh))
				{
					int tezina = grafMatrica->tezina(fromVrh, toVrh);
					grafIvice->add(new Ivica(fromVrh, toVrh, tezina));
				}
			}
		}
	}

	bool isCiklus(Ivica* i)
	{
		Lista<int>* lista = BfsAlgoritamIterativno::start(stabloMatrica, i->endVrh);
		return lista->sadrzi(i->startVrh);
	}

	Lista<Ivica*>* _start()
	{
		pripremiIvice();

		int s = 0;

		while (stabloIvice->count() < (grafMatrica->velicina) - 1)
		{
			Ivica* i = grafIvice->ukloni();

			if (!isCiklus(i))
			{
				stabloIvice->dodaj(i);
				stabloMatrica->dodaj(i);
				s += i->tezina;
			}
		}
		cout << "Kruskal Algoritam: MST suma je " << s << endl;

		return stabloIvice;
	}

public:

	static Lista<Ivica*>* start(MatricaSusjedstva* M)
	{
		return KruskalAlgoritam(M)._start();
	}
};
