public class Kata
{
    public static string AbbrevName(string name)
    {
        return string.Concat(name.Split(' ')[0].ToUpper()[0],".", name.Split(' ')[1].ToUpper()[0]);
    }
}