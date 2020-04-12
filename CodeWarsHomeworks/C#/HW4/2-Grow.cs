public class Kata
{
    public static int Grow(int[] x)
    {
        int res=1;
        for (int i = 0; i < x.Length; i++)
            res *= x[i];
        
        return res;
    }
}