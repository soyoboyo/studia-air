using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WM_project_timetable
{
    class SetPer
    {
        public int[] pi;
        public int[] ps;
        public int op, m, size;
        
        public void init(int _op, int _m)
        {
            op = _op;
            m = _m;
            size = op + m;
            pi = new int[size + 1];
            ps = new int[size + 1];
        }

        public void createPS()
        {
            for (int i = 1; i <= size; i++)
                ps[pi[i]] = i;
        }
    }
}
