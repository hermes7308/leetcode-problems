#pragma once

#include<iostream>
#include<vector>
#include<math.h>

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
	/// 1. Tow Sum
	/// </summary>
	void runTwoSum();
	vector<int> twoSum(vector<int>& nums, int target);

	void runAddTwoNumbers();
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

