#pragma once
#include "WiTi.h"
#include <Windows.h>
#include <bitset>

using namespace std;

int n = 0;
int ilosc_kombinacji = 0;

LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();

WiTi obiekt;


int main() {

	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	__int64 freq;
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);


	/*
	Wyniki:
	0	1	2	3	4	5	6	7	 8	 9
	10	131	502	279	66	267	57	1191 435 723	
	*/
	
	

	if (!obiekt.wczytajPlik("witi_1.txt"))
		std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;

	performanceCountStart = startTimer(); // start timera


	obiekt.algorytm_WiTi();


	performanceCountEnd = endTimer(); // stop timera
	double tm = (double)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq;

	cout << endl << "Czas wykonywania algorytmu: " << tm << " s" << endl << endl;
	

	/*

	NOTATKI I UWAGI

	cout << obiekt.reset(15, 0) << endl;
	cout << obiekt.reset(15, 1) << endl;
	cout << obiekt.reset(15, 2) << endl;
	cout << obiekt.reset(15, 3) << endl;
	//cout << obiekt.sprawdz_bit(4, 3) << endl;
	//cout << ((1) & 1 << (0)) << endl;
	/* 
	Ci - czas zakoñczenia zadania;
	Ti = spóŸnienie czyli max(O, Ci, d);
	
	Wi to kara za jednostkê spóŸnienia
	Wi*Ti trzbea znalexæ min

	zestaw zadañ
	nr 1 2 3 4
	pi 1 3 2 2
	wi 1 1 4 2
	di 6 4 3 1
	
	
	dla permutacji 1 2 i 3 bedzie 6 mo¿liwoœci
	dlatego trzeba rozbiæ to na 3 zbiory
	kazdy zakoñczony odpowiednio 1, 2 i 3
	podzbiór 1: ({1,2} 3)
	podzbiór 2:	({1,3} 2)
	podzbiór 3: ({2,3} 1)
	
	sprawdzic ile wynosi kara za zadanie 1 2 i 3
	a potem sprawdziæ karê za mniejsze permutacje
	
	ogólnie trzeba znaæ wartoœæ optymaln¹ od koñca permutacji
	liczby koduj¹ bity w systemie binarnymfunkcja na podstawie liczby ca³kowitej dekoduje elementy zbioru
	trzeba skasowaæ jeden z bitów i odliczyæ karê dla elementu dla którego skasowaliœmy bit
	
	pseudokod:
	for(it = 1; it <= 2^n - 1; it++)
	{	
		OP[it] = INT_MAX;
	
		for(b = 0;b <= n;b++)
		{
			if(bit(b,it)) bit zwraca prawde jezeli bit w zmiennej it jest ustawiony a reset b-ty 
			{	ki = kara(b)
			adr = reset(b,it)
				k2 = opt[adr]	
				if(k1 + k2 < OPT[it]) jezeli kara za element 
			OPT[it] = k1 + k2
			}
		}
	}
	*/

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




/*

makuchy
wynik	czy dzia³a?		poprawna kolejnoœæ?
1	766		tak					nie				6 9 2 5 1 3 4 7 8 10
2	799		tak					nie				6 9 2 11 5 1 3 7 4 8 10
3	742		tak					nie				6 9 2 11 5 1 3 12 7 4 8 10
4	688											6 9 5 2 11 1 3 7 12 4 8 10 13
5	497											6 9 5 1 2 3 11 7 12 4 8 10 13 14
6	440											6 9 5 1 2 3 11 4 12 7 8 10 13 14 15
7	423											6 9 5 1 2 3 7 11 4 12 8 10 13 14 15 16
8	417											6 9 5 1 2 3 7 11 4 12 8 10 13 14 15 16 17
9	405											6 9 5 1 2 3 7 11 12 16 17 18 4 8 10 13 14 15
10	393											6 9 5 1 2 3 4 11 12 16 18 7 8 10 13 14 15 19 17
11	897											6 20 9 5 1 2 3 7 11 12 18 4 8 10 13 14 16 17 19 15

*/