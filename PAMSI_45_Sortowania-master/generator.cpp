#pragma once
#include "generator.h"


using namespace std;

/* 20, 50, 75, 95, 99, 99.7 */

void generator(int rozmiar, int ilosc, int procent, int **tab, char o)
{
	srand(time(0)); // resetowanie zegara dla liczb losowych

	int i = 0, j = 0;
	float procenty = (float)procent / 10;
	int posortowane = rozmiar * procent / 1000; // do którego momentu ma generowaæ po kolei

	if (o == 'r')
	{
		// generowanie liczb po kolei do okreœlonego momentu
		for (j = 0; j < ilosc; j++) // pêtla dla ka¿dej tablicy
		{
			// kolejne liczby
			for (i = 0; i < posortowane; i++) {
				tab[j][i] = i;
			}

			// losoowo
			for (i = posortowane; i < rozmiar; i++) {
				tab[j][i] = rand() % rozmiar + posortowane;
			}
		}
	} // if 'r'
	else if (o == 'm') {
		for (j = 0; j < ilosc; j++) // pêtla dla ka¿dej tablicy
		{
			// kolejne liczby
			for (i = rozmiar - 1; i >= 0; i--) {
				tab[j][i] = i;
			}
		}
	}

	cout << "Wygenerowano " << ilosc << " tablic o rozmiarze " << rozmiar << " posortowanych w " << procenty << "%" << endl;
}