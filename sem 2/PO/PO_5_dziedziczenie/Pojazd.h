#pragma once
#include <iostream>
#include <string>
 
using namespace std;

class Pojazd
{
public:
	Pojazd(); // konstruktor BEZparametryczny
	Pojazd(int kola, int pasazerowie, std::string nazwa_obiektu); // konstruktor parametryczny
	~Pojazd(); // destruktor
	int getKola(); // getter
	int getMiejsca(); // getter
	std::string getModel(); // getter
	void przedstaw_Pojazd();
	int liczba_kol;

protected: 
	string model;

private:
	int liczba_miejsc;
	
};

