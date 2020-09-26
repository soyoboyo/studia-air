#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <math.h>
#include <queue>

using namespace std;

extern int liczba_zadan; // zmienna dost�pna we wszystkich plikach

class Zadanie {
public:
	Zadanie();
	~Zadanie();

	friend void wyswietl();
	friend bool wczytajPlik(string);
	friend void sortuj();
	friend int znajdz_max(int, int);
	friend int main();
	friend void schrage();

	friend ostream& operator<<(ostream& stream, const Zadanie& o); // wy�wietlanie obiekt�w klasy Zadanie
	friend bool operator<(const Zadanie& o1, const Zadanie& o2);
	friend struct argMAX; // priorytet wg najwi�kszego q
	friend struct argMIN; // priorytet wg najmniejszego r

private:
	int nr, r, p, q; // nr zadania, head, body i tail
};


// wyswietlanie kolejki
template<typename T> void wyswietl_kolejke(T& o) {
	while (!o.empty()) {
		cout << o.top(); // << " ";
		o.pop();
	}
	cout << '\n';
}
// priorytet wg. wartosci NAJWI�KSZEGO q
struct argMAX {
	bool operator()(const Zadanie& o1, const Zadanie& o2) {
		return o1.q < o2.q;
	}
};
// priorytet wg. warto�ci NAJMNIEJSZEGO r
struct argMIN {
	bool operator()(const Zadanie& o1, const Zadanie& o2) {
		return o1.r > o2.r;
	}
};