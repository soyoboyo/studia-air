#pragma once
#include "Pojazd.h"

using namespace std;

class Samochod_ciezarowy : public Pojazd
{
public:
	Samochod_ciezarowy();
	Samochod_ciezarowy(int kola, int pasazerowie, string nazwa, int ladunek, string rejestracja, string firma);
	~Samochod_ciezarowy();
	void przedstaw_sie();
private:
	int ladownosc;
	std::string nr_rejestracyjny;
	const string marka;
};

