using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;







/*
  wybierz statek
  pionowo lub poziomo
  sprawdź czy ścieżka dla statku jest pusta

 */
namespace PAMSI_9_Statki
{
    public partial class UI : Form
    {
        public Color[,] kolory_lewa = new Color[10, 10] {
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
        };
        public Color[,] kolory_prawa = new Color[10, 10] {
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
    { Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White, Color.White },
        };

        public int x = 0;
        public int y = 0;
        public int i = 0;
        public int sumaCzlowiek = 0;
        public int sumaAI = 0;
        public bool pionowo = false;
        public bool trafAI = false;
        public bool trafCzlowiek = false;
        //object syncLock = new object(); // nie wiem po co to
        
        public UI() {
            InitializeComponent();
            tableLayoutPanel1.Enabled = false; // blokuj planszę strzałów
            tableLayoutPanel2.Enabled = false; // blokuj planszę dodawania statków
        }

        Zestaw z_gracza = new Zestaw(); // zestaw dla gracza
        Zestaw z_AI = new Zestaw(); // zestaw dla AI

        public bool gra_zaczeta = false; // etap dodawania statków, gra nie jest jeszcze zaczęta
        public string dodawanie = "nic"; // żaden statek nie jest obecnie dodawany
        public string kr = "";
        // pokaż statki
        public void pokaStatki()
        {
            for (int j = 0; j < 10; j++)
            {
                for (int i = 0; i < 10; i++)
                {
                    if (z_AI.plansza_swoja[i, j].statek == true && z_gracza.plansza_strzalow[i, j].status == "nic")
                        kolory_lewa[i, j] = Color.Pink;
                }
            }
            tableLayoutPanel1.Refresh();
        }

        // nie strzelaj w otoczone pola
        public void AI_element1()
        {
            // switch jako element AI
            // wyklukczający w strzelanie otoczone pudłami pole
            // z_AI.plansza_strzalow[x, y].setkrawedz();
            kr = z_AI.plansza_strzalow[x, y].krawedz;
            if(z_AI.plansza_strzalow[x, y].status == "nic") {
                switch (kr)
                {
                    case "TopLeft":
                        if (z_AI.plansza_strzalow[x + 1, y].status == "pudlo" && // jeden w prawo
                            z_AI.plansza_strzalow[x, y + 1].status == "pudlo") // jeden w dol
                        {
                            z_AI.plansza_strzalow[x, y].setStatus("pudlo");
                            kolory_prawa[x, y] = Color.Yellow;
                        }
                        break;
                    case "BotLeft":
                        if (z_AI.plansza_strzalow[x + 1, y].status == "pudlo" && // jeden w prawo
                            z_AI.plansza_strzalow[x, y - 1].status == "pudlo") // jeden w górę
                        {
                            z_AI.plansza_strzalow[x, y].setStatus("pudlo");
                            kolory_prawa[x, y] = Color.Yellow;
                        }
                        break;
                    case "Left":
                        if (z_AI.plansza_strzalow[x, y + 1].status == "pudlo" && // jeden w dół
                            z_AI.plansza_strzalow[x, y - 1].status == "pudlo" && // jeden w gore
                            z_AI.plansza_strzalow[x + 1, y].status == "pudlo") // jeden w prawo
                        {
                            z_AI.plansza_strzalow[x, y].setStatus("pudlo");
                            kolory_prawa[x, y] = Color.Yellow;
                        }
                        break;
                    case "TopRight":
                        if (z_AI.plansza_strzalow[x, y + 1].status == "pudlo" && // jeden w dół
                            z_AI.plansza_strzalow[x - 1, y].status == "pudlo")// jeden w lewo

                        {
                            z_AI.plansza_strzalow[x, y].setStatus("pudlo");
                            kolory_prawa[x, y] = Color.Yellow;
                        }
                        break;
                    case "BotRight":
                        if (z_AI.plansza_strzalow[x, y - 1].status == "pudlo" && // jeden w górę
                            z_AI.plansza_strzalow[x - 1, y].status == "pudlo")// jeden w lewo

                        {
                            z_AI.plansza_strzalow[x, y].setStatus("pudlo");
                            kolory_prawa[x, y] = Color.Yellow;
                        }
                        break;
                    case "Right":
                        if (z_AI.plansza_strzalow[x, y + 1].status == "pudlo" && // jeden w dół
                            z_AI.plansza_strzalow[x - 1, y].status == "pudlo" && // jeden w lewo
                            z_AI.plansza_strzalow[x, y - 1].status == "pudlo") // jeden w górę

                        {
                            z_AI.plansza_strzalow[x, y].setStatus("pudlo");
                            kolory_prawa[x, y] = Color.Yellow;
                        }
                        break;
                    case "Top":
                        if (z_AI.plansza_strzalow[x, y + 1].status == "pudlo" && // jeden w dół
                           z_AI.plansza_strzalow[x - 1, y].status == "pudlo" && // jeden w lewo
                           z_AI.plansza_strzalow[x + 1, y].status == "pudlo") // jeden w prawo

                        {
                            z_AI.plansza_strzalow[x, y].setStatus("pudlo");
                            kolory_prawa[x, y] = Color.Yellow;
                        }
                        break;
                    case "Bot":
                        if (z_AI.plansza_strzalow[x + 1, y].status == "pudlo" && // jeden w prawo
                           z_AI.plansza_strzalow[x - 1, y].status == "pudlo" && // jeden w lewo
                           z_AI.plansza_strzalow[x, y - 1].status == "pudlo") // jeden w górę

                        {
                            z_AI.plansza_strzalow[x, y].setStatus("pudlo");
                            kolory_prawa[x, y] = Color.Yellow;
                        }
                        break;
                    case "C":
                        if (z_AI.plansza_strzalow[x, y - 1].status == "pudlo" && // jeden w górę
                           z_AI.plansza_strzalow[x - 1, y].status == "pudlo" && // jeden w lewo
                           z_AI.plansza_strzalow[x + 1, y].status == "pudlo" && // jeden w prawo
                           z_AI.plansza_strzalow[x, y + 1].status == "pudlo") // jeden w dół

                        {
                            z_AI.plansza_strzalow[x, y].setStatus("pudlo");
                            kolory_prawa[x, y] = Color.Yellow;
                        }
                        break;
                }
            }
        }


