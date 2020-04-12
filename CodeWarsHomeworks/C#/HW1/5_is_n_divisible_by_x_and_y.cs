using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class DivisibleNb
{
    public static bool isDivisible(long n, long x, long y)
    {
        return n % x == 0 && n % y == 0;
    }
}

