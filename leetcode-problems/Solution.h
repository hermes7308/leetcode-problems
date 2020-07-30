#pragma once

#include<iostream>
#include<vector>
#include<math.h>
#include<assert.h>
#include<map>
#include<algorithm>
#include<string>

using namespace std;


/*Definition for singly-linked list.*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
	/// <summary>
	/// 1. Two Sum
	/// </summary>
	void runTwoSum();
	vector<int> twoSum(vector<int>& nums, int target);

	/// <summary>
	/// 2. Add Two Numbers
	/// </summary>
	void runAddTwoNumbers();
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

	/// <summary>
	/// 3. Longest Substring Without Repeating Characters
	/// </summary>
	void runLengthOfLongestSubstring();
	int lengthOfLongestSubstring(string s);

	/// <summary>
	/// 4. Median of Two Sorted Arrays
	/// </summary>
	void runFindMedianSortedArrays();
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

	/// <summary>
	/// 1480. Running Sum of 1d Array
	/// </summary>
	void runRunningSum();
	vector<int> runningSum(vector<int>& nums);

	/// <summary>
	/// 1217. Play with Chips
	/// </summary>
	void runMinCostToMoveChips();
	int minCostToMoveChips(vector<int>& chips);

	/// <summary>
	/// 1037. Valid Boomerang
	/// </summary>
	void runIsBoomerang();
	bool isBoomerang(vector<vector<int>>& points);

	/// <summary>
	/// 9. Valid Boomerang
	/// </summary>
	void runIsPalindrome();
	bool isPalindrome(int x);

	/// <summary>
	/// 704. Binary Search
	/// </summary>
	void runBinarySearch();
	int search(vector<int>& nums, int target);
	int binarySearch(vector<int>& nums, int target, int startIndex, int endIndex);

	/// <summary>
	/// 771. Jewels and Stones
	/// </summary>
	void runNumJewelsInStones();
	int numJewelsInStones(string J, string S);

	/// <summary>
	/// 1365. How Many Numbers Are Smaller Than the Current Number
	/// </summary>
	void runSmallerNumbersThanCurrent();
	vector<int> smallerNumbersThanCurrent(vector<int>& nums);
};

