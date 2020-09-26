#pragma once

#include "Zadanie.h"

using namespace std;

int t = 1; // chwila czasu = t
int liczba_zadan = 0; // liczba zadan
int Cmax = 0; // czas dostarczenia

Zadanie tab[2000]; // do wczytania z pliku

Zadanie teraz;// zadanie obecnie ykonywane
Zadanie e; // nowe zadanie swie¿o dodawane


bool wczytajPlik(string);
void sortuj();
void wyswietl();
int znajdz_max(int, int);

priority_queue<Zadanie, vector<Zadanie>, argMIN> NIEDostepne; // kolejka zadan jeszcze nie gotowych do realizacji
priority_queue<Zadanie, vector<Zadanie>, argMAX> Dostepne; // kolejka zadan gotowych do realizacji


void schrage() {
	int n = liczba_zadan; // liczba zadan
	teraz.p = 0; teraz.q = 0;
	int i = 0; // zmienna iteracyjna
	t = tab[1].r; // skok od razu do czasu rozpoczenia 1 zadania

	// dopoki chocia¿ 1 kolejka ma chociaz 1 element
	while (!(empty(Dostepne)) || !(empty(NIEDostepne)))
	{
		// dopoki sa jakies niedostepne zadania
		// i któreœ z nich jest gotowe do realizacji
		while (!(empty(NIEDostepne)) && (NIEDostepne.top().r <= t))
		{
			e = NIEDostepne.top(); // element o najmniejszym r
			Dostepne.push(e); // staje sie dostêpny
			NIEDostepne.pop(); // usuwanie z kolejki niedostêpnych zadanie ktore wlasnie zaczelo sie wykonywaæ

			if (e.q > teraz.q) // je¿eli ogon nowego zadania jest wiêkszy ni¿ obecnie wtkonywanego
			{
				teraz.p = t - e.r; // odejmujemy od p tyle ile zostalo zrobione
				t = e.r; // nowy czas mowie ile MA BYæ wykonywane nowe zadanie
				if (teraz.p > 0) // jezeli jeszcze robione
				{
					Dostepne.push(teraz); // dodaj do kolejki
				}
			}
		}
		if (empty(Dostepne)) // je¿eli ¿adne zadanie nie jest obecnie wykonywane
		{
			t = NIEDostepne.top().r; // przeskocz do pocz¹tku kolejnego zadania
		}
		else // je¿eli coœ jest wykonywane to:
		{
			e = Dostepne.top(); // zadanie obecnie wykonywane
			Dostepne.pop(); // usun z kolejki po zakonczeniu zadania
			teraz = e;
			t = t + e.p; // przejdz do chwili zakonczenia zadania
			Cmax = znajdz_max(Cmax, t + e.q); // sprawdŸ co wiêksze
		}
	} // while empty(dost) || empty(niedost)
} // schrage

int main() {

	if (!wczytajPlik("schrage_6.txt"))
		std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;

	sortuj(); // sortuj wzgledem r rosn¹co i wrzuc do kolejki NIEDostepne
	cout << "Posortowane wzgledem r: " << endl;
	wyswietl();

	schrage(); // wiadomo
	cout << "Po algorytmie Schrage: " << endl;
	cout << "Cmax: " << Cmax << endl;

	/*
	1 32
	2 641
	3 1257
	4 1386
	5 3472
	6 3617
	7 6885
	8 6904
	9 72852
	*/

	return 0;
}

bool wczytajPlik(string nazwaPliku) // funkcja wczytujca dane z plik do tablicy
{
	int i = 0; // zmienna iteracyjna

	ifstream plik; // obiekt typu ifstream
	plik.open(nazwaPliku.c_str());
	if (!plik.good()) // jezeli nie ma pliku o podanej nazwie
		return false;

	plik >> liczba_zadan;
	cout << "Liczba zadan: " << liczba_zadan << endl;
	cout << "Przed posortowaniem: " << endl;
	
	for (i = 0; i < liczba_zadan; i++)
	{
		plik >> tab[i].r >> tab[i].p >> tab[i].q; // wczytywanie wierszy
		tab[i].nr = i + 1;
		cout << tab[i];
	}

	return true;
}

void sortuj() { // funckja sortujca
	int n = liczba_zadan;
	int i = 0;
	Zadanie tmp;

	while (n > 0) {
		for (i = 0; i < n; i++) {
			if (tab[i-1].r > tab[i].r) {
				tmp = tab[i-1];
				tab[i-1] = tab[i];
				tab[i] = tmp;
			}
		}
		n--;

	}
	n = liczba_zadan;
	for (i = 0; i < n; i++) {
		NIEDostepne.push(tab[i]);
	}
}

void wyswietl() {
	for (int i = 0; i < liczba_zadan; i++)
		cout << tab[i];
	//cout << "Nr zad: " << tab[i].nr_zad << "|| " << tab[i].r << " " << tab[i].p << " " << tab[i].q << endl;
}

int znajdz_max(int a, int b) // funkcja znajdujaca max z 2 liczb
{
	return (a > b) ? a : b;
}
