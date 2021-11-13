#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

double Distance(vector<int> point)
{
	return sqrt(pow(abs(point[0]), 2) + pow(abs(point[1]), 2));
}

vector<vector<int>> ClosestPoints(vector<vector<int>>& points, int k)
{
	if(points.size() == 0) return points;

	int index = 0;

	for(unsigned int i = 0; i < points.size(); i++)
	{
		index = i;

		for(unsigned int j = i + 1; j < points.size(); j++)
		{
			if(Distance(points[j]) < Distance(points[index]))
			{
				index = j;
			}
		}

		swap(points[i], points[index]);
	}

	vector<vector<int>> closest = points;
	closest.resize(k);
	return closest;
}

int main()
{
	int k = 4;
	int size = 10;
	vector<vector<int>> points(size, vector<int>(2,0));
	for(unsigned int i = 0; i < points.size(); i++) {points[i][0] = size - i - 1; points[i][1] = size - i - 1;}
	vector<vector<int>> closest = ClosestPoints(points, k);

	for(unsigned int i = 0; i < closest.size(); i++)
	{
		cout << "[" << i << "]" << " " << "[" << closest[i][0] << "," << closest[i][1] << "] : " << Distance(closest[i]) << '\n';
	}
}