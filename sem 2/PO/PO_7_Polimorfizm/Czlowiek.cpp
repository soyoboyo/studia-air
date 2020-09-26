#include "Czlowiek.h"

using namespace std;

void Czlowiek::przeslona() {
	cout << "x wilkolaka = " << Wilkolak::x 
		<< " x czlowieka = " << x << endl;
}

void Czlowiek::zwykla_funkcja() {
	cout << "Zwykla funkcja klasy Czlowiek.\n";
	cout << "x wilkolaka = " << Wilkolak::x << " x czlowieka = " << x << endl;
}

void Czlowiek::przedstaw_sie() {
	cout << "Jestem czlowiek. Mam na imie " << imie 
		<< ". Mam " << wiek << " lat.\n";
}

Czlowiek::Czlowiek(string name, int lata) : wiek(lata) {
	imie = name;
	cout << "Konstruktor klasy Czlowiek.\n";
}

Czlowiek::Czlowiek(): x(10) {
	cout << "Konstruktor klasy Czlowiek.\n";
}

Czlowiek::~Czlowiek() { cout << "Destruktor klasy Czlowiek.\n"; }
