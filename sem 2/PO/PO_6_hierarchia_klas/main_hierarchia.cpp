#include "Wnuk.h"
#define IMIE(n) #n

using namespace std;

/*
Zadanie 6: Hierarchia klas

dziedziczenie wielopoziomowe, wielobazowe, virtualne, 
zasady inicjalizacji i destrukcji obiektów. 

Napisz program sprawdzaj¹cy ró¿ne warianty struktur hierarchii i dziedziczenia,
kolejnoœæ wywo³ywania konstruktorów,
kolejnoœæ inicjalizacji sk³adowych w klasach pochodnych i podstawowych. 
Dziedziczenie wirtualne.

*/


/*
na czym polega zysk je¿eli u¿ywamy dziedziczenia wirtualnego?
- obiekt klasy syn i wnuk siê zmniejszy³, bo sk³adniki siê nie duplikuj¹
- nie ma wieloznacznoœci

*/




int main() {

	Ojciec *Janusz = new Ojciec();
	cout << IMIE(Janusz) << endl;
	Janusz->przedstaw_sie();
	cout << endl; 	cout << endl;

	Matka *Grazyna = new Matka();
	cout << IMIE(Grazyna) << endl;
	Grazyna->przedstaw_sie();
	cout << endl; 	cout << endl;

	Syn *Baltek = new Syn();	
	cout << IMIE(Baltek) << endl;
	Baltek->przedstaw_sie();
	cout << endl; 	cout << endl;

	Wnuk *Dyzio = new Wnuk();
	cout << IMIE(Dyzio) << endl;
	Dyzio->przedstaw_sie();
	cout << endl;  	cout << endl;

	Wnuk Hyzio;
	Hyzio.przedstaw_sie();
	
	


	delete Janusz;
	delete Grazyna;
	delete Baltek;
	delete Dyzio;

	return 0;
}