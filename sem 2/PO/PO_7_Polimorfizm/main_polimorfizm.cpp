#pragma once
#include "Czlowiek.h"
#include "Wilk.h"

using namespace std;

/* Zad 7 - Polimorfizm:
przes³anianie elementów - Czlowiek::przeslona();
polimorfizm - main.cpp
funkcje wirtualne - Wilkolak.h
klasy abstrakcyjne - Wilkolak.h
destruktory wirtualne - Wilkolah.h

Napisz program demostruj¹cy wymienione elementy. 

Poka¿ ró¿nice przy u¿yciu modyfikatorów virtual 
przy funkcjach i bez tych modyfikatorów - main.cpp

****************************************************

co to jest klasa abstrakcyjna?
klasa która s³u¿y tylko do dziedziczenia i nie reprezentuje ¿adnego konkretnego obiektu

ró¿nica miêdzy zwyk³ym destruktorem, a wirtualnym?
w przypadku polimorfizmu
zwyk³y: zostanie usuniêta tylko instancja klasy bazowej
wirtualny: zostn¹ TE¯ usuniête instancje klas pochodnych

*/

int main() {

	char znak = 11;

	Wilkolak *wsk;

	do {
		cout << "Czy mamy teraz pelnie? ( t / n / 0 = wyjscie)" << endl;
		cin >> znak;
		// je¿eli jest pe³nia to mamy Wilka
		if (znak == 't' || znak == 'T') {
			wsk = new Wilk("Benek", "zielonego");
			cout << endl;
			wsk->przedstaw_sie(); // funkcja klasy wilk
			wsk->zwykla_funkcja(); // funckja klasy wilkolak
			cout << endl;
			delete wsk;

		}
		// je¿eli nie ma pe³ni to mamy Czlowieka
		else if (znak == 'n' || znak == 'N') {
			wsk = new Czlowiek("Zbyszek", 5000);
			cout << endl;
			wsk->przedstaw_sie(); // funkcja klasy czlowiek
			wsk->zwykla_funkcja(); // funckja klasy wilkolak
			cout << endl;
			delete wsk;
		}

	} while (znak != 48);


	// przeslanianie elementów o takiej samej nazwie
	Czlowiek Bolek; // konstruktor domyœlny z inn¹ list¹ inicjalizacyjn¹
	Bolek.przeslona(); 
	

	cout << "Dziekuje :)\n";
	return 0;
}