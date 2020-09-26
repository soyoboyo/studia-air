 #pragma once

#include "Samochod_ciezarowy.h"
#include "Samochod_osobowy.h"
#include "Jednoslad.h"

#include <Windows.h>


using namespace std;

/* Dziedziecznie:
dziedziczenie publiczne, prywatne i zabezpieczone oraz zachowanie siê dziedziczonych sk³adowych,
konstruktory (z parametrem i bez) i destrkutory, listy inicjalizacyjne.
Napisz program, w któym stworzone bêd¹ dynamicznie (tj. stworzone na pewien czas, a nastêpnie zniszczone)
nastêpujêce obiekty: unicykl, bicykl, sedan i jelcz. 
Obiekty te maj¹ wypisaæ na monitorze wszystkie informacje o sobie poprzez wywo³anie metody
"przedstaw_sie", a nastêpnie maja zostaæ zniszczone. 

Zalecenia: zastanowiæ siê nad stworzeniem hierarchii klas: pojazd, samochód osobowy, samochód ciê¿arowy.
Proponowane cechy obiektów: liczba kó³, waga, obci¹¿enie, ³adownoœæ, liczba pasa¿erów, itp.
Pola klas powinny byæ prywante, a wartoœci im nadawaæ mog¹ publiczne metody
(np. podaj liczbê kó³, podaj wagê itp.) lub konstruktory.
Ka¿da klasa ma mieæ swojê deklaracjê w osobnym pliku *.h, a defincje metod w odpowiednim pliku *.cpp.
Program ma demostrowaæ dzia³anie konstruktorów (powinny byæ ró¿ne) i destruktorów
oraz wp³ywu rodzaju dziedzicznia na dziedziczone sk³adowe.

listy inicjalizacyjnej uzywamy gdy chcemy mieæ stale pola w klasie modyfikator const

listy s¹ niezbêde tak¿e gdy chcemy u¿ywaæ innych ni¿ bezargumentowych konstruktorów klas bazowych

no i jeszcze goœcie

zad6:
najpierw przodkowie, potem goœcie (czyli obiekty innej klasy w klasie np typ A obiekt w klasie B), a potem my


pytanie 1:
jak pokazaæ ró¿nica miêdzy typem dziedziczenia?

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
