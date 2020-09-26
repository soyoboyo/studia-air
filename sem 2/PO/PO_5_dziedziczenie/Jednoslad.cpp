#include "Jednoslad.h"

using namespace std;

Jednoslad::Jednoslad() 
	: kolor_siodelka("szary")
{
	std::cout << "Konstruktor BEZparametryczny klasy Jednoslad\n";
}
Jednoslad::Jednoslad(int kola, int pasazerowie, std::string nazwa, std::string kolor) 
	: Pojazd(2, 1, "rower miejski")
{
	
	kolor_siodelka = kolor;
	cout << "Konstruktor parametryczny klasy Jednoslad\n";
}

void Jednoslad::przedstaw_sie() 
{
	Pojazd::przedstaw_Pojazd();
	cout << "Kolor siodelka: " << kolor_siodelka << endl;

}

Jednoslad::~Jednoslad() {}//std::cout << "Destruktor klasy Jednoslad\n";}
