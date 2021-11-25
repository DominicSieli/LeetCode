#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

double Distance(vector<int> point)
{
	return point[0] * point[0] + point[1] * point[1];
}

vector<vector<int>> ClosestPoints(vector<vector<int>>& points, int k)
{
	sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b)
	{
		return Distance(a) < Distance(b);
	});

	return vector<vector<int>>(points.begin(), points.begin() + k);
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