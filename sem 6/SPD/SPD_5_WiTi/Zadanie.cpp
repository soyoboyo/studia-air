#pragma once
#include "Zadanie.h"

// przeci¹¿enie operatora potrzebne do ³atwego wyœwieltnia zadañ
ostream& operator<<(ostream& stream, const Zadanie& o) {
	stream << o.nr << " || " << o.p << " " << o.w << " " << o.d  << endl;
	return stream;
}




Zadanie::Zadanie() : nr(0), p(0), w(0), d(0) {}
Zadanie::~Zadanie() {}
