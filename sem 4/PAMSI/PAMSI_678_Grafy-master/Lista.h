#pragma once
#include "Graf.h"

using namespace std;

class Lista : public Graf {
private:
	vector< pair<int, int> > *VP;
	void dodajKrawedz(int u, int v, int w);
	void wyczysc();
	void dealokuj();
	void realokuj();
	
	
public:
	Lista();
	~Lista();
	int getKoszt(int u, int v);
	pair<int, int> sasiedzi(int u, int w)
	{
		if (w < VP[u].size())
			return VP[u][w];
		return make_pair(-1, -1);
	}
};