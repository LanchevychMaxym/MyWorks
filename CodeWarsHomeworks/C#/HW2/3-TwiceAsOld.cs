namespace Solution
{
    public class TwiceAsOldSolution
    {
        public static int TwiceAsOld(int dadYears, int sonYears)
        {
            return System.Math.Abs(dadYears - (sonYears * 2));
        }
    }
}