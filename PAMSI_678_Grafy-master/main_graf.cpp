#pragma once
#include "Lista.h"
#include "Macierz.h"
#include <queue>
#include <Windows.h>
#include <cstdlib>
#include "time.h"

using namespace std;

LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();


int Prim(Graf* G)
{
	int wynik = 0;
	int V = G->getV();
	int* jest_w_drzewie = new int[V];
	priority_queue<pair<int, int> > kolejka;
	pair<int, int> p = make_pair(0, 0);

	for (int i = 0; i < V; i++)
		jest_w_drzewie[i] = 0;

	jest_w_drzewie[0] = 1; //poczatek na V=0

	for (int i = 0; (p = G->sasiedzi(0, i)).first != -1; i++)
		kolejka.push(make_pair(-p.second, p.first));

	while (!kolejka.empty())
	{
		pair<int, int> najmniejsza = kolejka.top();
		kolejka.pop();

		if (jest_w_drzewie[najmniejsza.second] == 0)
		{
			wynik -= najmniejsza.first;
			for (int i = 0; (p = G->sasiedzi(najmniejsza.second, i)).first != -1; i++)
				kolejka.push(make_pair(-p.second, p.first));
			jest_w_drzewie[najmniejsza.second] = 1;
		}
	}

	delete[] jest_w_drzewie;

	return wynik;
}









int main()
{
	LARGE_INTEGER startLista, stopLista, startMacierz, stopMacierz;
	__int64 freq; double tmLista = 0, tmMacierz = 0; double czas_calkowity = 0;
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);


	ofstream plik;
	plik.open("wyniki_prim.txt", std::ofstream::out | std::ofstream::trunc);
	plik.close();
	plik.open("pure_data_for_excel.txt", std::ofstream::out | std::ofstream::trunc);
	plik.close();

	const int liczbaV[] = { 10, 50, 100, 500, 1000 }; // liczba wierzcho³ków
	const int gestosc[] = { 25, 50, 75, 100 }; // %%%% gêstoœci
	
	int i, j, k; // zmienne iteracyjne

	Lista* GL = new Lista();
	Macierz* GM = new Macierz();

	srand(time(0));
	for (j = 0; j < 5; j++) // iloœæ wierzcho³ków
	{ 
		for (i = 0; i < 4; i++) // gêstoœci
		{
			tmLista = 0;
			tmMacierz = 0;
			for (k = 0; k < 100; k++) // 100 razy
			{
				GL->generator(liczbaV[j], gestosc[i]);
				GM->generator(liczbaV[j], gestosc[i]);

				/***** POMIAR CZASU *****/
				startLista = startTimer();
				Prim(GL);
				stopLista = endTimer();

				startMacierz = startTimer();
				Prim(GM);
				stopMacierz = endTimer();
				/***** POMIAR CZASU *****/

				tmLista += (double)(stopLista.QuadPart - startLista.QuadPart) / freq;
				tmMacierz += (double)(stopMacierz.QuadPart - startMacierz.QuadPart) / freq;
				
			}
			if (liczbaV[j] == 10 && gestosc[i] == 50)
			{
				GL->zapisz("lista_struct.txt");
			}
			cout << "Graf " << liczbaV[j] << " wierzcholkow\t" << gestosc[i] << "% gestosci\n";
			cout << "Lista: " << tmLista << " s" << endl;
			cout << "Macierz: " << tmMacierz << " s" << endl;
			cout << endl;

			// zapis wyników do pliku
			plik.open("wyniki_prim.txt", std::ios::app);
			if (plik.good() == true)
			{
				plik << "Graf: " << liczbaV[j] << ", procent gestosci: " << gestosc[i] << "%." << endl;
				plik << "Lista: " << tmLista << " s" << endl;
				plik << "Macierz: " << tmMacierz << " s" << endl;
				plik.close();
			}
			plik.open("pure_data_for_excel.txt", std::ios::app);
			if (plik.good() == true)
			{
				plik << tmLista << " " << tmMacierz << " ";
				plik.close();
			}


			
		}
		plik.open("pure_data_for_excel.txt", std::ios::app);
		if (plik.good() == true) {
			plik << endl; // oddzielenie nowym wierszem
			plik.close();
		}
		cout << endl;
	}
	
	

	return 0;
}


LARGE_INTEGER startTimer()
{
	LARGE_INTEGER start;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return start;
}

LARGE_INTEGER endTimer()
{
	LARGE_INTEGER stop;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return stop;
}