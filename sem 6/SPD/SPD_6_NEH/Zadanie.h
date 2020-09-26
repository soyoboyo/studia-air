#pragma once
#include <iostream>
#include <vector>

using namespace std;

// po chuj robi� gettery skoro mo�na mie� t� sam� zmienn� dla wszystkich plik�w
extern int n; // liczba zada�
extern int m; // liczba maszyn

class Zadanie
{
public:

	int suma; // suma wszytkich czas�
	int nr; // numer zadania
	vector<int> czasy; // czasy na poszczeg�lnych maszynach
	vector<int> pocz; // pocz�tek zadania na poszczeg�lnych maszynach
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


