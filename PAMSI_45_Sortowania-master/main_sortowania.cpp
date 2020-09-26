#pragma once
#include "funkcje.h"
#include "generator.h"
#include <Windows.h>
#include <fstream>

using namespace std;
//extern const int ilosc_tab = 100;
//extern const int rozmiar = 50000;
LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();


/*
na 3:
b¹belkowe, wstawianie, kopcowanie, scalanie
na 4: 
kopcowanie, scalanie, Shella, quicksort
na 5:
scalanie, quicksort, introspektywne

*/

void funkcja(int x, int y, int **tab) // rozmiar tablicy, ilosc tablic, nazwa macierzy
{
	int i = 0, j = 0;
	for (j = 0; j < y; j++)
	{
		for (i = 0; i < x; i++)
			tab[j][i] = i;
	}
}

void wyswietl(int x, int y, int **tab) // rozmiar tablicy, ilosc tablic, nazwa macierzy
{
	int i = 0, j = 0;
	for (j = 0; j < y; j++)
	{
		for (i = 0; i < x; i++)
			cout << tab[j][i] << " ";
		cout << endl;
	}

}


/*
pseudokod
+ stworz tablice 2D
1 rozmiar to ilosc tablic = 100, 2 rozmiar to rozmiar tablic
generuj kazdy wiersz po kolei

sortuj kazdy wiersz po kolei

*/

int **tablica_tablic = new int*[100];



int main() {

	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	__int64 freq; double tm; double czas_calkowity = 0;
	ofstream plik;

	int i = 0, a = 0, b = 0; // zmienne iteracyjne
	char op; // r albo m, rosn¹co/malej¹co
	const int ilosc_tab = 100; // 100 tablic
	const int pro[8] = { 0 , 250, 500, 750, 950, 990, 997, 1000 }; // procent posortowania
	const int rozmiar[5] = { 10000, 50000, 100000, 500000, 1000000 };; // iloœæ elementów w tablicy
	float proc;
	int j = 0;
	

	plik.open("wyniki_sortowania.txt", std::ofstream::out | std::ofstream::trunc);
	plik.close();
	plik.open("pure_data_for_excel.txt", std::ofstream::out | std::ofstream::trunc);
	plik.close();

	int **tablica_tablic;
	
	for (b = 0; b < 5; b++) { // dla ka¿dego rozmiaru

		tablica_tablic = new int*[100];
		
		for (i = 0; i < ilosc_tab; i++) 
			tablica_tablic[i] = new int[rozmiar[b]];
		
		for (a = 0; a < 8; a++) { // dla ka¿dego procentu posortowania

			if (a < 7) op = 'r';
			else op = 'm';


			generator(rozmiar[b], ilosc_tab, pro[a], tablica_tablic, op);
			// wyswietl(rozmiar[b], ilosc_tab, tablica_tablic);

			QueryPerformanceFrequency((LARGE_INTEGER *)&freq);




			performanceCountStart = startTimer(); // start timera
			/***************sortowanie*********************/


			// bombelkowe(rozmiar[b], ilosc_tab, tablica_tablic);
			 wstawianie(rozmiar[b], ilosc_tab, tablica_tablic); 
			// kopcowanie(tablica_tablic, rozmiar[b], ilosc_tab);
			// Shell_sort(tablica_tablic, ilosc_tab, rozmiar[b]);

			//for (j = 0; j <  ilosc_tab; j++) { // tablica 1 ... 100
			
				//quicksort(rozmiar[b], ilosc_tab, tablica_tablic, 0, rozmiar[b] - 1, j); // 1386 s
				//scalanie(tablica_tablic, rozmiar[b], ilosc_tab, j, 0, rozmiar[b] - 1);
			//	}
				
				

				//  wyswietl(rozmiar[b], ilosc_tab, tablica_tablic);
				/****************************************************/
				performanceCountEnd = endTimer(); // stop timera

				
			
			tm = (double)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq;
			cout << "Czas sortowania: " << tm << " s" << endl;
			cout << "Czas sredni dla 1 tablicy: " << tm / 100 << " s" << endl << endl;
			proc = (float)pro[a] / 10;
			czas_calkowity += tm;
			
			plik.open("wyniki_sortowania.txt", std::ios::app);
			if (plik.good() == true)
			{
				plik << "Rozmiar tablic: " << rozmiar[b] << ", procent posortowania: " << proc << "%." << endl;
				plik << "Czas sortowania: " << tm << " s" << endl;
				plik << "Czas sredni dla 1 tablicy: " << tm / 100 << " s" << endl << endl;
				plik.close();
			}
			plik.open("pure_data_for_excel.txt", std::ios::app);
			if (plik.good() == true)
			{
				plik << tm << " ";
				plik.close();
			}
			
		} // procenty

		plik.open("pure_data_for_excel.txt", std::ios::app);
		if (plik.good() == true) {
			plik << endl; // oddzielenie nowym wierszem
			plik.close(); 
		}

		for (i = 0; i < ilosc_tab; i++)
		{
			//cout << i << " ";
		//	delete[] tablica_tablic[i];
		}
		
	} // rozmiar
	


	delete[] tablica_tablic;

	plik.open("wyniki_sortowania.txt", std::ios::app);
	if (plik.good() == true) {
		plik << "\nSuma czasow sortowania: " << czas_calkowity << endl; // oddzielenie nowym wierszem
		plik.close();
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

