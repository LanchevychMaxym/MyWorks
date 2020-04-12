public class Kata
{
    public static string TripleTrouble(string one, string two, string three)
    {
        string[] neew = new string[one.Length];
        for (int i = 0; i < one.Length; i++)
        {
            neew[i] = string.Concat(one[i],two[i],three[i]);
        }

        string res="";
        for (int i = 0; i < one.Length; i++)
        {
            res = string.Concat(res, neew[i]);
        }
        return res;
    }
}