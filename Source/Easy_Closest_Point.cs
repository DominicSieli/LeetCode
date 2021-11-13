using System;
using System.Collections.Generic;

class Point
{
	public int x = 0;
	public int y = 0;

	public Point(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
}

class Calculate
{
	public static double Distance(Point point)
	{
		return Math.Sqrt(Math.Pow(Math.Abs(point.x), 2) + Math.Pow(Math.Abs(point.y), 2));
	}
}

class Algorithm
{
	public static Point ClosestPoint(Point[] points)
	{
		if(points.Length == 0) return new Point(0,0);
		Point point = new Point(0,0);
		point = points[0];

		for(int i = 0; i < points.Length; i++)
		{
			if(Calculate.Distance(points[i]) < Calculate.Distance(point))
			{
				point = points[i];
			}
		}

		return point;
	}
}

class Program
{
	static void Main()
	{
		Point[] points = new Point[4];
		points[0] = new Point(8,8);
		points[1] = new Point(4,4);
		points[2] = new Point(2,2);
		points[3] = new Point(1,1);
		Point point = Algorithm.ClosestPoint(points);
		Console.WriteLine("Closest Point: [{0},{1}]", point.x, point.y);
	}
}