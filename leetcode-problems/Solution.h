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
};

