#pragma once
#include "Pojazd.h"

class Jednoslad : protected Pojazd
{
public:
	Jednoslad();
	Jednoslad(int kola, int pasazerowie, std::string nazwa, std::string kolor);

	~Jednoslad();
	void przedstaw_sie();
private:
	std::string kolor_siodelka;
};

