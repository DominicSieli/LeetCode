#include <vector>
#include <iostream>

int BinarySearch(std::vector<int>& nums, int target)
{
	int left = 0;
	int median = 0;
	int right = nums.size() - 1;

	if(target < nums[left] || target > nums[right]) return -1;

	while(left <= right)
	{
		median = left + (right - left) / 2;

		if(nums[left] == target) return left;
		if(nums[right] == target) return right;
		if(nums[median] == target) return median;
		if(nums[median] < target) left = median + 1;
		if(nums[median] > target) right = median - 1;
	}

	return -1;
}

std::vector<int> vector({2,4,8,16,32,64,128});

int main()
{
	for(int i = 1; i <= 256; i *= 2)
	{
		std::cout << i << ": " << BinarySearch(vector, i) << '\n';
	}
}