#pragma once
#include "Czlowiek.h"

using namespace std;

class Ojciec : public Czlowiek
{
public:
	Ojciec();
	~Ojciec();

	int wzrost;
	string cecha;


	void przedstaw_sie();
};

