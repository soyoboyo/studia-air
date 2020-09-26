#include "Zadanie.h"

using namespace std;

void Zadanie::policzSume()
{
	int i;
	suma = 0;
	for (i = 0; i < czasy.size(); i++)
	{
		suma += czasy[i];
	}
}

Zadanie::Zadanie() {}
Zadanie::~Zadanie() {}
