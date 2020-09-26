#include "Samochod_ciezarowy.h"

using namespace std;



void Samochod_ciezarowy::przedstaw_sie() {
	Pojazd::przedstaw_Pojazd();
	cout << "Ladownosc: " << ladownosc << " kg" << endl
		 << "Nr rejestracyjny: " << nr_rejestracyjny << endl
		 << "Marka: " << marka << endl;
}



Samochod_ciezarowy::Samochod_ciezarowy() { std::cout << "Konstruktor BEZparametryczny klasy Samochod_ciezarowy\n"; } // konstruktor domyœlny
Samochod_ciezarowy::Samochod_ciezarowy(int kola, int pasazerowie, string nazwa, int ladunek, string rejestracja, string firma)
	: Pojazd(kola, pasazerowie, nazwa), nr_rejestracyjny(rejestracja), marka(firma), ladownosc(ladunek)
{
	cout << "Konstruktor parametryczny klasy Samochod_ciezarowy\n";
}
Samochod_ciezarowy::~Samochod_ciezarowy() {}// std::cout << "Destruktor klasy Samochod_ciezarowy\n"; } // destruktor