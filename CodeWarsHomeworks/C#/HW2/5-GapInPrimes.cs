using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

 public class Eratosphen
{
   public static long[] GetPrimaryMas(long m,long n)
    {
        bool[] mas=new bool[n+1];
        for (int i = 0; i <=n; i++)
        {
            mas[i] = true;
        }
        for ( long i = 2; i * i < n+1; i++)
        {
            if (mas[i] == true)
            {
                long j = i * i;
                while (j < n)
                {
                    mas[j] = false;
                    j += i;
                }
            }
        }
         List<long> prim_mas= new List<long>(Convert.ToInt32(n-m));
        for (long i = m; i <=n; i++)
        {
            if (mas[i] == true)
                prim_mas.Add(i);
        }
        return prim_mas.ToArray<long>();
    }
}
class GapInPrimes
{
    public static long[] Gap(int g, long m, long n)
    {
        long[] primes=Eratosphen.GetPrimaryMas(m,n);
        for (int i = 1; i < primes.Length-1; i++)
        {
            if (primes[i]-primes[i-1]==g)
            {
                return new long[] {primes[i-1],primes[i] };
            }
        }
        return null;
    }
}