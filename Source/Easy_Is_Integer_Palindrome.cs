using System;

public class Solution
{
	public bool Is_Interger_Palindrome(int x)
	{
		if(x < 0) return false;

		int rev = 0;
		int rev_x = x;

		while(rev_x != 0)
		{
			int pop = rev_x % 10;
			rev_x /= 10;

			if(rev > Int32.MaxValue / 10 || (rev == Int32.MaxValue / 10 && pop > 7)) return false;
			if(rev < Int32.MinValue / 10 || (rev == Int32.MinValue / 10 && pop < -8)) return false;
			rev = rev * 10 + pop;
		}

		rev_x = x;

		while(rev_x != 0)
		{
			int x_pop = rev_x % 10;
			int rev_pop = rev % 10;
			rev /= 10;
			rev_x /= 10;

			if(x_pop != rev_pop)
			{
				return false;
			}
		}

		return true;
	}
}

public class LeetCode
{
	public static void Main()
	{
		Solution solution = new Solution();
		Console.WriteLine(solution.Is_Interger_Palindrome(121));
	}
}