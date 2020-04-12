using System.Linq;

public class Kata
{
    public static bool BetterThanAverage(int[] ClassPoints, int YourPoints)
    {
        return YourPoints>(ClassPoints.Sum()+YourPoints)/(double)(ClassPoints.Length+1);
    }
}
