#pragma once
#include "Zadanie.h"


using namespace std;

int znajdz_max(int, int);
int znajdz_min(int, int);

class Schrage
{
public:
	
	

	Zadanie PI[2000]; // permutacja PI
	
	int Cmax; // wartoœæ funkcji celu Cmax
	int Cmax_bez;
	int Cmax_z;
	int t; // chwila czasowa t
	Zadanie e;
	Zadanie teraz;

	bool wczytajPlik(string);
	void sortuj();

	priority_queue<Zadanie, vector<Zadanie>, argMIN> NIEDostepne; // kolejka zadan jeszcze nie gotowych do realizacji
	priority_queue<Zadanie, vector<Zadanie>, argMAX> Dostepne; // kolejka zadan gotowych do realizacji
	
	friend bool operator<(const Zadanie& o1, const Zadanie& o2);
	struct argMAX; // priorytet wg najwiêkszego q
	struct argMIN; // priorytet wg najmniejszego r

	int schrage_bez();
	int schrage_z();

	Schrage();
	~Schrage();
};

