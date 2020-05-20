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
