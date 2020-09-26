#include "Macierz.h"

using namespace std;


void Macierz::dodajKrawedz(int u, int v, int waga)
{
	M[u][v] = waga;
	M[v][u] = waga;
}

void Macierz::wyczysc()
{
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			M[i][j] = -1;
}

void Macierz::dealokuj()
{
	if (M != NULL)
	{
		for (int i = 0; i < V; i++)
			delete[] M[i];
		delete[] M;
	}
}

void Macierz::realokuj()
{
	M = new int*[V];
	for (int i = 0; i < V; i++)
		M[i] = new int[V];
}

void Macierz::wyswietl()
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}
}

int Macierz::getKoszt(int u, int v) { return this->M[u][v]; }

Macierz::Macierz() { M = NULL; }
Macierz::~Macierz() { dealokuj(); }

