#include "Matka.h"

void Matka::przedstaw_sie()
{
	cout << "Obiekt typu Matka, grupa krwi: " 
		<< grupa_krwi << ", wzrost: " << wzrost
		<< ", szczegolna cecha: " << cecha 
		<< endl;

}

Matka::Matka() : wzrost(170), cecha("niebieskie oczy")
{
	this->grupa_krwi = "0-";
	cout << "\tKonstruktor klasy Matka.\n"; 
}


Matka::~Matka() { cout << "\tDestruktor klasy Matka.\n"; }