#include "Solution.h"

void Solution::runTwoSum()
{
	vector<int> nums;
	nums.reserve(4);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);

	int target = 9;

	vector<int> result = twoSum(nums, target);
	cout << result.at(0) << ", " << result.at(1) << endl;
}

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		int num = *it;
		for (auto itx = it + 1; itx != nums.end(); itx++)
		{
			int numx = *itx;

			if (target == num + numx)
			{
				vector<int> result;
				result.reserve(2);
				result.push_back(distance(nums.begin(), it));
				result.push_back(distance(nums.begin(), itx));

				return result;
			}
		}
	}
	return vector<int>();
}