        // lokalizacja kursora
        Point? GetRowColIndex(TableLayoutPanel tlp, Point point)
        {
            if (point.X > tlp.Width || point.Y > tlp.Height)
                return null;

            int w = tlp.Width;
            int h = tlp.Height;
            int[] widths = tlp.GetColumnWidths();

            int i;
            for (i = widths.Length - 1; i >= 0 && point.X < w; i--)
                w -= widths[i];
            int col = i + 1;

            int[] heights = tlp.GetRowHeights();
            for (i = heights.Length - 1; i >= 0 && point.Y < h; i--)
                h -= heights[i];

            int row = i + 1;

            return new Point(col, row);
        }

        // plansza lewa
        private void tableLayoutPanel1_Click(object sender, EventArgs e)
        {
            var cellPos = GetRowColIndex(tableLayoutPanel1, tableLayoutPanel1.PointToClient(Cursor.Position));
            
            x = cellPos.Value.X;
            y = cellPos.Value.Y;

            
           
            // strzał gracza
            if(z_AI.plansza_swoja[x,y].statek == true) // jeżeli trafiono w statek
            {
                z_gracza.plansza_strzalow[x, y].setStatus("trafiony");
                kolory_lewa[x, y] = Color.Red;
                tableLayoutPanel1.Refresh();
                trafCzlowiek = true;
                if (z_gracza.sprawdzPlansze() == 16)
                {
                    MessageBox.Show("Wygrales!");
                    tableLayoutPanel1.Enabled = false;
                    return;
                }
            } else if(z_AI.plansza_swoja[x,y].statek == false) // jeżeli pudło
            {
                z_gracza.plansza_strzalow[x, y].setStatus("pudlo");
                kolory_lewa[x, y] = Color.Navy;
                tableLayoutPanel1.Refresh();
                trafCzlowiek = false;
            }
            sumaCzlowiek++;

            // strzał AI
            do {
                if (trafCzlowiek == false) // jezeli czlowiek nie trafil to moze strzelać
                {
                    while (true)
                    {
                        Random los = new Random(DateTime.Now.Millisecond);
                        x = los.Next(0, 10);
                        y = los.Next(0, 10);

                        AI_element1(); // sprawdz czy pole nie jest otoczone, bo nie ma statków wielkości 1 pola

                        // jeżeli znajdzie nieruszone pole
                        // to że gdzieś jest pudło, nie znaczy że tam strzelił
                        if (z_AI.plansza_strzalow[x, y].status == "nic" && // jeżli znalzał puste
                            z_AI.plansza_strzalow[x, y].status != "pudlo" && // i nie ma tam pudla
                            z_AI.plansza_strzalow[x, y].status != "trafiony" && // i nie trafione
                            z_AI.plansza_strzalow[x, y].status != "zatopiony") // i nie pudło
                        {
                            sumaAI++;
                            if (z_gracza.plansza_swoja[x, y].statek == true)
                            { // jeżeli trafił
                                kolory_prawa[x, y] = Color.Red;
                                z_AI.plansza_strzalow[x, y].setStatus("trafiony");
                                trafAI = true;
                                break;
                            }
                            else if (z_gracza.plansza_swoja[x, y].statek == false)
                            { // jeżeli pudło
                                kolory_prawa[x, y] = Color.Navy;
                                z_AI.plansza_strzalow[x, y].setStatus("pudlo");
                                trafAI = false;
                                break;
                            }
                            
                        }
                    }
                    tableLayoutPanel2.Refresh();
                    if (z_AI.sprawdzPlansze() == 16)
                    {
                        MessageBox.Show("Przegrales!");
                        tableLayoutPanel1.Enabled = false;
                        return;
                    }
                }
            } while (trafAI); // jezeli trafil to może jeszce raz

            label3.Text = sumaCzlowiek.ToString();
            label4.Text = sumaAI.ToString();


        }
        private void tableLayoutPanel1_CellPaint(object sender, TableLayoutCellPaintEventArgs e)
        {
            using (var b = new SolidBrush(kolory_lewa[e.Column, e.Row]))
            {
                e.Graphics.FillRectangle(b, e.CellBounds);
            }
        }

