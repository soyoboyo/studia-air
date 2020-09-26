#include "Pojazd.h"


// gettery
int Pojazd::getKola() 
{
	return liczba_kol;
}
int Pojazd::getMiejsca() 
{
	return liczba_miejsc;
}
std::string Pojazd::getModel() 
{
	return model;
}

void Pojazd::przedstaw_Pojazd() 
{
	std::cout << "Model: " << model << std::endl
		<< "Liczba miejsc: " << liczba_miejsc << std::endl
		<< "Liczba kol: " << liczba_kol << std::endl;
}

// konstruktor parametryczny
Pojazd::Pojazd(int kola, int pasazerowie, std::string nazwa) 
	: liczba_kol(kola), liczba_miejsc(pasazerowie), model(nazwa)
{
	std::cout << "Konstruktor parametryczny klasy Pojazd\n";
}

// konstruktor BEZparametryczny 
Pojazd::Pojazd() 
	: liczba_kol(1), liczba_miejsc(1), model("ASD") // lista inicjalizacyjna
{
	std::cout << "Konstruktor BEZparametryczny klasy Pojazd\n";
} 

// destruktor
Pojazd::~Pojazd() {}//std::cout << "Destruktor klasy Pojazd\n";} 
