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

	int r_plim; // nowe r dla zadania c
	int p_plim; // suma p KROK 5
	int q_plim; // nowe q dla zadania c

	int r_mem; // zapami�tane r zadania c
	int q_mem; // zapami�tane q zadania c
	int nr_mem; // zapami�tany numer zadania c
	
	int carlier(Carlier &ob);
	int znajdz_a();
	int znajdz_b();
	int znajdz_c();
	

	
};

