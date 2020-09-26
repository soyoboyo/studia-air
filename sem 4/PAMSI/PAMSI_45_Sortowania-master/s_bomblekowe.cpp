#pragma once
#include "funkcje.h"


void bombelkowe(int x, int y, int **tab)
{
	int i = 0, j = 0, k = 0;
	int tmp = 0;

	for (j = 0; j < y; j++) // tablica 1 ... 100
	{
		/***************** SORTOWANIE *****************/
		for (k = 0; k < x; k++)
		{
			for (i = 0; i < x-1; i++)
			{
				if (tab[j][i] > tab[j][i+1])
				{
					tmp = tab[j][i];
					tab[j][i] = tab[j][i + 1];
					tab[j][i + 1] = tmp;
				}
			}
		}
		/**********************************************/
	}
}