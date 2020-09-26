using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PAMSI_9_Statki
{
    public class Statek
    {
        public Pole dziob;
        public Pole rufa;
        public int dlugosc;
        public bool zatopiony = false;

        public void setDziob(int X, int Y)
        {
          
        }
        
        public void setRufa(int X, int Y)
        {
            rufa.x = X;
            rufa.y = Y;
        }

        public void wypelnij()
        {
           // Pole tmp = new Pole("nic", true); // dodaj w tym polu statek
            int i = 0, j = 0, index = 1;
            
            if (dziob.x == rufa.x) // statek jest pionowo
            {
                if(dziob.y > rufa.y) // od prawej do lewej
                {
                    i = dziob.y;
                    j = rufa.y;
                }
                else // od lewej do prawej
                {
                    i = rufa.y;
                    j = dziob.y;
                }
                for(int k = 0; k < dlugosc; k++)
                {
                    if(dziob.y < rufa.y)
                    {

                    }
                }
            }
            else // statek jest poziomo
            {

            }
        }

        public void set_dlugosc(int dl)
        {
            dlugosc = dl;
        }
        public Statek(int dl) { dlugosc = dl; }
        public List<Pole> pozycje = new List<Pole>();


    }
}
