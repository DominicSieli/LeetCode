#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double Distance(int* point)
{
	return sqrt(pow(fabs((double)point[0]), 2) + pow(fabs((double)point[1]), 2));
}

int** ClosestPoints(int** points, int size, int k)
{
	if(size == 0) return points;
	int** closest = (int**)malloc(k * sizeof(int*));
	for(int i = 0; i < k; i++) closest[i] = (int*)malloc(2 * sizeof(int));

	int index = 0;

	for(int i = 0; i < size; i++)
	{
		index = i;

		for(int j = i + 1; j < size; j++)
		{
			if(Distance(points[j]) < Distance(points[index]))
			{
				index = j;
			}
		}

		int* p1 = points[i];
		int* p2 = points[index];
		points[i] = p2;
		points[index] = p1;
	}

	for(int i = 0; i < k; i++)
	{
		closest[i][0] = points[i][0];
		closest[i][1] = points[i][1];
	}

	return closest;
}

int main()
{
	int size = 10;
	int** points = (int**)malloc(size * sizeof(int*));
	for(int i = 0; i < size; i++) points[i] = (int*)malloc(2 * sizeof(int));

	for(int i = 0; i < size; i++)
	{
		points[i][0] = size - i - 1;
		points[i][1] = size - i - 1;
	}

	int k = 4;
	int** closest = ClosestPoints(points, size, k);

	for(int i = 0; i < k; i++)
	{
		printf("[%d] [%d,%d] : %lf\n", i, closest[i][0], closest[i][1], Distance(closest[i]));
	}
}