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

struct Point ClosestPoint(struct Point* points, unsigned int size)
{
	struct Point point = {0,0};
	if(size == 0) return point;
	point = points[0];

	for(unsigned int i = 0; i < size; i++)
	{
		if(Distance(points[i]) < Distance(point)) point = points[i];
	}

	return point;
}

struct Point points[] = {{2,3},{4,9},{10,10},{1,1}};
unsigned int size = sizeof(points) / sizeof(struct Point);

int main()
{
	struct Point point = ClosestPoint(points, size);
	printf("Closest Point: [%d,%d]\n", point.x, point.y);
}