        // plansza prawa
        private void tableLayoutPanel2_Click(object sender, EventArgs e)
        {
            
            var cellPos = GetRowColIndex(tableLayoutPanel2, tableLayoutPanel2.PointToClient(Cursor.Position));

            cellPos = GetRowColIndex(tableLayoutPanel2, tableLayoutPanel2.PointToClient(Cursor.Position));
            x = cellPos.Value.X;
            y = cellPos.Value.Y;
            if (dodawanie != "nic")
            {
                kolory_prawa[x, y] = Color.LimeGreen;
               // z_gracza.plansza_swoja[x, y].setStatek(true);
                tableLayoutPanel2.Refresh();
            }

            

           

            if (gra_zaczeta == false)
            {
              if (!z_gracza.sprawdzSciezke(x, y, pionowo, dodawanie))
              {
                    MessageBox.Show("Statki kolidują!");
              }
              
                    z_gracza.dodajStatek(x, y, pionowo, dodawanie, kolory_prawa);
                    tableLayoutPanel2.Refresh();

                switch (dodawanie)
                {
                    case "p":
                    label10.BackColor = Color.LimeGreen;
                    tableLayoutPanel2.Enabled = false;
                    dodawanie = "nic";
                    break;
                    case "f1":
                    label11.BackColor = Color.LimeGreen;
                    tableLayoutPanel2.Enabled = false;
                        dodawanie = "nic";
                        break;
                    case "f2":
                    label12.BackColor = Color.LimeGreen;
                    tableLayoutPanel2.Enabled = false;
                        dodawanie = "nic";
                        break;
                    case "k1":
                    label13.BackColor = Color.LimeGreen;
                    tableLayoutPanel2.Enabled = false;
                        dodawanie = "nic";
                        break;
                    case "k2":
                    label14.BackColor = Color.LimeGreen;
                    tableLayoutPanel2.Enabled = false;
                        dodawanie = "nic";
                        break;
                    case "k3":
                    label15.BackColor = Color.LimeGreen;
                    tableLayoutPanel2.Enabled = false;
                        dodawanie = "nic";
                        break;
                  
                }
            }
        }
        private void tableLayoutPanel2_CellPaint(object sender, TableLayoutCellPaintEventArgs e)
        {
            using (var b = new SolidBrush(kolory_prawa[e.Column, e.Row]))
            {
                e.Graphics.FillRectangle(b, e.CellBounds);
            }
        }


        // dodaj pancernik
        private void label10_Click(object sender, EventArgs e)
        {
            dodawanie = "p";
            label10.BackColor = Color.Pink;
            tableLayoutPanel2.Enabled = true;
        }
        // dodaj fregatę 1
        private void label11_Click(object sender, EventArgs e)
        {
            dodawanie = "f1";
            label11.BackColor = Color.Pink;
            tableLayoutPanel2.Enabled = true;
        }
        // dodaj fregatę 2
        private void label12_Click(object sender, EventArgs e)
        {
            dodawanie = "f2";
            label12.BackColor = Color.Pink;
            tableLayoutPanel2.Enabled = true;
        }
        // dodaj kogę 1
        private void label13_Click(object sender, EventArgs e)
        {
            dodawanie = "k1";
            label13.BackColor = Color.Pink;
            tableLayoutPanel2.Enabled = true;
        }
        // dodaj kogę 2
        private void label14_Click(object sender, EventArgs e)
        {
            dodawanie = "k2";
            label14.BackColor = Color.Pink;
            tableLayoutPanel2.Enabled = true;
        }
        // dodaj kogę 3
        private void label15_Click(object sender, EventArgs e)
        {
            dodawanie = "k3";
            label15.BackColor = Color.Pink;
            tableLayoutPanel2.Enabled = true;
        }

       

