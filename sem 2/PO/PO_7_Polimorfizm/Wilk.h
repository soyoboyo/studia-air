#pragma once
#include "Wilkolak.h"

using namespace std;

class Wilk : public Wilkolak
{
public:

	void przedstaw_sie();
	void zwykla_funkcja();

	Wilk(string name, string kolor);
	~Wilk();
	
private:
	string futro;
};

