#pragma once
#include "Zadanie.h"

using namespace std;

Zadanie::Zadanie() {} // konstruktor domy�lny
Zadanie::~Zadanie() {} // destruktor

					   // przeci�zanie operatora niezb�dne aby koeljka obs�ugiwa�a obiekty typu Zadanie
bool operator<(const Zadanie& o1, const Zadanie& o2) {
	return o1.q > o2.q;
}
// przeci��enie operatora potrzebne do �atwego wy�wietlania zada�
ostream& operator<<(ostream& stream, const Zadanie& o) {
	stream << o.nr << " || " << o.r << " " << o.p << " " << o.q << endl;
	return stream;
}






