#pragma once
struct Ivica
{
	int startVrh;
	int endVrh;
	int tezina;

	Ivica(int start_vrh, int end_vrh, int tezina)
		: startVrh(start_vrh),
		  endVrh(end_vrh),
		  tezina(tezina)
	{
	}
};