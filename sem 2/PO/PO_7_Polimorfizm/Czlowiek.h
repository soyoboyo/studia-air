#pragma once
#include "Wilkolak.h"

using namespace std;

class Czlowiek : public Wilkolak
{
public:

	void przedstaw_sie();
	void zwykla_funkcja();
	void przeslona();

	Czlowiek();
	Czlowiek(string name, int lata);
	~Czlowiek();

private:
	int wiek;
	int x;
};

