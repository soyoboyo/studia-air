#pragma once
#include "Pojazd.h"

using namespace std;

class Samochod_osobowy : private Pojazd 
{
public:
	Samochod_osobowy();
	Samochod_osobowy(int kola, int pasazerowie, std::string nazwa, bool klima, std::string tablica, std::string firma);
	~Samochod_osobowy();

	bool getKlima();
	std::string getRejestracja();
	std::string getMarka();

	void przedstaw_sie();
private:
	bool klimatyzacja;
	std::string nr_rejestracyjny;
	const string marka;
};

