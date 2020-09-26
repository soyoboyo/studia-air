#pragma once
#include "funkcje.h"

using namespace std;

void wstawianie(int x, int y, int **tab)
{
	int i = 0, j = 0, k = 0;
	int tmp = 0;

	for (j = 0; j < y; j++) // tablica 1 ... 100
	{
		/***************** SORTOWANIE *****************/
		for (i = 1; i < x; i++)
		{
			tmp = tab[j][i];
			k = i - 1;
			for (k = i - 1;( k >= 0 && tab[j][k] > tmp ); k--)
			{
				tab[j][k + 1] = tab[j][k];
			}
			tab[j][k] = tmp;
		}
		/**********************************************/
	}
}
