#include <cmath>
#include <vector>
#include <iostream>

struct Point
{
	int x = 0;
	int y = 0;
};

double Distance(Point& point)
{
	return sqrt(pow(abs(point.x), 2) + pow(abs(point.y), 2));
}

Point ClosestPoint(std::vector<Point>& points)
{
	Point point = {0,0};
	if(points.size() == 0) return point;
	point = points[0];

	for(unsigned int i = 0; i < points.size(); i++)
	{
		if(Distance(points[i]) < Distance(point)) point = points[i];
	}

	return point;
}

std::vector<Point> points = {{2,3},{4,9},{10,10},{1,1}};

int main()
{
	Point point = ClosestPoint(points);
	std::cout << "Closest Point: [" << point.x << "," << point.y << "]" << '\n';
}