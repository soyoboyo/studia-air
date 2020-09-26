#pragma once
#include "Czlowiek.h"
#include "Wilk.h"

using namespace std;

/* Zad 7 - Polimorfizm:
przes�anianie element�w - Czlowiek::przeslona();
polimorfizm - main.cpp
funkcje wirtualne - Wilkolak.h
klasy abstrakcyjne - Wilkolak.h
destruktory wirtualne - Wilkolah.h

Napisz program demostruj�cy wymienione elementy. 

Poka� r�nice przy u�yciu modyfikator�w virtual 
przy funkcjach i bez tych modyfikator�w - main.cpp

****************************************************

co to jest klasa abstrakcyjna?
klasa kt�ra s�u�y tylko do dziedziczenia i nie reprezentuje �adnego konkretnego obiektu

r�nica mi�dzy zwyk�ym destruktorem, a wirtualnym?
w przypadku polimorfizmu
zwyk�y: zostanie usuni�ta tylko instancja klasy bazowej
wirtualny: zostn� TE� usuni�te instancje klas pochodnych

*/

int main() {

	char znak = 11;

	Wilkolak *wsk;

	do {
		cout << "Czy mamy teraz pelnie? ( t / n / 0 = wyjscie)" << endl;
		cin >> znak;
		// je�eli jest pe�nia to mamy Wilka
		if (znak == 't' || znak == 'T') {
			wsk = new Wilk("Benek", "zielonego");
			cout << endl;
			wsk->przedstaw_sie(); // funkcja klasy wilk
			wsk->zwykla_funkcja(); // funckja klasy wilkolak
			cout << endl;
			delete wsk;

		}
		// je�eli nie ma pe�ni to mamy Czlowieka
		else if (znak == 'n' || znak == 'N') {
			wsk = new Czlowiek("Zbyszek", 5000);
			cout << endl;
			wsk->przedstaw_sie(); // funkcja klasy czlowiek
			wsk->zwykla_funkcja(); // funckja klasy wilkolak
			cout << endl;
			delete wsk;
		}

	} while (znak != 48);


	// przeslanianie element�w o takiej samej nazwie
	Czlowiek Bolek; // konstruktor domy�lny z inn� list� inicjalizacyjn�
	Bolek.przeslona(); 
	

	cout << "Dziekuje :)\n";
	return 0;
}