using System;

public static class Kata
{
    public static int Enough(int cap, int on, int wait)
    {
        return on + wait - cap < 0 ? 0 : on + wait - cap;
    }
}
