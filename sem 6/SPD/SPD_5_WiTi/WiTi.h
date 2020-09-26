#pragma once
#include "Zadanie.h"
#include "Kombinacja.h"
#include <string>
#include <list>

using namespace std;

class WiTi
{
public:

	vector <Zadanie> zadania; // tablica wczytanych zada�
	int k1, k2; // k1 - kara za ostatnie zadanie, k2 - kara adresowanej kombinacji
	int adr; // adres permutacji

	void algorytm_WiTi(); // algorytm g��wny
	bool sprawdz_bit(int war, int poz); // sprawdza czy bit na danej pozycji jest ustawiony
	int reset(int war, int poz); // ustawia bit na danej pozycji na 0
	int policz_kare(int a, int b); // liczy kar� dla dalej kombinacji
	void znajdz_kolejnosc(); // znajduje i wyswietla podzbior zada�

	vector <Kombinacja> kombinacje; // wszystkie kombinacje
	list <int> podzbior; // lista podzbiori zada�

	bool wczytajPlik(string);
	void wyswietl_zad(Zadanie *, int);

	WiTi();
	~WiTi();
};

