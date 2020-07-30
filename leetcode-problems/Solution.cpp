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

void Solution::runIsBoomerang()
{
	vector<int> point11;
	point11.push_back(1);
	point11.push_back(1);
	vector<int> point12;
	point12.push_back(2);
	point12.push_back(3);
	vector<int> point13;
	point13.push_back(3);
	point13.push_back(2);

	vector<vector<int>> points1;
	points1.push_back(point11);
	points1.push_back(point12);
	points1.push_back(point13);

	bool result1 = isBoomerang(points1);
	assert(result1 == true);

	vector<int> point21;
	point21.push_back(1);
	point21.push_back(1);
	vector<int> point22;
	point22.push_back(2);
	point22.push_back(2);
	vector<int> point23;
	point23.push_back(3);
	point23.push_back(3);

	vector<vector<int>> points2;
	points2.push_back(point21);
	points2.push_back(point22);
	points2.push_back(point23);

	bool result2 = isBoomerang(points2);
	assert(result2 == false);

	vector<int> point31;
	point31.push_back(0);
	point31.push_back(0);
	vector<int> point32;
	point32.push_back(1);
	point32.push_back(2);
	vector<int> point33;
	point33.push_back(0);
	point33.push_back(1);

	vector<vector<int>> points3;
	points3.push_back(point31);
	points3.push_back(point32);
	points3.push_back(point33);

	bool result3 = isBoomerang(points3);
	assert(result3 == true);
}

bool Solution::isBoomerang(vector<vector<int>>& points)
{
	vector<int> point1 = points[0];
	vector<int> point2 = points[1];
	vector<int> point3 = points[2];

	double side1 = sqrt(double(pow(point1[0] - point2[0], 2) + pow(point1[1] - point2[1], 2)));
	double side2 = sqrt(double(pow(point2[0] - point3[0], 2) + pow(point2[1] - point3[1], 2)));
	double side3 = sqrt(double(pow(point3[0] - point1[0], 2) + pow(point3[1] - point1[1], 2)));

	vector<double> triangle;
	triangle.push_back(side1);
	triangle.push_back(side2);
	triangle.push_back(side3);

	int maxIndex = 0;
	for (int i = 1; i < triangle.size(); i++)
	{
		if (triangle[maxIndex] < triangle[i])
		{
			maxIndex = i;
		}
	}

	double sumTwoSide = 0;
	for (int i = 0; i < triangle.size(); i++)
	{
		if (i == maxIndex)
		{
			continue;
		}

		sumTwoSide += triangle[i];
	}

	return sumTwoSide > triangle[maxIndex];
}

void Solution::runIsPalindrome()
{
	int input1 = 121;
	bool result1 = isPalindrome(input1);
	assert(result1 == true);

	int input2 = -121;
	bool result2 = isPalindrome(input2);
	assert(result2 == false);

	int input3 = 10;
	bool result3 = isPalindrome(input3);
	assert(result3 == false);
}

bool Solution::isPalindrome(int x)
{
	if (x < 0) {
		return false;
	}

	string str = to_string(x);
	for (int startIndex = 0, endIndex = str.length() - 1; startIndex <= endIndex; startIndex++, endIndex--)
	{
		if (str.at(startIndex) == str.at(endIndex))
		{
			continue;
		}

		return false;
	}

	return true;
}

void Solution::runBinarySearch()
{
	vector<int> nums1;
	nums1.push_back(-1);
	nums1.push_back(0);
	nums1.push_back(3);
	nums1.push_back(5);
	nums1.push_back(9);
	nums1.push_back(12);

	int target1 = 9;

	int result1 = search(nums1, target1);
	assert(result1 == 4);

	vector<int> nums2;
	nums2.push_back(-1);
	nums2.push_back(0);
	nums2.push_back(3);
	nums2.push_back(5);
	nums2.push_back(9);
	nums2.push_back(12);

	int target2 = 2;

	int result2 = search(nums2, target2);
	assert(result2 == -1);
}

int Solution::search(vector<int>& nums, int target)
{
	return binarySearch(nums, target, 0, nums.size());
}

int Solution::binarySearch(vector<int>& nums, int target, int startIndex, int endIndex)
{
	int middleIndex = (startIndex + endIndex) / 2;
	if (nums[middleIndex] == target)
	{
		return middleIndex;
	}

	if (startIndex == middleIndex || endIndex == middleIndex)
	{
		return -1;
	}

	if (nums[middleIndex] > target)
	{
		return binarySearch(nums, target, startIndex, middleIndex);
	}

	return binarySearch(nums, target, middleIndex, endIndex);
}

void Solution::runNumJewelsInStones()
{
	string J1 = "aA";
	string S1 = "aAAbbbb";
	int result1 = numJewelsInStones(J1, S1);
	assert(result1 == 3);

	string J2 = "z";
	string S2 = "ZZ";
	int result2 = numJewelsInStones(J2, S2);
	assert(result2 == 0);
}

int Solution::numJewelsInStones(string J, string S)
{
	int count = 0;

	for (int i = 0; i < J.length(); i++)
	{
		int cur = 0;
		char stone = J.at(i);
		while (true)
		{
			string::size_type loc = S.find(stone, cur);
			if (loc == string::npos) {
				break;
			}
			cur = loc + 1;
			count++;
		}

	}	

	return count;
}
