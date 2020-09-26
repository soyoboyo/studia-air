#pragma once
#include "Schrage.h"

using namespace std;

class Carlier : public Schrage
{
public:
	Carlier();
	~Carlier();

	Zadanie PI_opt[2000];
	int U; // wartoœæ funkcji celu Cmax
	int UB; // górne oszacowanie, upper bound
	int LB; // dolne oszacowanie, lower bound

	int a; // numer pierwszego zadania w bloku K
	int b; // numer ostatniego zadania w bloku K
	int c; // numer zadania przeszkadzajacêgo, interference job

	int r_plim; // nowe r dla zadania c
	int p_plim; // suma p KROK 5
	int q_plim; // nowe q dla zadania c

	int r_mem; // zapamiêtane r zadania c
	int q_mem; // zapamiêtane q zadania c
	int nr_mem; // zapamiêtany numer zadania c
	
	int carlier(Carlier &ob);
	int znajdz_a();
	int znajdz_b();
	int znajdz_c();
	

	
};

