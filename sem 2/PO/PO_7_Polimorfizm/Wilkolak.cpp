#include "Wilkolak.h"

using namespace std;

void Wilkolak::zwykla_funkcja() {
	cout << "Zwykla funkcja klasy Wilkolak.\n";
}

Wilkolak::Wilkolak(): x(5) {
	cout << "Konstruktor klasy Wilkolak.\n";
}

Wilkolak::~Wilkolak() {cout << "Destruktor klasy Wilkolak.\n";}
