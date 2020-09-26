using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PAMSI_9_Statki
{
    public class Pole
    {
        public int x;
        public int y;
        public string krawedz;
     
        public bool statek = false;
        public string status = "nic"; // czy strzal, czy pudlo, czy trafiony, czy zatopiony

        public void setStatus(string s) { status = s; } // ustaw w tym polu status

        public void setStatek(bool s) { statek = s; } // ustaw w tym polu statek


        public void setkrawedz()
        {
            if (x == 0)
            {
                if (y == 0)
                    krawedz = "TopLeft";
                else if (y == 9)
                    krawedz = "BotLeft";
                else krawedz = "Left";
            }
            else if (x == 9)
            {
                if (y == 0)
                    krawedz = "TopRight";
                else if (y == 9)
                    krawedz = "BotRight";
                else krawedz = "Right";
            } else
            {
                if (y == 0)
                    krawedz = "Top";
                else if (y == 9)
                    krawedz = "Bot";
                else krawedz = "C";
            }
        }

        // konstruktor
        public Pole(string s, bool czyStatek, int pozX, int pozY)
        {
            x = pozX;
            y = pozY;
            setkrawedz();
        }
      


    }
}
