using System;

public class Solution
{
	public String Longest_Common_Prefix(String[] strs)
	{
		int i = strs[0].Length;

		for(int s = 0; s < strs.Length - 1; s++)
		{
			for(int c = 0; c < i; c++)
			{
				if(c >= strs[s].Length) {i = strs[s].Length; break;}
				if(c >= strs[s+1].Length) {i = strs[s+1].Length; break;}
				if(strs[s][c] != strs[s+1][c]) i = c;
			}
		}

		return strs[0].Substring(0, i);
	}
}

public class LeetCode
{
	public static void Main()
	{
		String[] strs1 = new string[] {"a"};
		String[] strs2 = new string[] {"",""};
		String[] strs3 = new string[] {"ab","a"};
		String[] strs4 = new string[] {"flower","flow","flight"};

		Solution solution = new Solution();
		Console.WriteLine(solution.Longest_Common_Prefix(strs1));
		Console.WriteLine(solution.Longest_Common_Prefix(strs2));
		Console.WriteLine(solution.Longest_Common_Prefix(strs3));
		Console.WriteLine(solution.Longest_Common_Prefix(strs4));
	}
}