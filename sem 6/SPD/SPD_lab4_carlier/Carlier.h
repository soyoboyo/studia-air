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


	
	int carlier(Carlier &ob, int UB);
	int znajdz_a(int &a, int &b);
	int znajdz_b(int &b);
	int znajdz_c(int a, int b);
	

	
};

