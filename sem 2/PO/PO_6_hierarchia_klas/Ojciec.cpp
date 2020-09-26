#include "Ojciec.h"

void Ojciec::przedstaw_sie()
{
	cout << "Obiekt typu Ojciec, grupa krwi: " 
		<< grupa_krwi << ", wzrost: " << wzrost
		<< ", szczegolna cecha: " << cecha 
		<< endl;


}

Ojciec::Ojciec() :  wzrost(190) , cecha("brazowe wlosy")
{
	this->grupa_krwi = "A+";
	cout << "\tKonstruktor klasy Ojciec.\n"; 
}


Ojciec::~Ojciec() {cout << "\tDestruktor klasy Ojciec.\n";}
