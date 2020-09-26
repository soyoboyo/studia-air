#pragma once
#include "Zadanie.h"

using namespace std;

Zadanie::Zadanie() {} // konstruktor domyœlny
Zadanie::~Zadanie() {} // destruktor


// przeci¹¿enie operatora potrzebne do ³atwego wyœwieltnia zadañ
ostream& operator<<(ostream& stream, const Zadanie& o) {
	stream << o.nr << " || " << o.r << " " << o.p << " " << o.q << " " << o.C << " " << o.Cq << endl;
	return stream;
}







