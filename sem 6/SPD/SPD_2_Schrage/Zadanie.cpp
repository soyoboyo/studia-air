#pragma once
#include "Zadanie.h"

using namespace std;

Zadanie::Zadanie() {} // konstruktor domyœlny
Zadanie::~Zadanie() {} // destruktor

					   // przeci¹zanie operatora niezbêdne aby koeljka obs³ugiwa³a obiekty typu Zadanie
bool operator<(const Zadanie& o1, const Zadanie& o2) {
	return o1.q > o2.q;
}
// przeci¹¿enie operatora potrzebne do ³atwego wyœwietlania zadañ
ostream& operator<<(ostream& stream, const Zadanie& o) {
	stream << o.nr << " || " << o.r << " " << o.p << " " << o.q << endl;
	return stream;
}






