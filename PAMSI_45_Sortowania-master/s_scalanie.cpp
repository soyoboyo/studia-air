#pragma once
#include "funkcje.h"

using namespace std;

// funckja scala 2 tablice
// pierwsza po³ówka LEWA[l..m]
// druga po³ówka PRAWA[m+1..r]
void scal(int **tab, int x, int y, int j, int lewy, int srodek, int  prawy)
{
	int i, k, m;
	int roz1 = srodek - lewy + 1;
	int roz2 = prawy - srodek;

	// tablice pomocnicze
	int *LEWA = new int[roz1];
	int *PRAWA =  new int[roz2];

	
	// kopiowanie wartoœci do tablic pomocniczych
	for (i = 0; i < roz1; i++)
		LEWA[i] = tab[j][lewy + i];
	for (k = 0; k < roz2; k++)
		PRAWA[k] = tab[j][srodek + 1 + k];

	// scalanie tablic
	i = 0; // pocz¹tkowy indeks pierwszej po³ówki
	k = 0; // oocz¹tkowy indeks drugiej po³ówki
	m = lewy; // pocz¹tkowy indeks scalonej tablicy
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

	// kopiuj pozosta³e elementy z LEWA, je¿eli s¹ jakieœ
	while (i < roz1)
	{
		tab[j][m] = LEWA[i];
		i++;
		m++;
	}

	
	// kopiuj pozosta³e elementy z PRAWA, je¿eli s¹ jakieœ
	while (k < roz2)
	{
		tab[j][k] = PRAWA[k];
		k++;
		m++;
	}
	delete LEWA; delete PRAWA;
}


// lewy to indeks lewej po³ówki
// prawy to indeks prawej po³ówki
void scalanie(int **tab, int x, int y, int j, int lewy, int prawy)
{
	if (lewy < prawy)
	{
		
		int srodek = lewy + (prawy - lewy) / 2;

		// sortuj pierwsze i drugie po³ówki
		scalanie(tab, x, y, j, lewy, srodek);
		scalanie(tab, x, y, j, srodek + 1, prawy);

		scal(tab, x, y, j, lewy, srodek, prawy);
	}
}