using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PAMSI_9_Statki
{
    public class Zestaw
    {
        public Statek pancernik = new Statek(4);
        public Statek fregata1 = new Statek(3);
        public Statek fregata2 = new Statek(3);
        public Statek koga1 = new Statek(2);
        public Statek koga2 = new Statek(2);
        public Statek koga3 = new Statek(2);

        public Pole[,] plansza_swoja = new Pole[10,10];
        public Pole[,] plansza_strzalow = new Pole[10, 10];

        // sprawdź ścieżkę
        public bool sprawdzSciezke(int poczX, int poczY, bool czyPion, string nazwa)
        {
            int i = 0, dlugosc = 0;
            switch (nazwa) // jaka jest długość statku
            {
                case "p": dlugosc = 4; break;
                case "f1": dlugosc = 3; break;
                case "f2": dlugosc = 3; break;
                case "k1": dlugosc = 2; break;
                case "k2": dlugosc = 2; break;
                case "k3": dlugosc = 2; break;
                default:
                    break;
            }
            for (i = 0; i < dlugosc; i++)
            {
                if (plansza_swoja[poczX, poczY].statek == true)
                {
                    return false;
                }
                if (czyPion == true) // jeżeli jest pionowo to daj go w dół
                    poczY++;
                else poczX++; // jeżeli jest poziomo to daj go w prawo
            }

            return true;
        }
        // dodawanie statku
        public void dodajStatek(int poczX, int poczY, bool czyPion, string nazwa, Color[,] tab)
        {
            int i = 0, dlugosc = 0;
            switch (nazwa) // jaka jest długość statku
            {
                case "p": dlugosc = 4; break;
                case "f1": dlugosc = 3; break;
                case "f2": dlugosc = 3; break;
                case "k1": dlugosc = 2; break;
                case "k2": dlugosc = 2; break;
                case "k3": dlugosc = 2; break;
                default:
                    break;
            }
            for (i = 0; i < dlugosc; i++)
            {
                plansza_swoja[poczX, poczY].setStatek(true);
                tab[poczX, poczY] = Color.LimeGreen;
                if (czyPion == true) // jeżeli jest pionowo to daj go w dół
                    poczY++;
                else poczX++; // jeżeli jest poziomo to daj go w prawo 
            }
        }
        // dodawanie statku AI
        public void dodAIStatek()
        {
            int x, y, i = 0, j = 0;
            bool pion = false; // 0 - poziomo, 1 - pionowo
            string[] nazwy = new string[]{ "p", "f1", "f2", "k1", "k2", "k3"};
            int[] dl = new int[] { 4, 3, 3, 2, 2, 2 };
            for(i = 0; i < 6; i++ )
            {
                
                while (true)
                {
                    Random los = new Random(DateTime.Now.Millisecond);
                    if (los.Next(0, 2) == 0)
                        pion = false;
                    else pion = true;
                    // pomniejsz obszar poszukiwań
                    if (pion)
                    {
                        x = los.Next(0, 10 );
                        y = los.Next(0, 10 - dl[i] + 1);
                    }
                    else
                    {
                        x = los.Next(0, 10 - dl[i] + 1);
                        y = los.Next(0, 10);
                    }
                    if (sprawdzSciezke(x, y, pion, nazwy[i]))
                    {
                        for (j = 0; j < dl[i]; j++)
                        {
                            plansza_swoja[x, y].setStatek(true);
                            if (pion == true) // jeżeli jest pionowo to daj go w dół
                                y++;
                           else x++; // jeżeli jest poziomo to daj go w prawo 
                       }
                        break;
                    }
                }
            }
            

        }

        // sprawdź ile jest trafionych pól
        public int sprawdzPlansze()
        {
            int i, j, suma = 0;

            for (j = 0; j < 10; j++)
            {
                for (i = 0; i < 10; i++)
                {
                    if (plansza_strzalow[j, i].status == "trafiony")
                        suma++;
                }
            }

            return suma;
        }

        // konstruktor
        public Zestaw()
        {
            int j = 0, i = 0;
            for(j = 0; j < 10; j++)
            {
                for(i = 0; i < 10; i++)
                {
                    this.plansza_swoja[j, i] = new Pole("nic", false, j, i);
                    this.plansza_strzalow[j, i] = new Pole("nic", false, j, i);
                    this.plansza_swoja[j, i].setStatek(false); // jeszcze raz dla pewności
                    this.plansza_strzalow[j, i].setStatus("nic"); // jeszcze raz dla pewności

                }
            }

        }

    }
}
