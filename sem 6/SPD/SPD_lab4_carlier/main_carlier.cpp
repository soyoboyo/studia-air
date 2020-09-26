#pragma once
#include "Carlier.h"
#include <Windows.h>

using namespace std;

int n = 0; // liczba zadan


int znajdz_max(int, int);
int znajdz_min(int, int);
void wyswietl_zad(Zadanie *, int);

LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();

Carlier obiekt;

/*
Co powinno wyjœæ:
plik	bez		z		carlier		roznica		czy dziala?
1		32		32		| 32 |		0			tak
2		687		641		| 641 |		46			tak
3		1299	1257	| 1267 |	32			tak
4		1399	1386	| 1386 |	13			tak
5		3487	3472	| 3472 |	15			tak
6		3659	3617	| 3617 |	42			tak
7		6918	6885	| 6885 |	67			tak
8		6936	6904	| 6904 |	32			tak
9		72853	72852	| 72852 |	1			tak

makuch		dziala?		kolejnoœæ
1 228		NIEEEEE			0 2 1 3
2 3026		tak			0 44 29 27 17 24 9 20 5 47 4 12 30 6 1 3 36 48 10 32 45 31 49 41 34 22 33 46 18 21 28 13 8 35 42 16 37 19 15 23 7 38 39 2 11 40 26 43 14 25
3 3665		NIEEEEE			37 0 27 5 21 9 19 34 36 10 20 48 2 28 45 16 42 17 18 12 24 4 46 26 6 31 33 13 25 15 39 43 40 32 7 49 44 8 23 38 1 41 30 11 29 22 47 3 14 35
4 3309		NIEEEEE			3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 25 26 27 28 36 44 0 1 38 45 46 47 48 49 2 24 29 30 31 32 33 34 35 37 39 40 41 42 43
5 3191		NIEEEEE			0 33 38 14 31 44 40 11 25 4 45 36 26 20 19 41 48 47 42 12 28 35 3 15 49 9 17 32 24 1 6 27 16 34 21 18 39 8 43 5 37 10 2 29 7 46 30 23 22 13
6 3618		tak			0 43 24 34 27 3 29 44 42 45 9 8 1 39 15 16 2 19 7 26 37 13 5 35 6 20 47 4 36 23 25 33 49 40 38 22 11 21 12 46 17 10 48 14 18 41 31 32 30 28
7 3446		NIEEEEE			18 35 45 3 37 38 4 5 25 2 28 7 39 14 10 8 11 12 48 1 43 27 41 46 9 29 49 22 42 26 34 16 13 36 17 15 44 40 30 31 20 6 23 32 21 24 19 0 33 47
8 3821		NIEEEEE			47 0 40 39 27 45 43 22 33 28 9 37 48 35 14 49 15 20 1 18 34 8 7 41 24 36 6 44 11 19 17 31 25 42 12 5 4 3 30 21 23 16 13 26 38 29 46 2 32 10
9 3634		NIEEEEE			29 48 4 28 36 13 21 7 15 3 10 24 14 18 22 17 34 38 1 27 2 25 46 26 23 41 19 11 9 40 44 33 0 35 32 49 45 42 8 31 43 12 47 6 37 5 20 39 16 30


UWAGI DO MAKUCHOWYCH:
1 kolejnoœæ dobra, ale U = 283, i schrage_bez tez gdzieœ tam generuje optymalne ale jakby je pomija
2 ------------------------- dzia³a, nie wnikam czemu
3 U = UB = LB = 3643
4 U = 3336, UB = 3336, LB = 3417
5 U = UB = LB = 3206
6 ------------------------- dziala, nie wnikam czemu
7 U = UB = 3457, LB = 3647, ale schrage_bez od razu generuje optymalne BEZ SENSU
8 U = UB = LB = 3793, jest mniej ni¿ optymalne
9 U = UB = 3650, LB = 3764



*/

int main() {

	
	if (!obiekt.wczytajPlik("schrage_3.txt"))
		std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;
	/*
	Co powinno wyjœæ:
	plik	bez		z		carlier		roznica		czy dziala?
	1		32		32		| 32 |		0			tak
	2		687		641		| 641 |		46			tak
	3		1299	1257	| 1267 |	32			tak
	4		1399	1386	| 1386 |	13			tak
	5		3487	3472	| 3472 |	15			tak
	6		3659	3617	| 3617 |	42			tak
	7		6918	6885	| 6885 |	67			tak
	8		6936	6904	| 6904 |	32			tak
	9		72853	72852	| 72852 |	1			tak
	*/
	 

	//obiekt.sortuj(); // sortuj wzgledem r rosn¹co i wrzuc do kolejki NIEDostepne
	//cout << "Posortowane wzgledem r: " << endl;
	//wyswietl_zad(obiekt.PI, n);
	obiekt.sortuj(); // sortuj wzgledem r rosn¹co i wrzuc do kolejki NIEDostepne
	obiekt.schrage_bez();
	wyswietl_zad(obiekt.PI, n);
	
	
	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	__int64 freq;
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
	performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy


	obiekt.carlier(obiekt, INT_MAX);


	performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
	double tm = (double)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq;
	

	cout << "\n\nKolejnosc zadan po algorytmie Carliera:\n";
	wyswietl_zad(obiekt.PI_opt, n);
	cout << "\nU = " << obiekt.U << ", UB = " << obiekt.Cmax_bez << ", LB = " << obiekt.Cmax_z << endl;
	cout << endl << "Czas wykonywania algorytmu: " << tm << " s" << endl << endl;

	return 0;
}





void wyswietl_zad(Zadanie* tablica, int rozmiar) {
	for (int i = 0; i < rozmiar; i++)
		cout << tablica[i];
	//cout << "Nr zad: " << tab[i].nr_zad << "|| " << tab[i].r << " " << tab[i].p << " " << tab[i].q << endl;
}

int znajdz_max(int a, int b) // funkcja znajdujaca max z 2 liczb
{
	return (a > b) ? a : b;
}

int znajdz_min(int a, int b) // funkcja znajdujaca min z 2 liczb
{
	return (a < b) ? a : b;
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
