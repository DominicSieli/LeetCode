using System;

public class Solution
{
	public String LongestCommonPrefix(String[] strings)
	{
		int i = strings[0].Length;

		for(int s = 0; s < strings.Length - 1; s++)
		{
			for(int c = 0; c < i; c++)
			{
				if(c >= strings[s].Length) {i = strings[s].Length; break;}
				if(c >= strings[s+1].Length) {i = strings[s+1].Length; break;}
				if(strings[s][c] != strings[s+1][c]) i = c;
			}
		}

		return strings[0].Substring(0, i);
	}
}

public class LeetCode
{
	public static void Main()
	{
		String[] string1 = new string[] {"a"};
		String[] string2 = new string[] {"",""};
		String[] string3 = new string[] {"ab","a"};
		String[] string4 = new string[] {"flower","flow","flight"};

		Solution solution = new Solution();
		Console.WriteLine(solution.LongestCommonPrefix(string1));
		Console.WriteLine(solution.LongestCommonPrefix(string2));
		Console.WriteLine(solution.LongestCommonPrefix(string3));
		Console.WriteLine(solution.LongestCommonPrefix(string4));
	}
}