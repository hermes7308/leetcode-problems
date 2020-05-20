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
