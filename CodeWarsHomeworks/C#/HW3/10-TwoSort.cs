using System;
using System.Collections.Generic;
public class Kata
{
    public static string TwoSort(string[] s)
    {
        List<string> a = new List<string>(s);
        a.Sort(StringComparer.Ordinal);
        return string.Join("***", a[0].ToCharArray());
    }
  
}
