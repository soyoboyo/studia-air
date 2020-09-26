#pragma once
#include "Czlowiek.h"

using namespace std;

class Matka : public Czlowiek
{
public:
	Matka();
	~Matka();

	int wzrost;
	string cecha;

	void przedstaw_sie();
};

