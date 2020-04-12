using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


public class Kata
{
    public static string FakeBin(string x)
    {
        for (int i = 0; i <= 9; i++)
        {
            if (i<5)
            {
                x=x.Replace(Convert.ToString(i), "0");
            }
            else
            {
                x=x.Replace(Convert.ToString(i), "1");
            }
    
        }
        return x;
    }
}

