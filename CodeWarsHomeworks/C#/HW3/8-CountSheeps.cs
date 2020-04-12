using System.Linq;
using System;

public static class Kata
{
    public static int CountSheeps(bool[] sheeps)
    {
        return sheeps.Count(x=>x==true);
    }
}
