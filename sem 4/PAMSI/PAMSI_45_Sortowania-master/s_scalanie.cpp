#pragma once
#include "funkcje.h"

using namespace std;

// funckja scala 2 tablice
// pierwsza po��wka LEWA[l..m]
// druga po��wka PRAWA[m+1..r]
void scal(int **tab, int x, int y, int j, int lewy, int srodek, int  prawy)
{
	int i, k, m;
	int roz1 = srodek - lewy + 1;
	int roz2 = prawy - srodek;

	// tablice pomocnicze
	int *LEWA = new int[roz1];
	int *PRAWA =  new int[roz2];

	
	// kopiowanie warto�ci do tablic pomocniczych
	for (i = 0; i < roz1; i++)
		LEWA[i] = tab[j][lewy + i];
	for (k = 0; k < roz2; k++)
		PRAWA[k] = tab[j][srodek + 1 + k];

	// scalanie tablic
	i = 0; // pocz�tkowy indeks pierwszej po��wki
	k = 0; // oocz�tkowy indeks drugiej po��wki
	m = lewy; // pocz�tkowy indeks scalonej tablicy
	while (i < roz1 && k < roz2)
	{
		if (LEWA[i] <= PRAWA[k])
		{
			tab[j][m] = LEWA[i];
			i++;
		}
		else
		{
			tab[j][m] = PRAWA[k];
			k++;
		}
		m++;
	}

	// kopiuj pozosta�e elementy z LEWA, je�eli s� jakie�
	while (i < roz1)
	{
		tab[j][m] = LEWA[i];
		i++;
		m++;
	}

	
	// kopiuj pozosta�e elementy z PRAWA, je�eli s� jakie�
	while (k < roz2)
	{
		tab[j][k] = PRAWA[k];
		k++;
		m++;
	}
	delete LEWA; delete PRAWA;
}


// lewy to indeks lewej po��wki
// prawy to indeks prawej po��wki
void scalanie(int **tab, int x, int y, int j, int lewy, int prawy)
{
	if (lewy < prawy)
	{
		
		int srodek = lewy + (prawy - lewy) / 2;

		// sortuj pierwsze i drugie po��wki
		scalanie(tab, x, y, j, lewy, srodek);
		scalanie(tab, x, y, j, srodek + 1, prawy);

		scal(tab, x, y, j, lewy, srodek, prawy);
	}
}