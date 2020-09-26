#include "funkcje.h"

using namespace std;


void quicksort(int x, int y, int **tab, int lewy, int prawy, int j)
{

	int i, pivot, k;
	
		//cout << " " << j << " " << endl;
			/***************** SORTOWANIE *****************/
			i = (lewy + prawy) / 2;
			pivot = tab[j][i]; tab[j][i] = tab[j][prawy];
			for (k = i = lewy; i < prawy; i++)
				if (tab[j][i] < pivot)
				{
					swap(tab[j][i], tab[j][k]);
					k++;
				}
			tab[j][prawy] = tab[j][k]; 
			tab[j][k] = pivot;
			if (lewy < k - 1)  
				quicksort(x, y, tab, lewy, k - 1, j);
			if (k + 1 < prawy) 
				quicksort(x, y, tab, k + 1, prawy, j);
			/**********************************************/

}