#include "Carlier.h"



using namespace std;

Carlier::Carlier() : a(0), b(0), c(-1), U(0), UB(INT_MAX), LB(0), r_plim(INT_MAX), p_plim(0), q_plim(INT_MAX), r_mem(-2), q_mem(-2), nr_mem(0)  {}

int Carlier::carlier(Carlier &ob) 
{
	int i = 0;
	////////// KROK 1
	ob.U = ob.schrage_bez(); // wartoœæ funkcji celu dla algorytmu schrage bez

	 ////////// KROK 2
	if (ob.U < ob.UB) // je¿eli 
	{
		ob.UB = ob.U;
		for (i = 0; i < n; i++)
		{
			ob.PI_opt[i] = ob.PI[i];
		}
	}

	////////// KROK 3
	ob.znajdz_b();
	ob.znajdz_a();
	ob.znajdz_c();
	
	cout << "Zadanie b:\n" << "\tPozycja w permutacji: " << ob.b + 1 << " z " << n << "\n\tNumer zadania: " << ob.PI[b].nr << endl;
	cout << "Zadanie a:\n" << "\tPozycja w permutacji: " << ob.a + 1 << " z " << n << "\n\tNumer zadania: " << ob.PI[a].nr << endl;
	cout << "Zadanie c:\n" << "\tPozycja w permutacji: " << ob.c + 1 << " z " << n << "\n\tNumer zadania: " << ob.PI[c].nr << endl;

	////////// KROK 4
	if (ob.c == -1) // jeœli c nie istnieje
	{
		cout << "\tNie znaleziono zadania c!!!\n";
		return ob.U; // to znaczy ¿e schrage_bez znalaz³ rozwi¹zanie optymalne
	}


	////////// KROK 5
	for (i = ob.c + 1; i <= ob.b; i++)
	{
		// spoœród zadañ po c+1 ale przed blokiem b
		
		ob.r_plim = min(ob.r_plim, ob.PI[i].r);// znaleŸæ najmiejsze r, czyli r_plim
		
		ob.p_plim += ob.PI[i].p;// dodaæ wszytkie p, czyli p_plim
		
		ob.q_plim = min(ob.q_plim, ob.PI[i].q); // znaleŸæ najmiejsze q, czyli q_plim
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	////////// KROK 6
	if (ob.r_mem == -2)
	{
		ob.nr_mem = ob.PI[c].nr;
		ob.r_mem = ob.PI[c].r;
	}
	
	// wymuœ aby zadanie c bylo wykonywanie PO bloku K
	ob.PI[c].r = max(ob.PI[c].r, ob.r_plim + ob.p_plim);

	////////// KROK 7
	ob.LB = ob.schrage_z();

	////////// KROK 8
	if (ob.LB < ob.UB)
	{
		cout << "\tPierwszy if spelniony\n\n\n";
		////////// KROK 9
		ob.UB = ob.carlier(ob);
	}
	////////// KROK 10
	for (i = 0; i < n; i++)
	{
		if (ob.nr_mem == ob.PI[i].nr)
			ob.PI[i].r = ob.r_mem; // odtwórz r zadania c
	}
	ob.r_mem = -2;

	//////////////////////////////////////////////////////////////////////////////////////////
	////////// KROK 11
	if (ob.q_mem == -2) 
	{
		ob.nr_mem = ob.PI[c].nr;
		ob.q_mem = ob.PI[c].q;
	}
	// wymuœ aby zadanie c by³o wykonywanie PRZED blokiem K
	ob.PI[c].q = max(ob.PI[c].q, ob.q_plim + ob.p_plim);

	////////// KROK 12
	ob.LB = ob.schrage_z(); 

	////////// KROK 13
	if (ob.LB < ob.UB)
	{
		cout << "\tDrugi if spelniony\n\n\n\n";
		////////// KROK 14
		ob.UB = ob.carlier(ob);
		
	}
	////////// KROK 15
	for (i = 0; i < n; i++) 
	{
		if(ob.nr_mem == ob.PI[i].nr) // je¿eli numer zadania zgadza siê z zapamiêtanym
			ob.PI[i].q = ob.q_mem; // odtwórz q zadania c
	}
	
	ob.q_mem = -2;

	return ob.U;

}



int Carlier::znajdz_b()
{
	int i = 0;
	for (i = n - 1; i > 0; i--)
	{
		if (Cmax_bez == PI[i].C + PI[i].q)
		{
			b = i;
			break;
		}
	}
	
	return b;
}

int Carlier::znajdz_a()
{
	int suma = 0, i;

	// najmniejsze takie a, czyli trzeba iœæ od lewej
	for(a = 0; a < b; a++)
	{

		suma = 0;
		for (i = a; i <= b; i++)
		{
			suma += PI[i].p; // suma P zadañ od a do b
		}
		
		if (Cmax_bez == (PI[a].r + suma + PI[b].q))
		{
			return a;
		}
	}
	return a;
	
}

int Carlier::znajdz_c()
{
	c = -1;
	int i;

	// najwiêksze takie c, czyli trzeba iœæ od prawej
	for (i = b; i >= a; i--)
	{
		if (PI[i].q < PI[b].q) 
		{
			c = i;
			break;
		}
	}
	
	return c;
}



Carlier::~Carlier() {}
