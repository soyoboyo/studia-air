#pragma once
#include "Schrage.h"

using namespace std;

class Carlier : public Schrage
{
public:
	Carlier();
	~Carlier();

	Zadanie PI_opt[2000];
	int U; // warto�� funkcji celu Cmax
	int UB; // g�rne oszacowanie, upper bound
	int LB; // dolne oszacowanie, lower bound

	int a; // numer pierwszego zadania w bloku K
	int b; // numer ostatniego zadania w bloku K
	int c; // numer zadania przeszkadzajac�go, interference job


	
	int carlier(Carlier &ob, int UB);
	int znajdz_a(int &a, int &b);
	int znajdz_b(int &b);
	int znajdz_c(int a, int b);
	

	
};

