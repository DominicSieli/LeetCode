using System;

public class Solution
{
	public bool IsIntergerPalindrome(int x)
	{
		int n = 0;
		if(x < 0) return false;
		if(x > 0) n = (int)Math.Log10(x);

		while(x != 0)
		{
			if(x % 10 != (int)(x / (int)Math.Pow(10, n))) return false;
			x = x % (int)Math.Pow(10, n);
			x = (int)(x / 10);
			n -= 2;
		}

		return true;
	}
}

public class LeetCode
{
	public static void Main()
	{
		Solution solution = new Solution();
		Console.WriteLine(solution.IsIntergerPalindrome(121));
	}
}