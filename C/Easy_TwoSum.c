#include <stdio.h>

int* TwoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* results = (int*)malloc(sizeof(*returnSize) * 2);

	for(int i = 0; i < numsSize; i++)
	{
		for(int j = i + 1; j < numsSize; j++)
		{
			if(nums[i] + nums[j] == target)
			{
				results[0] = i;
				results[1] = j;
				return results;
			}
		}
	}

	results[0] = 0;
	results[1] = 0;
	return results;
}

int main()
{
	int target = 9;
	int* returnSize;
	const unsigned int size = 10;
	int* nums = (int*)malloc(sizeof(int) * size);

	nums[0] = 2;
	nums[1] = 7;
	nums[2] = 11;
	nums[3] = 15;

	*returnSize = 2;
	int* results = TwoSum(nums, size, target, returnSize);


	printf("[%d]", results[0]);
	printf("[%d]", results[1]);
}