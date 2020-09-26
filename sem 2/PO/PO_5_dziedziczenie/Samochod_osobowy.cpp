#include "Samochod_osobowy.h"

using namespace std;

// gettery

bool Samochod_osobowy::getKlima()
{
	return klimatyzacja;
}

string Samochod_osobowy::getRejestracja()
{
	return nr_rejestracyjny;
}

std::string Samochod_osobowy::getMarka()
{
	return marka;
}



Samochod_osobowy::Samochod_osobowy() 
{
	klimatyzacja = true;
	std::cout << "Konstruktor BEZparametryczny klasy Samochod_osobowy\n";
}

Samochod_osobowy::Samochod_osobowy(int kola, int pasazerowie, std::string nazwa, bool klima, std::string tablica, std::string firma)
	: Pojazd(kola, pasazerowie, nazwa), klimatyzacja(klima), nr_rejestracyjny(tablica), marka(firma)
{
	std::cout << "Konstruktor parametryczny klasy Samochod_osobowy\n";
}



void Samochod_osobowy::przedstaw_sie() {
	Pojazd::przedstaw_Pojazd();

	std::cout << "Klimatyzacja: ";
	if (klimatyzacja)
		std::cout << "tak\n";
	else
		std::cout << "nie\n";
	std::cout << "Nr rejestracyjny: " << nr_rejestracyjny << std::endl
		<< "Marka: " << marka << std:: endl;
}

Samochod_osobowy::~Samochod_osobowy() {}// std::cout << "Destruktor klasy Samochod_osobowy\n"; }
