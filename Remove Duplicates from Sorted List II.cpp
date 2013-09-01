/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (head == NULL)
			return NULL;
		int rTimes = 0;
		ListNode* pre = head;
		ListNode * cur = head->next;
		ListNode * ret = NULL;
		while (cur != NULL)
		{
			if (cur->val == pre->val)
			{
				rTimes += 1;
			}
			else
			{
				if (rTimes == 0)
				{
					ret = pre;
					break;
				}
				rTimes = 0;
			}
			pre = cur;
			cur = cur->next;
		}
		if (rTimes == 0)
			ret = pre;
		if (ret != NULL)
		{
			rTimes = 0;
			cur = ret->next;
			ListNode * end = ret;
			pre = ret;
			while (cur != NULL)
			{
				if (cur->val == pre->val)
				{
					rTimes += 1;
				}
				else
				{
					if (rTimes == 0)
					{
						end->next = pre;
						end = pre;
						end->next = NULL;
					}
					rTimes = 0;

				}
				pre = cur;
				cur = cur->next;
			}
			if (rTimes == 0)
			{
				end->next = pre;
				end->next->next = NULL;
			}
		}
		return ret;
	}
};