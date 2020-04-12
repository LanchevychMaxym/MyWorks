using System;

public static class Kata
{
    public static int summation(int num)
    {
        int count = 0;
        for (int i = 0; i <= num; i++)
        {
            count += i;
        }
        return count;
    }
}