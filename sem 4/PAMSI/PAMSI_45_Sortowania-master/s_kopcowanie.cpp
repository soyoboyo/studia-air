#pragma once
#include "funkcje.h"

using namespace std;

// funkcja pomocnicza
void heapify(int **tab, int x, int y, int j, int n, int i);

void kopcowanie(int **tab, int x, int y)
{
	int j;

	for (j = 0; j < y; j++) // tablice 1 ... 100
	{
		// stwórz kopiec
		for (int i = x / 2 - 1; i >= 0; i--)
			heapify(tab, x, y, j, x, i);

		// pobieraj elemnty pojedynczo
		for (int i = x - 1; i >= 0; i--)
		{
			// przenieœ wartoœæ na koneic
			swap(tab[j][0], tab[j][i]);

			// zmniejszanie kopca
			heapify(tab, x, y, j, i, 0);
		}
	}

}

// funckja pomocnicza
void heapify(int **tab, int x, int y, int j, int n, int i)
{
	int najwiekszy = i;  // Initialize najwiekszy as root
	int lewy = 2 * i + 1;  // lewy = 2*i + 1
	int prawy = 2 * i + 2;  // prawy = 2*i + 2

	// jezeli wartoœæ lewej ga³êzi jest wiêksza ni¿ korzeñ
	if (lewy < n && tab[j][lewy] > tab[j][najwiekszy])
		najwiekszy = lewy;

	// je¿eli wartoœæ prawej ga³êzi jest wiêksza ni¿ korzeñ
	if (prawy < n && tab[j][prawy] > tab[j][najwiekszy])
		najwiekszy = prawy;

	// je¿eli korzeñ nie ma najwiêkszej wartosci
	if (najwiekszy != i)
	{
		swap(tab[j][i], tab[j][najwiekszy]);

		// wywoalnie reukrencyjne
		heapify(tab, x, y, j, n, najwiekszy);
	}
}

