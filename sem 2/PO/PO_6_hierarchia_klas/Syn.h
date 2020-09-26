#pragma once
#include "Ojciec.h"
#include "Matka.h"

class Syn : public Matka, public Ojciec
{
public:
	Syn();
	~Syn();

	string cecha;
	int wzrost;
	void przedstaw_sie();
};

