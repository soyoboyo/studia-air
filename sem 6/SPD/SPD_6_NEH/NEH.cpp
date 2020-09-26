#include "NEH.h"

using namespace std;

void NEH::algorytmNEH() 
{
	int i = 0;

	sort(wczytane.begin(), wczytane.end()); // sortowanie
	cout << "Posortowane wg sumy:\n";
	wyswietl(wczytane); // wyœwietl posorotwane zadania wg sumy czasów

	// weŸ 2 pierwsze zadania
	zad.push_back(wczytane[0]);
	zad.push_back(wczytane[1]);
	dwaPierwsze(); // znajdŸ dla nich najlepsze u³o¿enie (2 mo¿liwoœci)

	for (i = 2; i < n; i++)
	{
		zad.push_back(wczytane[i]); // weŸ kolejne zadanie
		znajdzCmax(); // znajdŸ najlepsz¹ kolejnoœæ
	}
}

void NEH::dwaPierwsze()
{
	int dwa[2];
	int i = 0, j = 0, z = 0;

	cout << "\n2 pierwsze zadania\n";
	for (z = 0; z < zad.size(); z++)
	{
		// pierwsze zad na maszynie 1 zaczyna siê w chwili 0
		zad[0].pocz.push_back(0); 
		// drugie zadanie na maszynie zaczyna siê od razu po pierwszym
		zad[1].pocz.push_back(zad[0].pocz[0] + zad[0].czasy[0]);
		// czasy wszystkich pocz¹tków pierwszego zadania na ka¿dej maszynie
		for (i = 0; i < m - 1; i++)
		{
			zad[0].pocz.push_back(zad[0].pocz[i] + zad[0].czasy[i]);
		}
		//
		for (i = 1; i < m; i++)
		{
			zad[1].pocz.push_back(max(zad[1].czasy[i - 1] , zad[0].czasy[i]) + zad[0].pocz[i]);
		}

		//for (j = 0; j < zad.size(); j++) { cout << zad[j].nr << " || "; for (i = 0; i < lMasz; i++) { cout << zad[j].pocz[i] << " "; } cout << endl; }

		// pocz¹tek ostatniego zadania na ostatniej maszynie
		// + czas jego wykonania na ostatniej maszynie
		Cmax = zad.back().pocz.back() + zad.back().czasy.back();
		dwa[z] = Cmax;
		//cout << "Cmax = " << Cmax << endl;
		zad[0].pocz.clear(); // reset tablicy pocz¹tków
		zad[1].pocz.clear(); // reset tablicy pocz¹tków
		swap(zad[0], zad[1]); 

	}
	// je¿eli piewsze by³o lepsze to zamieñ
	if (dwa[0] > dwa[1])
	{
		Cmax = dwa[1];
		swap(zad[0], zad[1]);
	}
	else { // a je¿eli drugie by³o lepsze to zostaw
		Cmax = dwa[0];
	}
	//cout << "Lepsze Cmax = " << Cmax << endl;
}

void NEH::znajdzCmax()
{
	int najlepsze = INT_MAX, pozycja = 0;
	int i = 0, j = 0, wst = 0;
	Cmax = INT_MAX; // reset Cmax
	int lewe = 0, prawe = 0;

//	cout << endl;
	for (wst = 0; wst < zad.size(); wst++)
	{
		zad[0].pocz.push_back(0); // pierwsze zadanie na pierwszej maszynie: start = 0
		
		for (i = 0; i < m - 1; i++) // pocz¹tki dla pierwszego zadania
		{
			zad[0].pocz.push_back
			(
				zad[0].pocz[i] 
				+ zad[0].czasy[i]
			);
		}

		for (i = 1; i < zad.size(); i++) // pierwsza maszyna
		{
			zad[i].pocz.push_back
			(
				zad[i - 1].pocz[0]
				+ zad[i - 1].czasy[0]
			);
		}

		for (j = 1; j < zad.size(); j++) // zadania od trzeciego do ostatniego
		{
			for (i = 1; i < m; i++) // maszyny od drugiej do ostatniej
			{
				zad[j].pocz.push_back
				( 
					max( 
						zad[j - 1].czasy[i] + zad[j - 1].pocz[i],
						zad[j].czasy[i - 1] + zad[j].pocz[i - 1]
					)
				);
			}
		}

		// wyœwietl wstawienia
		for (j = 0; j < zad.size(); j++) { cout << zad[j].nr << " || "; for (i = 0; i < lMasz; i++) { cout << zad[j].pocz[i] << " "; } cout << endl; }
		
		Cmax = (zad.back().pocz.back() + zad.back().czasy.back());
		
		cout << "Cmax = " << Cmax << endl; // poka¿ Cmax dla ka¿dej opcji

		for (i = 0; i < zad.size(); i++) {
			zad[i].pocz.clear(); // reset tablicy pocz¹tków ka¿dego zadania
		}

		// je¿eli znalaz³ nowe najlepsze zadanie
		if (Cmax < najlepsze) { 
			najlepsze = Cmax; // to zapamiêtaj nowe Cmax
			pozycja = 0; // nie trzeba przestawiaæ zadania z powrotem
		}
		else { // je¿eli nowe Cmax jest gorsze ni¿ najlepsze
			pozycja++; // przestaw zadanie tyle razy
		}


		prawe = zad.size() - wst - 1;
		lewe = zad.size() - wst - 2;
		if (wst < zad.size()-1)
			swap(zad[lewe], zad[prawe]);

		
	}
	//cout << "Nowa kolejnosc zadan:\n";
	for (i = 0; i < pozycja; i++)
	{
		swap(zad[i], zad[i + 1]);
	}
//	wyswietl(zad);
	
	Cmax = najlepsze;
	//cout << "Cmax nowej = " << najlepsze <<  endl;
}

bool NEH::wczytaj_plik(std::string nazwaPliku) // funkcja wczytujca dane z plik do tablicy
{
	int i = 0, k =0; // zmienne iteracyjne
	Zadanie tmp; // obiekt tmp (pomocniczy)
	int t; // zmienna tmp (pmocnicza)
	
	ifstream plik;
	plik.open(nazwaPliku.c_str());
	if (!plik.good()) // jezeli nie ma pliku o podanej nazwie
		return false;

	plik >> n;
	cout << "Liczba zadan: " << n << endl;
	plik >> m;
	cout << "Liczba maszyn: " << m << endl;
	
	lZad = n;
	lMasz = m;

	for (k = 0; k < n; k++) // ka¿de zadanie / wiersz
	{
		tmp.nr = (k + 1); // okreœl numer zadania
		wczytane.push_back(tmp); // dodaj puste zadanie do tablicy

		for (i = 0; i < m; i++) // ka¿da maszyna / kolumna
		{
			plik >> t; 
			wczytane[k].czasy.push_back(t); // dodaj czas ka¿dej maszyny
		}
		wczytane[k].policzSume(); // policz sumê czasów na wszystkich maszynach
	}
	return true;
}

void NEH::wyswietl(vector<Zadanie> &tab)
{
	int i = 0, k = 0;
	for (k = 0; k < tab.size(); k++)
	{
		cout << tab[k].nr << " || ";
		for (i = 0; i < m; i++)
		{
			cout << tab[k].czasy[i] << " ";
		}
		if (tab.size() == wczytane.size())
			cout << tab[k].suma << endl;
		else
			cout << endl;
	}
}


NEH::NEH() : Cmax(INT_MAX) {}
NEH::~NEH() {}
