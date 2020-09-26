#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

extern int n; // iloœæ zadañ
extern int ilosc_kombinacji; // iloœæ kombinacji 2^n

class Zadanie
{
public:

	int nr; // numer zadania
	int p; // czas wykonania zadania
	int w; // wspó³czynnik kary za jednostkê spoŸnienia
	int d; // deadline, a raczej due date

	friend ostream& operator<<(ostream& stream, const Zadanie& o); // przeci¹¿enie operatora wyœwietlania

	Zadanie();
	~Zadanie();
};

