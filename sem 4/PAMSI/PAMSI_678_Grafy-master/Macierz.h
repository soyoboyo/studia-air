#pragma once
#include "Graf.h"

using namespace std;

class Macierz : public Graf
{
private:
	int **M;
	void dodajKrawedz(int u, int v, int waga);
	void wyczysc();
	void dealokuj();
	void realokuj();
	
	
public:
	Macierz();
	~Macierz();
	int getKoszt(int u, int v);
	void wyswietl();
	pair<int, int> sasiedzi(int u, int i)
	{
		for (int v = 0; v < V; v++)
			if (M[u][v] != -1)
			{
				if (i == 0)
					return make_pair(v, M[u][v]);
				i--;
			}

		return make_pair(-1, -1);
	}
};