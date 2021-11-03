using System;

public class Solution
{
	public bool IsPalindrome(string s)
	{
		int l = 0;
		int r = s.Length - 1;

		while(l < r)
		{
			while(l < r && !Char.IsLetterOrDigit(s[l])) l++;
			while(l < r && !Char.IsLetterOrDigit(s[r])) r--;
			if(Char.ToLower(s[l]) != Char.ToLower(s[r])) return false;
			if(l < r) l++;
			if(l < r) r--;
		}

		return true;
	}
}

public class LeetCode
{
	public static void Main()
	{
		string s = "a #a c -bbc, a:  a ";
		Solution solution = new Solution();
		Console.WriteLine(solution.IsPalindrome(s));
	}
}