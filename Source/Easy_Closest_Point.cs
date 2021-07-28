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
    public static Point Closest_Point(List<Point> points)
    {
        if(points.Count == 0) return new Point(0,0);
        Point closest_point = new Point(0,0);
        closest_point = points[0];

        for(int i = 0; i < points.Count; i++)
        {
            if(Calculate.Distance(points[i]) < Calculate.Distance(closest_point))
            {
                closest_point = points[i];
            }
        }

        return closest_point;
    }
}

class Program
{
    static void Main()
    {
        List<Point> points = new List<Point>();
        points.Add(new Point(8,8));
        points.Add(new Point(4,4));
        points.Add(new Point(2,2));
        points.Add(new Point(1,1));
        Point point = Algorithm.Closest_Point(points);
        Console.WriteLine("Closest Point: [{0},{1}]", point.x, point.y);
    }
}