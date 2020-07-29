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

void Solution::runAddTwoNumbers()
{
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	ListNode* result = addTwoNumbers(l1, l2);
	cout << result->val << "->" << result->next->val << "->" << result->next->next->val << endl;

	delete result;
	delete l2;
	delete l1;
}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* result = new ListNode();
	ListNode* prev = result;
	int n = 0;

	while (l1 != nullptr || l2 != nullptr || n != 0)
	{
		if (l1 != nullptr)
		{
			n += l1->val;
			l1 = l1->next;
		}

		if (l2 != nullptr)
		{
			n += l2->val;
			l2 = l2->next;
		}

		prev->next = new ListNode(n % 10);
		prev = prev->next;
		n /= 10;
	}

	return result->next;
}

void Solution::runLengthOfLongestSubstring()
{
	assert(lengthOfLongestSubstring("abcabcbb"), 3);
	assert(lengthOfLongestSubstring("bbbbb"), 1);
	assert(lengthOfLongestSubstring("pwwkew"), 3);
}

int Solution::lengthOfLongestSubstring(string s)
{
	map<char, int> mapper;
	int startIndex = 0;
	int lengthOfLongest = 0;

	for (int index = 0; index < s.length(); index++)
	{
		char character = s.at(index);
		if (mapper.find(character) != mapper.end() && mapper[character] >= startIndex)
		{
			startIndex = mapper[character] + 1;
		}
		else
		{
			int currentLength = index - startIndex + 1;
			lengthOfLongest = lengthOfLongest > currentLength ? lengthOfLongest : currentLength;
		}

		mapper[character] = index;
	}

	return lengthOfLongest;
}

void Solution::runFindMedianSortedArrays()
{
	vector<int> num1;
	num1.push_back(1);
	num1.push_back(3);

	vector<int> num2;
	num2.push_back(2);

	assert(2.0 == findMedianSortedArrays(num1, num2));

	vector<int> num3;
	num3.push_back(1);
	num3.push_back(2);

	vector<int> num4;
	num4.push_back(3);
	num4.push_back(4);

	assert(2.5 == findMedianSortedArrays(num3, num4));
}

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	nums1.reserve(nums1.size() + distance(nums2.begin(), nums2.end()));
	nums1.insert(nums1.end(), nums2.begin(), nums2.end());
	sort(nums1.begin(), nums1.end());

	int n = 0;

	if (nums1.size() % 2 == 0)
	{
		n = nums1.size() / 2;
		return double(nums1[n - 1] + nums1[n]) / 2;
	}
	else
	{
		n = (nums1.size() / 2);
		return nums1[n];
	}
}

void Solution::runRunningSum()
{
	vector<int> nums1;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(3);
	nums1.push_back(4);

	vector<int> result1 = runningSum(nums1);
	assert(result1[0] == 1);
	assert(result1[1] == 3);
	assert(result1[2] == 6);
	assert(result1[3] == 10);


	vector<int> nums2;
	nums2.push_back(1);
	nums2.push_back(1);
	nums2.push_back(1);
	nums2.push_back(1);
	nums2.push_back(1);

	vector<int> result2 = runningSum(nums2);
	assert(result2[0] == 1);
	assert(result2[1] == 2);
	assert(result2[2] == 3);
	assert(result2[3] == 4);
	assert(result2[4] == 5);

	vector<int> nums3;
	nums3.push_back(3);
	nums3.push_back(1);
	nums3.push_back(2);
	nums3.push_back(10);
	nums3.push_back(1);

	vector<int> result3 = runningSum(nums3);
	assert(result3[0] == 3);
	assert(result3[1] == 4);
	assert(result3[2] == 6);
	assert(result3[3] == 16);
	assert(result3[4] == 17);
}

vector<int> Solution::runningSum(vector<int>& nums)
{
	vector<int> result;
	result.reserve(nums.size());

	for (int i = 0; i < nums.size(); i++)
	{
		int val;

		if (i - 1 >= 0)
		{
			val = result[i - 1] + nums[i];
		}
		else
		{
			val = nums[i];
		}
		result.push_back(val);
	}

	return result;
}

void Solution::runMinCostToMoveChips()
{
	vector<int> chips1;
	chips1.push_back(1);
	chips1.push_back(2);
	chips1.push_back(3);

	int result1 = minCostToMoveChips(chips1);
	assert(result1 == 1);

	vector<int> chips2;
	chips2.push_back(2);
	chips2.push_back(2);
	chips2.push_back(2);
	chips2.push_back(3);
	chips2.push_back(3);

	int result2 = minCostToMoveChips(chips2);
	assert(result2 == 2);
}

int Solution::minCostToMoveChips(vector<int>& chips)
{
	int even = 0;
	int odd = 0;
	for (int i = 0; i < chips.size(); i++)
	{
		if (chips[i] % 2 == 0)
		{
			even++;
		}
		else
		{
			odd++;
		}
	}

	return even > odd ? odd : even;
}
