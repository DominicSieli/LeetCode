#include <stdio.h>

int BinarySearch(int* nums, int size, int target)
{
	int left = 0;
	int median = 0;
	int right = size - 1;

	if(target < nums[left] || target > nums[right]) return -1;

	while(left <= right)
	{
		median = left + (right - left) / 2;

		if(nums[left] == target) return left;
		else if(nums[right] == target) return right;
		else if(nums[median] == target) return median;
		else if(nums[median] < target) left = median + 1;
		else if(nums[median] > target) right = median - 1;
	}

	return -1;
}

int array[] = {2,4,8,16,32,64,128};
int size = sizeof(array) / sizeof(int);

int main()
{
	for(int i = 1; i <= 256; i *= 2)
	{
		printf("%d: %d\n", i, BinarySearch(array, size, i));
	}
}