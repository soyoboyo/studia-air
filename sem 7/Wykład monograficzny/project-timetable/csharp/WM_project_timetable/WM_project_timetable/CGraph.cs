using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WM_project_timetable
{
    class CGraph
    {
        public int n = 0; // number of nodes
        List<int>[] succs; // list of successors
        List<int>[] preds; // list of predecessors
        public int[] weights; // weights of nodes
        public int[] reso; // assign to resource

        // create empty lists for graph with n nodes 
        public void Init(int pn)
        {
            n = pn;
            reso = new int[n + 1];
            weights = new int[n + 1];
            succs = new List<int>[n + 1];
            preds = new List<int>[n + 1];
            for (int i = 0; i < n; i++)
            {
                succs[i] = new List<int>();
                preds[i] = new List<int>();
            }
        }

        // add arc linked node f with node t
        public void addArc(int f, int t)
        {
            succs[f].Add(t);
            preds[t].Add(f);
        } 

        public List<int> succ(int node)
        {
            return succs[node];
        }
        public List<int> pred(int node)
        {
            return preds[node];
        }

        

    }
    
}
