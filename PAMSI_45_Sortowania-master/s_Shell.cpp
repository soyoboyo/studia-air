#include "funkcje.h"

using namespace std;

void Shell_sort(int **tab, int y, int x) {
	
	int gap, tmp, i = 0, j = 0, k;

	for (j = 0; j < y; j++) // kazdy wiersz
	{
		/*************************************/
		for (gap = x / 2; gap > 0; gap /= 2)
		{
			for (i = gap; i < x; i++)
			{
				tmp = tab[j][i];

				for (k = i; k >= gap && tab[j][k - gap] > tmp; k -= gap)
					tab[j][k] = tab[j][k - gap];

				tab[j][k] = tmp;
			}
		}
		/****************************************/
	}
}