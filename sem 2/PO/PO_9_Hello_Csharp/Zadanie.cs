using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PO_9_Hello_Csharp
{
    class Zadanie
    {
        int nr; // numer zadania
        int r; // head (czas dostępności zadania)
        int p; // body (czas wykonania zadani)
        int q; // tail (czas dostarczenia zadania)


    }
}
#pragma once
#include "Zadanie.h"

using namespace std;

Zadanie::Zadanie() {} // konstruktor domyślny
Zadanie::~Zadanie() { } // destruktor

// przeciązanie operatora niezbędne aby koeljka obsługiwała obiekty typu Zadanie
bool operator <(const Zadanie& o1, const Zadanie& o2)
{
    return o1.q > o2.q;
}
// przeciążenie operatora potrzebne do łatwego wyświetlania zadań
ostream& operator <<(ostream& stream, const Zadanie& o)
{
    stream << o.nr << " || " << o.r << " " << o.p << " " << o.q << endl;
    return stream;
}





#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <math.h>
#include <queue>

using namespace std;

extern int liczba_zadan; // zmienna dostępna we wszystkich plikach

class Zadanie
{
    public:
	Zadanie();
    ~Zadanie();

    friend void wyswietl();
    friend bool wczytajPlik(string);
    friend void sortuj();
    friend int znajdz_max(int, int);
    friend int main();
    friend void schrage();

    friend ostream& operator<<(ostream& stream, const Zadanie& o); // wyświetlanie obiektów klasy Zadanie
	friend bool operator <(const Zadanie& o1, const Zadanie& o2);
	friend struct argMAX; // priorytet wg największego q
    friend struct argMIN; // priorytet wg najmniejszego r

    private:
	int nr, r, p, q; // nr zadania, head, body i tail
};


// wyswietlanie kolejki
template<typename T> void wyswietl_kolejke(T& o)
{
    while (!o.empty())
    {
        cout << o.top(); // << " ";
        o.pop();
    }
    cout << '\n';
}
// priorytet wg. wartosci NAJWIĘKSZEGO q
struct argMAX
{
    bool operator()(const Zadanie& o1, const Zadanie& o2) {
		return o1.q<o2.q;
	}
};
// priorytet wg. wartości NAJMNIEJSZEGO r
struct argMIN
{
    bool operator()(const Zadanie& o1, const Zadanie& o2) {
		return o1.r > o2.r;
	}
};