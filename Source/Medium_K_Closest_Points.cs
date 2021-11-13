using System;

class Calculate
{
	public static double Distance(int x, int y)
	{
		return Math.Sqrt(Math.Pow(Math.Abs(x), 2) + Math.Pow(Math.Abs(y), 2));
	}
}

class Solution
{
	public static int[,] ClosestPoints(int[,] points, int k)
	{
		if(points.Length == 0) return points;
		int[,] closest = new int[k,2];

		int index = 0;

		for(int i = 0; i < points.GetLength(0); i++)
		{
			index = i;

			for(int j = i + 1; j < points.GetLength(0); j++)
			{
				if(Calculate.Distance(points[j,0], points[j,1]) < Calculate.Distance(points[index,0], points[index,0]))
				{
					index = j;
				}
			}

			int ax = points[i,0];
			int ay = points[i,1];
			int bx = points[index,0];
			int by = points[index,1];
			points[i,0] = bx;
			points[i,1] = by;
			points[index,0] = ax;
			points[index,1] = ay;
		}

		for(int i = 0; i < k; i++)
		{
			closest[i,0] = points[i,0];
			closest[i,1] = points[i,1];
		}

		return closest;
	}
}

class LeetCode
{
	static void Main()
	{
		int k = 4;
		int size = 10;
		int[,] points = new int[size,2];

		for(int i = 0; i < size; i++)
		{
			points[i,0] = size - i - 1;
			points[i,1] = size - i - 1;
		}

		int[,] closest = Solution.ClosestPoints(points, k);

		for(int i = 0; i < closest.GetLength(0); i++)
		{
			Console.WriteLine("[{0},{1}] : {2}", closest[i,0], closest[i,1], Calculate.Distance(closest[i,0], closest[i,1]));
		}
	}
}