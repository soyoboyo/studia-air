#pragma once
#include "Schrage.h"
#include "Carlier.h"

using namespace std;

int Schrage::schrage_bez() {
	
	Zadanie tmp; // obiekt pomocniczy, bardziej czytelny kod
	int i = 1; // zmienna iteracyjna
	t = PI[0].r; // skok od razu do czasu rozpoczenia 1 zadania
	Cmax = 0; // trzeba zerowaæ Cmax miedzy wywolaniami schrage z i bez, bo weŸmie wiêksz¹ wartoœæ z dwóch

	for (i = 0; i < n; i++) {
		NIEDostepne.push(PI[i]);
	}

	i = 0;
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
						  // sprawdŸ czy obecne Cmax jest wiêksze ni¿ 
						  // aktualna chwila czasu, czyli moment w którym zakonczylo sie dane zadanie
						  // i do tego dodaæ ogon tego zadania
			Cmax = znajdz_max(Cmax, t + PI[i].q);
			
			PI[i].C = t;
			PI[i].Cq = PI[i].C + PI[i].q;
			
			i++; // nastepne miejsce w permutacji
		}

	} // while empty(dost) || empty(niedost)
	Cmax_bez = Cmax;
	cout << "Po algorytmie Schrage bez podzialu: Cmax_bez " << Cmax_bez << endl;
	return Cmax;
} // schrage bez 


int Schrage::schrage_z() {
	
	teraz.p = 0; teraz.q = 0;
	int i = 0; // zmienna iteracyjna
	t = PI[0].r; // skok od razu do czasu rozpoczenia 1 zadania
	Cmax = 0; // trzeba zerowaæ Cmax miedzy wywolaniami schrage z i bez, bo weŸmie wiêksz¹ wartoœæ z dwóch
	for (i = 0; i < n; i++) {
		NIEDostepne.push(PI[i]);
	}
	i = 0;

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
	Cmax_z = Cmax;
	cout << "Po algorytmie Schrage z podzialem: Cmax_z = " << Cmax_z << endl;
	return Cmax;
} // schrage z 

bool Schrage::wczytajPlik(std::string nazwaPliku) // funkcja wczytujca dane z plik do tablicy
{
	int i = 0; // zmienna iteracyjna

	ifstream plik; // obiekt typu ifstream
	plik.open(nazwaPliku.c_str());
	if (!plik.good()) // jezeli nie ma pliku o podanej nazwie
		return false;
	plik >> n;
	cout << "Liczba zadan: " << n << endl;
	cout << "Przed posortowaniem: " << endl;

	for (i = 0; i < n; i++)
	{
		plik >> PI[i].r >> PI[i].p >> PI[i].q; // wczytywanie wierszy
		PI[i].nr = i + 1;
		cout << PI[i];
	}

	return true;
}

void Schrage::sortuj() { // funckja sortujca
	
	int i = 0;
	Zadanie tmp;
	int temp = n;
	while (n--) {
		for (i = 0; i < n; i++)
		{
			if (PI[i].r > PI[i + 1].r)
			{
				tmp = PI[i];
				PI[i] = PI[i + 1];
				PI[i + 1] = tmp;
			}
		}
	}
	n = temp;
	
}

// przeci¹zanie operatora niezbêdne aby kolejka obs³ugiwa³a obiekty typu Zadanie
bool operator<(const Zadanie& o1, const Zadanie& o2) {
	return o1.q > o2.q;
}

Schrage::Schrage() : Cmax(0), t(0), Cmax_bez(INT_MAX), Cmax_z(INT_MAX) {}
Schrage::~Schrage() {}
