#pragma once

#include "Zadanie.h"

using namespace std;

int t = 1; // chwila czasu = t
int liczba_zadan = 0; // liczba zadan
int Cmax = 0; // czas dostarczenia


Zadanie tab[200]; // do wczytania z pliku
Zadanie PI[200]; // permutacja PI po algorytmie schrage

bool wczytajPlik(string);
void sortuj();
void wyswietl();
int znajdz_max(int, int);

priority_queue<Zadanie, vector<Zadanie>, argMIN> NIEDostepne; // kolejka zadan jeszcze nie gotowych do realizacji
priority_queue<Zadanie, vector<Zadanie>, argMAX> Dostepne; // kolejka zadan gotowych do realizacji


void schrage() {
	int n = liczba_zadan; // liczba zadan
	Zadanie tmp; // obiekt pomocniczy, bardziej czytelny kod
	int i = 0; // zmienna iteracyjna
	t = tab[0].r; // skok od razu do czasu rozpoczenia 1 zadania

				  // dopoki chocia¿ 1 kolejka ma chociaz 1 element
	while (!(empty(Dostepne)) || !(empty(NIEDostepne)))
	{
		// dopoki sa jakies niedostepne zadania
		// i któreœ z nich jest gotowe do realizacji
		while (!(empty(NIEDostepne)) && (NIEDostepne.top().r <= t))
		{
			tmp = NIEDostepne.top(); // element o najmniejszym r
			Dostepne.push(tmp); // staje sie dostêpny
			NIEDostepne.pop(); // usuwanie z kolejki niedostêpnych zadanie ktore wlasnie zaczelo sie wykonywaæ
		}
		if (empty(Dostepne)) // je¿eli ¿adne zadanie nie jest obecnie wykonywane
		{
			t = NIEDostepne.top().r; // przeskocz do pocz¹tku kolejnego zadania
		}
		else {
			tmp = Dostepne.top(); // zadanie obecnie wykonywane
			PI[i] = tmp; // dodaj do permutacji
			Dostepne.pop(); // usun z kolejki po zakonczeniu zadania
			t += PI[i].p; // przeskocz do chwili w ktorym w/w zadanie sie zakonczylo

			Cmax = znajdz_max(Cmax, t + PI[i].q); // sprawdŸ czy obecne Cmax jest wiêksze ni¿ 
												  // aktualna chwila czasu, czyli moment w którym zakonczylo sie dane zadanie
												  // i do tego dodaæ ogon tego zadania


			i++; // nastepne miejsce w permutacji
		}

	} // while empty(dost) || empty(niedost)
} // schrage

int main() {

	if (!wczytajPlik("schrage_2.txt"))
		std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;

	sortuj(); // sortuj wzgledem r rosn¹co i wrzuc do kolejki NIEDostepne
	cout << "Posortowane wzgledem r: " << endl;
	wyswietl();

	schrage(); // wiadomo
	cout << "Po algorytmie Schrage: " << endl;
	for (int i = 0; i < liczba_zadan; i++)
		cout << PI[i]; // wyœwietl wszystkie elementy permutacji
	cout << "Cmax: " << Cmax << endl;
	/*
	Co powinno wyjœæ:
	1 32
	2 687
	3 1299
	4 1399
	5 3487
	6 3659
	7 6918
	8 6936
	9 72853
	*/

	return 0;
}

bool wczytajPlik(std::string nazwaPliku) // funkcja wczytujca dane z plik do tablicy
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
			if (tab[i - 1].r > tab[i].r) {
				tmp = tab[i - 1];
				tab[i - 1] = tab[i];
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
