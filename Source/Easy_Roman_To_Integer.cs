using System;
using System.Collections.Generic;

public class Solution
{
	public int RomanToInteger(string s)
	{
		int integer = 0;
		Dictionary<char, int> numerals = new Dictionary<char, int>();

		numerals.Add('I', 1);
		numerals.Add('V', 5);
		numerals.Add('X', 10);
		numerals.Add('L', 50);
		numerals.Add('C', 100);
		numerals.Add('D', 500);
		numerals.Add('M', 1000);

		for(int i = 0; i < s.Length; i++)
		{
			if(i + 1 >= s.Length)
			{
				integer += numerals[s[i]];
			}

			if(i + 1 < s.Length)
			{
				if(numerals[s[i]] >= numerals[s[i + 1]]) integer += numerals[s[i]];
				if(numerals[s[i]] < numerals[s[i + 1]]) {integer += numerals[s[i + 1]] - numerals[s[i]]; i++;}
			}
		}

		return integer;
	}
}

public class LeetCode
{
	public static void Main()
	{
		string s1 = "IV";
		string s2 = "IX";
		string s3 = "III";
		string s4 = "LVIII";
		string s5 = "MMCXVI";
		string s6 = "MCMXCIV";
		Solution solution = new Solution();

		Console.WriteLine(solution.RomanToInteger(s1));
		Console.WriteLine(solution.RomanToInteger(s2));
		Console.WriteLine(solution.RomanToInteger(s3));
		Console.WriteLine(solution.RomanToInteger(s4));
		Console.WriteLine(solution.RomanToInteger(s5));
		Console.WriteLine(solution.RomanToInteger(s6));
	}
}