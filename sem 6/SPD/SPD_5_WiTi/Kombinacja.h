#pragma once
#include "Zadanie.h"

using namespace std;

class Kombinacja
{
public:

	vector <Zadanie> podzbior; // zadania w danej kombinacji
	int ilosc; // wielkoœæ podzbioru
	int kara; // kara za wszystkie spoznienia
	int T; // czas wykonania wszystkich zadan
	int ostatnie; // ostatnie zadanie w permuatcji

	int policz_T(); // wylicza T dla danej kombinacji

	Kombinacja();
	~Kombinacja();
};

