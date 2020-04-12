using System;
class Kata
{
    public static int StrCount(string str, string letter)
    {
        return str.Contains(letter) ? str.Split(Convert.ToChar(letter)).Length -1 : 0;
    }
}
