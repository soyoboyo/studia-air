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
	vector<Zadanie> zad; // tablica na kt�ej dzia�� algorytm

	bool wczytaj_plik(string nazwaPliku); // wczytaj plik
	void algorytmNEH(); // sam algorytm
	void dwaPierwsze(); // znajd� kolejno�� dw�ch piwerszych zada�
	void znajdzCmax(); // znajd� kolejno�� reszty zada�

	void wyswietl(vector<Zadanie> &tab); // wy�wietl wybran� tablic�
	int getCmax() {return Cmax;}; // getter
	NEH();
	~NEH();

private:
	int lZad;
	int lMasz;
	int Cmax;
	
	
};



