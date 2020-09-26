#pragma once
#include "Lista.h"

using namespace std;

void Lista::dodajKrawedz(int u, int v, int waga)
{
	VP[u].push_back(make_pair(v, waga));
	VP[v].push_back(make_pair(u, waga));
}

void Lista::wyczysc()
{
	for (int i = 0; i < V; i++)
		VP[i].clear();
}

void Lista::dealokuj()
{
	if (VP != NULL)
		delete[] VP;
}

void Lista::realokuj()
{
	VP = new vector< pair<int, int> >[V];
}

int Lista::getKoszt(int u, int v) 
{
	for (int i = 0; i < VP[u].size(); i++)
		if (VP[u][i].first == v)
			return VP[u][i].second;
	return -1;
}

Lista::Lista() { VP = NULL; }
Lista::~Lista() { dealokuj(); }

