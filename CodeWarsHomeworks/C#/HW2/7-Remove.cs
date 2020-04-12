public class Kata
{
    public static string Remove(string s, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (!s.Contains("!"))
                break;
            s = s.Remove(s.IndexOf("!"), 1);
        }
        return s;
    }
}