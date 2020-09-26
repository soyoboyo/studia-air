#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

extern int n; // ilo�� zada�
extern int ilosc_kombinacji; // ilo�� kombinacji 2^n

class Zadanie
{
public:

	int nr; // numer zadania
	int p; // czas wykonania zadania
	int w; // wsp�czynnik kary za jednostk� spo�nienia
	int d; // deadline, a raczej due date

	friend ostream& operator<<(ostream& stream, const Zadanie& o); // przeci��enie operatora wy�wietlania

	Zadanie();
	~Zadanie();
};

