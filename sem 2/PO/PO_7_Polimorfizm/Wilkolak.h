#pragma once
#include <iostream>
#include <string>

using namespace std;

class Wilkolak
{
public:

	// funkcja czysto wirtualna
	virtual void przedstaw_sie() = 0; 

	void zwykla_funkcja();

	Wilkolak();
	virtual ~Wilkolak(); // tutaj pokaza� r�nice

	string imie;
	int x;
};

