#pragma once
#include "WiTi.h"
#include <fstream>
#include <bitset>


using namespace std;



void WiTi::algorytm_WiTi() {

	int kom = 1; // adres kombinacji w tablicy
	int i; // 

	Kombinacja tmp;

	kombinacje.push_back(tmp); // zbior pusty na pozycji 0
	//kombinacje[0].kara = 0; // na wszelki wypadek, bo zbiór pusty zawsze ma karê = 0

	for (kom = 1; kom <= ilosc_kombinacji-1; kom++)
	{
		kombinacje.push_back(tmp); // dodanie nowej kombinacji
		kombinacje[kom].kara = INT_MAX; // od razu zajebista kara na start

		for (i = 0; i < n; i++)
		{
			// czy na pozycji i-tej w adresie kom jest ustawiona 1
			if (sprawdz_bit(kom, i)) 
			{
				kombinacje[kom].podzbior.push_back(zadania[i]); // dodaj zadanie
			}
		}
		kombinacje[kom].ilosc = kombinacje[kom].podzbior.size(); // pole pomocnicze
		kombinacje[kom].policz_T(); // policzenie ile wykonuj¹ siê wszystkie zadania
	}
	
	/*********************  W£AŒCIWY ALGORYTM ************************/
	for (kom = 1; kom <= ilosc_kombinacji-1; kom++)
	{
	//	cout << "Nr kombinacji: " << kom << endl;
		kombinacje[kom].kara = INT_MAX; 

		for (i = 0; i <= n; i++)
		{
			
		//	if (i < kombinacje[kom].ilosc) // ¿eby gupol nie wy³azi³ po za zakres
			//	cout << kombinacje[kom].podzbior[i]; // wyœwietl zadanie

			if (sprawdz_bit(kom, i)) 
			{
				k1 = policz_kare(kom, i);
				adr = reset(kom, i);
				k2 = kombinacje[adr].kara; // kara z poprzedniej kombnacji
				
				//	cout << "adr: " << adr << endl;	cout << "k1 = " << k1 << ", k2 = " << k2 << endl;
				if (k1 + k2 < kombinacje[kom].kara)
				{
					kombinacje[kom].kara = k1 + k2;
					kombinacje[kom].ostatnie = 1 << i;
					//cout << "ostatnie: " << kombinacje[kom].ostatnie<< endl;
						
				}

			}
		}
	/*************************************************************/


	// pokazanie dzia³ania ca³ego algorytmu i atrybutów ka¿dej kombinacji
//	cout << "ilosc = " << kombinacje[kom].ilosc << endl; cout << "T = " << kombinacje[kom].T << endl; cout << "kara = " << kombinacje[kom].kara << endl; cout << "ostatnie: " << kombinacje[kom].ostatnie << endl; cout << endl;

	// cout << "ilosc = " << kombinacje[kom].ilosc << endl;
	// cout << "T = " << kombinacje[kom].T << endl;
	// cout << "kara = " << kombinacje[kom].kara << endl;
	// cout << "ostatnie: " << kombinacje[kom].ostatnie << endl;
	// cout << endl;

	}
	cout << "Kara ostateczna: " << kombinacje[kom-1].kara << endl;
	znajdz_kolejnosc();
}



bool WiTi::sprawdz_bit(int war, int poz) {
	return ((war >> poz) & 1) == 1 ? true : false;
}

int WiTi::reset(int war, int poz) {
	return 	(war &= ~(1 << poz));
};

int WiTi::policz_kare(int a, int b) {
	// a - adres kombinacji, której karê liczymy
	// b - nowe zadanie, które dorzucamy do kombinacji

	return zadania[b].w * max(0, kombinacje[a].T - zadania[b].d);
}

void WiTi::znajdz_kolejnosc()
{
	int p = ilosc_kombinacji, // adresy poszczególnych kombinacji
	zad, // indeks zadania przesuniêty bitowo np 1 << 3 
	i, wart; // zmienne pomocnicze

	// funkcja szuka kolejnoœci zadañ w ostatniej kombinacji
	// zaczyna od koñca, czyli ostatniej kombinacji
	// sprawdza które zadanie by³o ostatnie
	// wyrzuca je ze zbirou mo¿liwyc i idzie po adresie do kolejnej kombinacji
	// ^powtórz


	for (i = n; i > 0; i--)
	{
		zad = kombinacje[p - 1].ostatnie; 
		wart = (int)log2(zad) + 1; // np. log2(8) + 1 = 3 + 1 = 4 czyli zadanie nr 4
		p = p - zad; // wyrzucenie zadania z permutacji
		podzbior.push_front(wart);

	}
	cout << "Kolejnosc zadan: ";
	for (i = 0; i < n; i++)
	{
		wart = podzbior.front();
		cout << wart << " ";
		podzbior.pop_front();
		podzbior.push_back(wart);
	}
	cout << endl;

}

bool WiTi::wczytajPlik(std::string nazwaPliku) // funkcja wczytujca dane z plik do tablicy
{
	int i = 0; // zmienna iteracyjna
	ifstream plik;
	Zadanie tmp;

	plik.open(nazwaPliku.c_str());
	if (!plik.good()) // jezeli nie ma pliku o podanej nazwie
		return false;
	plik >> n;
	cout << "Liczba zadan: " << n << endl;
	cout << "Wczytane zadania: " << endl;

	for (i = 0; i < n; i++)
	{
		zadania.push_back(tmp);
		plik >> zadania[i].p >> zadania[i].w >> zadania[i].d; // wczytywanie wierszy
		zadania[i].nr = i+1;
		cout << zadania[i];
	}

	ilosc_kombinacji = 1 << n;
	
	
	return true;
}

void WiTi::wyswietl_zad(Zadanie* tablica, int rozmiar) {
	for (int i = 0; i < rozmiar; i++)
		cout << tablica[i];
	//cout << "Nr zad: " << tab[i].nr_zad << "|| " << tab[i].r << " " << tab[i].p << " " << tab[i].q << endl;
}

WiTi::WiTi() {}

WiTi::~WiTi() {}
