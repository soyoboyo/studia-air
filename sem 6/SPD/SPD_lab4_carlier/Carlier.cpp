#include "Carlier.h"



using namespace std;

Carlier::Carlier() : a(0), b(0), c(-1), U(0), UB(INT_MAX), LB(0) {}

int Carlier::carlier(Carlier &ob, int UB) 
{
	int i = 0;
	int r_mem = 0;
	int q_mem = 0;
	int nr_mem = 0;
	
	int LB = 0;
	int A = 0, B = 0, C = -1;
	int r_plim = INT_MAX, p_plim = 0, q_plim = INT_MAX;
	
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
	B = ob.znajdz_b(B);
	A = ob.znajdz_a(A, B);
	C = ob.znajdz_c(A, B);
	
	cout << "Zadanie b:\n" << "\tPozycja w permutacji: " << B + 1 << " z " << n << "\n\tNumer zadania: " << ob.PI[B].nr << endl;
	cout << "Zadanie a:\n" << "\tPozycja w permutacji: " << A + 1 << " z " << n << "\n\tNumer zadania: " << ob.PI[A].nr << endl;
	cout << "Zadanie c:\n" << "\tPozycja w permutacji: " << C + 1 << " z " << n << "\n\tNumer zadania: " << ob.PI[C].nr << endl;

	////////// KROK 4
	if (C == -1) // jeœli c nie istnieje
	{
		cout << "\tNie znaleziono zadania c!!!\n";
		return ob.U; // to znaczy ¿e schrage_bez znalaz³ rozwi¹zanie optymalne
	}


	////////// KROK 5
	for (i = C + 1; i <= B; i++)
	{
		// spoœród zadañ po c+1 ale przed blokiem b
		
		r_plim = min(r_plim, ob.PI[i].r);// znaleŸæ najmiejsze r, czyli r_plim
		
		p_plim += ob.PI[i].p;// dodaæ wszytkie p, czyli p_plim
		
		q_plim = min(q_plim, ob.PI[i].q); // znaleŸæ najmiejsze q, czyli q_plim
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	////////// KROK 6
	
	nr_mem = ob.PI[C].nr;
	r_mem = ob.PI[C].r;
	
	
	// wymuœ aby zadanie c bylo wykonywanie PO bloku K
	ob.PI[C].r = max(ob.PI[C].r, r_plim + p_plim);

	////////// KROK 7
	LB = ob.schrage_z();

	////////// KROK 8
	if (LB < ob.UB)
	{
		cout << "\tPierwszy if spelniony\n\n\n";
		////////// KROK 9
		ob.UB = ob.carlier(ob, ob.UB);
	}
	////////// KROK 10
	for (i = 0; i < n; i++)
	{
		if (nr_mem == ob.PI[i].nr)
			ob.PI[i].r = r_mem; // odtwórz r zadania c
	}
	

	//////////////////////////////////////////////////////////////////////////////////////////
	////////// KROK 11
	
	//nr_mem = ob.PI[x].nr;
	q_mem = ob.PI[C].q;
	
	// wymuœ aby zadanie c by³o wykonywanie PRZED blokiem K
	ob.PI[C].q = max(ob.PI[C].q, q_plim + p_plim);

	////////// KROK 12
	LB = ob.schrage_z(); 

	////////// KROK 13
	if (LB < ob.UB)
	{
		cout << "\tDrugi if spelniony\n\n\n\n";
		////////// KROK 14
		U = ob.carlier(ob, ob.UB);
		
	}
	////////// KROK 15
	for (i = 0; i < n; i++) 
	{
		if(nr_mem == ob.PI[i].nr) // je¿eli numer zadania zgadza siê z zapamiêtanym
			ob.PI[i].q = q_mem; // odtwórz q zadania c
	}
	
	
	return ob.U;

}



int Carlier::znajdz_b(int &b)
{
	b = 0;
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

int Carlier::znajdz_a(int &a, int &b)
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

int Carlier::znajdz_c(int a, int b)
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
