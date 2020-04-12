using System;

namespace Extensions
{
    public static class StringExt
    {
        public static string ToAlternatingCase(this string s)
        {
            char[] arr = s.ToCharArray();
            for (int i = 0; i < s.Length; i++)
            {
                if (!char.IsLetter(s[i]))
                    continue;
                if (char.IsUpper(s[i]))
                    arr[i]=char.ToLower(s[i]);
                else
                    arr[i]=char.ToUpper(s[i]);
            }
            return new string(arr);
        }
    }
}