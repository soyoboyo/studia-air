#pragma once
#include "Zadanie.h"
#include <string>
#include <fstream>
#include <algorithm>


using namespace std;

class NEH
{
public:

	vector<Zadanie> wczytane; // wczytane, modyfikowana tylko 1 raz
	vector<Zadanie> zad; // tablica na któej dzia³¹ algorytm

	bool wczytaj_plik(string nazwaPliku); // wczytaj plik
	void algorytmNEH(); // sam algorytm
	void dwaPierwsze(); // znajdŸ kolejnoœæ dwóch piwerszych zadañ
	void znajdzCmax(); // znajdŸ kolejnoœæ reszty zadañ

	void wyswietl(vector<Zadanie> &tab); // wyœwietl wybran¹ tablicê
	int getCmax() {return Cmax;}; // getter
	NEH();
	~NEH();

private:
	int lZad;
	int lMasz;
	int Cmax;
	
	
};



