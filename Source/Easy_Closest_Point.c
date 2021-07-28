#include <math.h>
#include <stdio.h>

struct Point
{
    int x;
    int y;
};

double Distance(struct Point point)
{
    return sqrt(pow(fabs(point.x), 2) + pow(fabs(point.y), 2));
}

struct Point Closest_Point(struct Point* points, unsigned int size)
{
    struct Point closest_point = {0,0};
    if(size == 0) return closest_point;
    closest_point = points[0];

    for(unsigned int i = 0; i < size; i++)
    {
        if(Distance(points[i]) < Distance(closest_point)) closest_point = points[i];
    }

    return closest_point;
}

struct Point points[] = {{2,3},{4,9},{10,10},{1,1}};
unsigned int size = sizeof(points) / sizeof(struct Point);

int main()
{
    struct Point point = Closest_Point(points, size);
    printf("Closest Point: [%d,%d]\n", point.x, point.y);
}