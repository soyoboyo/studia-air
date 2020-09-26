#include "Graf.h"

using namespace std;

bool Graf::wczytaj(char* nazwa)
{
	int u, v, w;
	fstream plik_in(nazwa, ios::in);

	if (plik_in.good() == true)
	{
		dealokuj();
		plik_in >> V;
		plik_in >> E;
		realokuj();
		wyczysc();

		for (int i = 0; i < E; i++)
		{
			plik_in >> u;
			plik_in >> v;
			plik_in >> w;
			dodajKrawedz(u, v, w);
		}
		plik_in.close();
	}
	else
		return false;

	return true;
}

bool Graf::zapisz(char* nazwa)
{
	fstream plik_out(nazwa, ios::out);

	if (plik_out.good() == true)
	{
		plik_out << V << " " << E << endl;

		for (int i = 0; i < V; i++)
			for (int j = i + 1; j < V; j++)
			{
				int w = getKoszt(i, j);

				if (w != -1)
					plik_out << i << " " << j << " " << w << endl;
			}
		plik_out.close();
	}
	else
		return false;

	return true;
}

bool Graf::czy_spojny()
{
	int *odwiedzone = new int[V];
	int *stos = new int[V];
	int ostatni = 0;
	int przejscie = 0;

	for (int i = 0; i < V; i++)
		odwiedzone[i] = 0;

	stos[ostatni] = 0;
	ostatni++;
	odwiedzone[0] = 1;

	while (ostatni > 0)
	{
		int aktualny = stos[--ostatni];
		int nastepny;

		przejscie++;

		for (int i = 0; (nastepny = sasiedzi(aktualny, i).first) != -1; i++)
			if (odwiedzone[nastepny] == 0)
			{
				stos[ostatni] = nastepny;
				ostatni++;
				odwiedzone[nastepny] = 1;
			}
	}

	delete[] odwiedzone;
	delete[] stos;

	return (przejscie == V); //jesli odwiedzono wszystkie wierzcholki to spojny
}

void Graf::generator(int iloscV, int procenty)
{
	int u, v, r;
	dealokuj();
	V = iloscV;
	E = V*(V - 1) * procenty / 200;
	realokuj();

	do
	{
		wyczysc();
		for (int i = 0; i < E; i++)
		{
			u = rand() % V;
			v = rand() % V;
			r = rand() % 10 + 1; // Waga od 1 do 10
			if (u != v && getKoszt(u, v) == -1)
			{
				dodajKrawedz(u, v, r);
			}
			else
			{
				i--;
			}
		}
	} while (!czy_spojny());
}

int Graf::getV() { return this->V; }
int Graf::getE() { return this->E; }

Graf::Graf() {}
Graf::~Graf() {}
