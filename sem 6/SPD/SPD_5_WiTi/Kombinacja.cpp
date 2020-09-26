#pragma once
#include "Kombinacja.h"


using namespace std;

// funkcja dodaje czasy wykonania wszystkich zadañ w kombinacji
int Kombinacja::policz_T()
{
	int i;
	T = 0;

	for (i = 0; i < ilosc; i++)
	{
		T += podzbior[i].p;
	}
	return T;
}

Kombinacja::Kombinacja() : kara(0), ilosc(0), T(0), ostatnie(0) {}

Kombinacja::~Kombinacja() {}
