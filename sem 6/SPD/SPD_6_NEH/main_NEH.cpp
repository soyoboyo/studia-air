#pragma once
#include "NEH.h"
#include <Windows.h>

using namespace std;

int n;
int m;

LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();

int main() {

	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	__int64 freq;
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

	/************************************************************/
	NEH obiekt;

	/*
	Wyniki
	nr	ma byæ	moje
	1	47		47
	2	637		626
	3	1163	1163
	4	1805	1805
	5	1137	1137
	6	1471	1471
	7	2397	2397
	8	5967	5959
	9	6369	6447

	*/

	if (!obiekt.wczytaj_plik("NEH_2.txt"))
		std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;
	obiekt.wyswietl(obiekt.wczytane); // wyœwietl wczytane zadania

	
	performanceCountStart = startTimer(); // start timera

	obiekt.algorytmNEH(); // sam algorytm
	
	performanceCountEnd = endTimer(); // stop timera

	cout << "Ostateczny Cmax = " << obiekt.getCmax() << endl; // ostateczny Cmax
	/************************************************************/

	double tm = (double)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq;
	cout << endl << "Czas wykonywania algorytmu: " << tm << " s" << endl << endl;



	return 0;
}




// pomiar czasu
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



