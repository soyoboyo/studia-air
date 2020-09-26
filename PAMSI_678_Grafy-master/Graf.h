#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Graf
{
protected:
	int V; // iloœæ wierzcho³ków
	int E; // iloœæ krawêdzi
	virtual void dodajKrawedz(int u, int v, int w) = 0;
	virtual void wyczysc() = 0;
	virtual void dealokuj() = 0;
	virtual void realokuj() = 0;
	bool czy_spojny(); // sprawdz spojnosc grafu

public:
	int getV(); // getter
	int getE(); // getter
	virtual int getKoszt(int u, int v) = 0;
	virtual pair<int, int> sasiedzi(int u, int i) = 0;
	bool wczytaj(char* nazwa); // wczytywanie z pliku
	bool zapisz(char* nazwa);  // zapis do pliku
	void generator(int iloscV, int procent);
	Graf();
	virtual ~Graf();
};

