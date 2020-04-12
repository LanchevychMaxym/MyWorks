using System.Linq;
public class Kata
{
    public static int PositiveSum(int[] arr)
    {

        return arr.Length == 0 ? 0 : arr.Aggregate((a, b) => (a > 0 && b > 0) ? a + b : (a > 0) ? a : (b > 0) ? b : 0);
    }
}
