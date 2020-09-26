#include "Wilk.h"

using namespace std;

void Wilk::zwykla_funkcja() {
	cout << "Zwykla funkcja klasy Wilk.\n";
}

void Wilk::przedstaw_sie() {
	cout << "Jestem wilk. Mowia na mnie " << imie 
		<< ". Mam futro koloru " << futro <<".\n";
}

Wilk::Wilk(string name, string kolor) : futro(kolor) {
	imie = name;
	cout << "Konstruktor klasy Wilk.\n";
}

Wilk::~Wilk() { cout << "Destruktor klasy Wilk.\n"; }
