#include "Wnuk.h"

void Wnuk::przedstaw_sie() 
{
	cout << "Obiekt typu Wnuk, grupa krwi: " << Matka::grupa_krwi
		<< ", wzrost: " << wzrost
		<< ", szczegolna cecha po dziadku: " << Ojciec::cecha
		<< " i po babci: " << Matka::cecha
		<< "\noraz po ojcu: " << Syn::cecha << endl;

}

Wnuk::Wnuk() 
{ 
	cout << "\t\t\tKonstruktor klasy Wnuk.\n"; 
}


Wnuk::~Wnuk(){cout << "\t\t\tDestruktor klasy Wnuk.\n";}