        // MENU OPCJI

        /*****************************************************************************/
        // pokaż legendę
        private void pomocToolStripMenuItem_Click(object sender, EventArgs e) {
            panel1.BringToFront();
            panel1.Visible = true;
        }
        // schowaj legendę
        private void button1_Click(object sender, EventArgs e) {
            panel1.Visible = false;
        }
        // zrestartuj stan gry
        private void restartToolStripMenuItem_Click(object sender, EventArgs e) {
            for (int j = 0; j < 10; j++)
            {
                for (int i = 0; i < 10; i++)
                {
                    kolory_lewa[j, i] = Color.White;
                    kolory_prawa[j, i] = Color.White;
                }
            }
            tableLayoutPanel1.Refresh();
            tableLayoutPanel2.Refresh();
            gra_zaczeta = false;
            tableLayoutPanel1.Enabled = false;
            tableLayoutPanel2.Enabled = true;
            label10.BackColor = Color.Aquamarine;
            label11.BackColor = Color.Aquamarine;
            label12.BackColor = Color.Aquamarine;
            label13.BackColor = Color.Aquamarine;
            label14.BackColor = Color.Aquamarine;
            label15.BackColor = Color.Aquamarine;
        }
        // start
        private void startToolStripMenuItem_Click(object sender, EventArgs e) {
           
            // dodaj 16 losowych pól - wczesna faza implementacji
            /*
            for (int i = 0; i < 16; i++) {
                while(true) {
                    Random los = new Random(DateTime.Now.Millisecond);
                    x = los.Next(0, 10);
                    y = los.Next(0, 10);
                    if(z_AI.plansza_swoja[x, y].statek == false){
                        z_AI.plansza_swoja[x, y].setStatek(true);
                        break;
                    } } }
            */
            z_AI.dodAIStatek();

            tableLayoutPanel1.Refresh();

            gra_zaczeta = true;
            tableLayoutPanel1.Enabled = true;
            tableLayoutPanel2.Enabled = false;
        }
        // radiobutton PIONOWO
        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            pionowo = true;
        }
        
        // radiobutton POZIOMO
        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            pionowo = false;
        }
        // zaznacz nietrafione jeszcze statki na różowo
        private void pokażStatkiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            pokaStatki();
        }
    }
}
// dodawanie statka pole po polu
/*
            switch (dodawanie)
            {
                case "p":
                        i++;
                        if(i == z_gracza.pancernik.dlugosc) {
                            i = 0;
                            label10.BackColor = Color.LimeGreen;
                            tableLayoutPanel2.Enabled = false;
                            dodawanie = null;
                        }
                    
                    break;
                case "f1":
                        i++;
                        if (i == z_gracza.fregata1.dlugosc) {
                            i = 0;
                            label11.BackColor = Color.LimeGreen;
                            tableLayoutPanel2.Enabled = false;
                            dodawanie = null;
                        }
                        break;
                case "f2":
                        i++;
                        if (i == z_gracza.fregata2.dlugosc) {
                            i = 0;
                            label12.BackColor = Color.LimeGreen;
                            tableLayoutPanel2.Enabled = false;
                            dodawanie = null;
                        }
                        break;
                case "k1":
                        i++;
                        if (i == z_gracza.koga1.dlugosc) {
                            i = 0;
                            label13.BackColor = Color.LimeGreen;
                            tableLayoutPanel2.Enabled = false;
                            dodawanie = null;
                        }
                        break;
                case "k2":
                        i++;
                        if (i == z_gracza.koga2.dlugosc) {
                            i = 0;
                            label14.BackColor = Color.LimeGreen;
                            tableLayoutPanel2.Enabled = false;
                            dodawanie = null;
                        }
                        break;
                case "k3":
                        i++;
                        if (i == z_gracza.koga3.dlugosc) {
                            i = 0;
                            label15.BackColor = Color.LimeGreen;
                            tableLayoutPanel2.Enabled = false;
                            dodawanie = null;
                        }
                        break;
            }
            */
