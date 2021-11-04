using System;

public class Solution
{
	public int ReverseInteger(int x)
	{
		int xlast = 0;
		int reverse = 0;

		while(x != 0)
		{
			xlast = x % 10;
			x /= 10;

			if(reverse > Int32.MaxValue / 10 || (reverse == Int32.MaxValue / 10 && xlast > 7)) return 0;
			if(reverse < Int32.MinValue / 10 || (reverse == Int32.MinValue / 10 && xlast < -8)) return 0;
			reverse = reverse * 10 + xlast;
		}

		return reverse;
	}
}

public class LeetCode
{
	public static void Main()
	{
		Solution solution = new Solution();

		Console.WriteLine(solution.ReverseInteger(123));
		Console.WriteLine(solution.ReverseInteger(-123));
	}
}