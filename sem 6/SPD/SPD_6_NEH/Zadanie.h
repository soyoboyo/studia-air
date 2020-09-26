#pragma once
#include <iostream>
#include <vector>

using namespace std;

// po chuj robiæ gettery skoro mo¿na mieæ tê sam¹ zmienn¹ dla wszystkich plików
extern int n; // liczba zadañ
extern int m; // liczba maszyn

class Zadanie
{
public:

	int suma; // suma wszytkich czasó
	int nr; // numer zadania
	vector<int> czasy; // czasy na poszczególnych maszynach
	vector<int> pocz; // pocz¹tek zadania na poszczególnych maszynach
	void policzSume(); // dodaj wszystkie czasy

	// sortowanie wg sumy
	bool operator<(const Zadanie& s) const {return (suma > s.suma);}
	// kopia zadania
	Zadanie operator=(const Zadanie &z)
	{
		int i;

		if (&z != this)
		{
			this->nr = z.nr;
			this->suma = z.suma;
			for (i = 0; i < pocz.size(); i++) {
				this->pocz[i] = z.pocz[i];
			}
			for( i = 0; i < czasy.size(); i++) {
				this->czasy[i] = z.czasy[i];
			}
		}
		return *this;
	}

	Zadanie();
	~Zadanie();
};


