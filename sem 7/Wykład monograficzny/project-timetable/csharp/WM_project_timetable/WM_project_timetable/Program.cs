using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WM_project_timetable
{
    class Program
    {
        // wyznaczenie kolejnosci topologicznej
        static public int[] topOrder(CGraph G)
        {
            int[] LP = new int[G.n + 1];
            int[] ORD = new int[G.n + 1];

            for (int i = 1; i <= G.n; i++)
            {
                LP[i] = G.pred(i).Count;
            }



            Queue<int> Q = new Queue<int>();

            for (int i = 1; i <= G.n; i++)
            {
                if (LP[i] == 0)
                    Q.Enqueue(i);
            }

            int l = 0;
            while (Q.Count > 0)
            {
                int w = Q.Dequeue();
                ORD[++l] = w;
                foreach (int ns in G.succ(w))
                {
                    if (--LP[ns] == 0)
                        Q.Enqueue(ns);
                }
            }

            if (l < G.n)
                ORD[0] = -1;
            else
                ORD[0] = 0;

            return ORD;
        }

        // wyznaczenie harmonogramu
        // S - starting times, C - completition times, PH - critical path
        public static int timetable(CGraph G, int[] topOrder, int[] S, int[] C, int[] PH)
        {
            for (int i = 1; i <= G.n; i++)
            {
                PH[i] = 0;
            }

            for (int i = 1; i <= G.n; i++)
            {
                int w = topOrder[i], s = 0;
                foreach (int p in G.pred(w))
                {
                    if (s < C[p])
                    {
                        s = C[p];
                        PH[w] = p;
                    } }
                    S[w] = s;
                    C[w] = s + G.weights[w];
               
            }
            PH[0] = 1;
            for (int i = 1; i <= G.n; i++)
            {
                if (C[PH[0]] < C[i])
                    PH[0] = i;
            }

            return C[PH[0]];
        }

        //////////// ver 2 ////////////


        // added methods
        static public int[] topOrder2(CGraph G, SetPer pi)
        {
            int[] LP = new int[G.n + 1];
            int[] ORD = new int[G.n + 1];

            for (int i = 1; i <= G.n; i++)
            {
                LP[i] = G.pred(i).Count;
            }

            // added
            for (int i = 1; i <= pi.size; i++)
            {
                if (pi.pi[i - 1] != 0)
                    LP[pi.pi[i]]++;
            }
            // added
            Queue<int> Q = new Queue<int>();

            for (int i = 1; i <= G.n; i++)
            {
                if (LP[i] == 0)
                    Q.Enqueue(i);
            }

            int l = 0;
            while (Q.Count > 0)
            {
                int w = Q.Dequeue();
                ORD[++l] = w;
                foreach (int ns in G.succ(w))
                {
                    if (--LP[ns] == 0)
                        Q.Enqueue(ns);
                }
                // added
                int nsp = pi.pi[pi.ps[w] + 1];
                if (nsp != 0)
                {
                    if (--LP[nsp] == 0)
                        Q.Enqueue(nsp);
                }
                // added
            }

            if (l < G.n)
                ORD[0] = -1;
            else
                ORD[0] = 0;

            return ORD;
        }

        public static int timetable2(CGraph G, SetPer pi, int[] topOrder, int[] S, int[] C, int[] PH)
        {
            for (int i = 1; i <= G.n; i++)
            {
                PH[i] = 0;
            }

            for (int i = 1; i <= G.n; i++)
            {
                int w = topOrder[i], s = 0;
                foreach (int p in G.pred(w))
                {
                    if (s < C[p])
                    {
                        s = C[p];
                        PH[w] = p;
                    }
                }
                // added
                int pp = pi.pi[pi.ps[w] - 1];
                if(pp != 0)
                {
                    if(s < C[pp])
                    {
                        s = C[pp];
                        PH[w] = pp;
                    }
                }
                // added
                S[w] = s;
                C[w] = s + G.weights[w];

            }
            PH[0] = 1;
            for (int i = 1; i <= G.n; i++)
            {
                if (C[PH[0]] < C[i])
                    PH[0] = i;
            }

            return C[PH[0]];
        }

        static void Main(string[] args)
        {

        }

        // tworzenie grafu
        static public void createGraphTest(CGraph G)
        {
            int[] tm = { 0, 2, 1, 2, 2, 6, 2, 1, 3, 1, 3, 5, 2, 3, 4, 1, 1, 2, 3, 3 };
            int[] rs = { 0, 1, 1, 2, 3, 3, 4, 3, 5, 3, 6, 3, 6, 6, 3, 5, 2, 2, 2, 3 };

            G.Init(19);
            G.addArc(1, 2); G.addArc(1, 3); G.addArc(1, 4);
            G.addArc(2, 5);
            G.addArc(3, 5);
            G.addArc(4, 5);
            G.addArc(5, 6);
            G.addArc(6, 7); G.addArc(6, 10);
            G.addArc(7, 8); G.addArc(7, 9);
            G.addArc(8, 9);
            G.addArc(9, 14);
            G.addArc(10, 11); G.addArc(10, 12);
            G.addArc(12, 13); G.addArc(12, 15); G.addArc(12, 17);
            G.addArc(13, 14);
            G.addArc(15, 16);
            G.addArc(16, 19);
            G.addArc(17, 16); G.addArc(17, 18);
            G.addArc(18, 19);
            for (int i = 1; i <= G.n; i++)
                G.weights[i] = tm[i];
            for (int i = 1; i <= G.n; i++)
                G.reso[i] = rs[i];
        }

        // tworzenie zbioru premutacji
        static public void createPermuTest(SetPer pi)
        {
            int[] pis = { 0, 1, 2, 0, 3, 17, 16, 18, 0, 4, 5, 7, 9, 11, 14, 19, 0, 6, 12, 13, 0, 8, 15, 0, 10, 0 };
            int op = 19, m = 6;
            pi.init(op, m);
            for (int i = 1; i <= op + m; i++)
                pi.pi[i] = pis[i];
            pi.createPS();
        }

    }
}
