#pragma once
#include "Zadanie.h"

using namespace std;

Zadanie::Zadanie() {} // konstruktor domy�lny
Zadanie::~Zadanie() {} // destruktor


// przeci��enie operatora potrzebne do �atwego wy�wieltnia zada�
ostream& operator<<(ostream& stream, const Zadanie& o) {
	stream << o.nr << " || " << o.r << " " << o.p << " " << o.q << " " << o.C << " " << o.Cq << endl;
	return stream;
}







