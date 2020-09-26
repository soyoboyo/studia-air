#include "Syn.h"


void Syn::przedstaw_sie()
{
	cout << "Obiekt typu Syn, grupa krwi: " << Ojciec::grupa_krwi 
		<< ", wzrost: " << wzrost
		<< ", szczegolna cecha po ojcu: " << Ojciec::cecha 
		<< " i po matce: " << Matka::cecha
		<< "\noraz moja szczegolna cecha: " << cecha << endl;
}


Syn::Syn() : cecha("odstajace uszy")
{
	wzrost = (Ojciec::wzrost + Matka::wzrost) / 2;
	cout << "\t\tKonstruktor klasy Syn.\n"; 
}


Syn::~Syn() {cout << "\t\tDestruktor klasy Syn.\n";}
