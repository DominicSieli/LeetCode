using System;
using System.Collections.Generic;

public class Solution
{
	public int[] TwoSum(int[] nums, int target)
	{
		Dictionary<int, int> cache = new Dictionary<int, int>();

		for(int i = 0; i < nums.Length; i++)
		{
			int complement = target - nums[i];

			if(cache.ContainsKey(complement))
			{
				return new int[] {cache[complement], i};
			}

			cache.Add(nums[i], i);
		}

		return new int[] {0, 0};
	}
}

public class LeetCode
{
	public static void Main()
	{
		Solution solution = new Solution();

		int target = 9;
		int[] nums = new int[] {1,2,3,4,5,6,7,8,9};
		int[] results = solution.TwoSum(nums, target);

		Console.WriteLine("["+results[0]+"]" + "["+results[1]+"]");
	}
}