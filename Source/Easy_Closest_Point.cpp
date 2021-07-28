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

Point Closest_Point(std::vector<Point>& points)
{
    Point closest_point = {0,0};
    if(points.size() == 0) return closest_point;
    closest_point = points[0];

    for(unsigned int i = 0; i < points.size(); i++)
    {
        if(Distance(points[i]) < Distance(closest_point)) closest_point = points[i];
    }

    return closest_point;
}

std::vector<Point> points = {{2,3},{4,9},{10,10},{1,1}};

int main()
{
    Point point = Closest_Point(points);
    std::cout << "Closest Point: [" << point.x << "," << point.y << "]" << '\n';
}