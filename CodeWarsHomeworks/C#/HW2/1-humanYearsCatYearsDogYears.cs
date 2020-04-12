
public class Dinglemouse
{

    public static int[] humanYearsCatYearsDogYears(int humanYears)
    {
        int d_years, c_years;
        if (humanYears <= 2)
        {
            c_years = d_years = (humanYears == 2) ? 24 : 15;
            return new int[] { humanYears, c_years, d_years };
        }

        d_years = 15 + 9 + 5 * (humanYears - 2);
        c_years = 15 + 9 + 4 * (humanYears - 2);

        return new int[] { humanYears, c_years, d_years };
    }
}
