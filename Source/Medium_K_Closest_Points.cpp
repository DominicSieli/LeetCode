#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

double Distance(vector<int> point)
{
    return sqrt(pow(abs(point[0]), 2) + pow(abs(point[1]), 2));
}

vector<vector<int>> K_Closest_Points(vector<vector<int>>& points, int k)
{
    if(points.size() == 0) return points;

    int min_index = 0;

    for(unsigned int i = 0; i < points.size(); i++)
    {
        min_index = i;

        for(unsigned int j = i + 1; j < points.size(); j++)
        {
            if(Distance(points[j]) < Distance(points[min_index]))
            {
                min_index = j;
            }
        }

        swap(points[i], points[min_index]);
    }

    vector<vector<int>> closest_points = points;
    closest_points.resize(k);
    return closest_points;
}

int main()
{
    int k = 4;
    int size = 10;
    vector<vector<int>> points(size, vector<int>(2,0));
    for(unsigned int i = 0; i < points.size(); i++) {points[i][0] = size - i - 1; points[i][1] = size - i - 1;}
    vector<vector<int>> k_points = K_Closest_Points(points, k);

    for(unsigned int i = 0; i < k_points.size(); i++)
    {
        cout << "[" << i << "]" << " " << "[" << k_points[i][0] << "," << k_points[i][1] << "] : " << Distance(k_points[i]) << '\n';
    }
}