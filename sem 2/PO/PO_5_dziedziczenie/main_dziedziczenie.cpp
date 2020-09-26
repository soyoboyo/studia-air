 #pragma once

#include "Samochod_ciezarowy.h"
#include "Samochod_osobowy.h"
#include "Jednoslad.h"

#include <Windows.h>


using namespace std;

/* Dziedziecznie:
dziedziczenie publiczne, prywatne i zabezpieczone oraz zachowanie si� dziedziczonych sk�adowych,
konstruktory (z parametrem i bez) i destrkutory, listy inicjalizacyjne.
Napisz program, w kt�ym stworzone b�d� dynamicznie (tj. stworzone na pewien czas, a nast�pnie zniszczone)
nast�puj�ce obiekty: unicykl, bicykl, sedan i jelcz. 
Obiekty te maj� wypisa� na monitorze wszystkie informacje o sobie poprzez wywo�anie metody
"przedstaw_sie", a nast�pnie maja zosta� zniszczone. 

Zalecenia: zastanowi� si� nad stworzeniem hierarchii klas: pojazd, samoch�d osobowy, samoch�d ci�arowy.
Proponowane cechy obiekt�w: liczba k�, waga, obci��enie, �adowno��, liczba pasa�er�w, itp.
Pola klas powinny by� prywante, a warto�ci im nadawa� mog� publiczne metody
(np. podaj liczb� k�, podaj wag� itp.) lub konstruktory.
Ka�da klasa ma mie� swoj� deklaracj� w osobnym pliku *.h, a defincje metod w odpowiednim pliku *.cpp.
Program ma demostrowa� dzia�anie konstruktor�w (powinny by� r�ne) i destruktor�w
oraz wp�ywu rodzaju dziedzicznia na dziedziczone sk�adowe.

listy inicjalizacyjnej uzywamy gdy chcemy mie� stale pola w klasie modyfikator const

listy s� niezb�de tak�e gdy chcemy u�ywa� innych ni� bezargumentowych konstruktor�w klas bazowych

no i jeszcze go�cie

zad6:
najpierw przodkowie, potem go�cie (czyli obiekty innej klasy w klasie np typ A obiekt w klasie B), a potem my


pytanie 1:
jak pokaza� r�nica mi�dzy typem dziedziczenia?

opcje:
- sprawdzic dostepnosc skladowych w klasie pochodnej bezposrednio A <- B
- sprawdzc dostepnosc skladowych w klasie pochodnej klasy pochodnej A <- B-  <- C




*/



int main() {


	
	Samochod_osobowy *sedan = new Samochod_osobowy(4, 5, "QSD", true, "DW JKLP0", "BMW");
	sedan->przedstaw_sie();
	delete sedan;

	cout << endl;

	Samochod_ciezarowy *jelcz = new Samochod_ciezarowy(4, 3,  "dostawczak", 5000, "KR 4567", "VOLVO");
	jelcz->przedstaw_sie();
	delete jelcz;

	cout << endl;

	Jednoslad *bicykl = new Jednoslad(2, 1, "rowerek", "zielony");;
	bicykl->przedstaw_sie();
	delete bicykl;

	cout << endl;

	int dla_referencji;

	Jednoslad *monocykl = new Jednoslad();
	monocykl->przedstaw_sie();
	delete monocykl;

	cout << endl;

	return 0;
}
