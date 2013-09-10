/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ListNode * headHead = new ListNode(0);
		ListNode * great = headHead, *less = headHead;
		ListNode * cur = head;
		while (cur != NULL)
		{
			ListNode * next = cur->next;
			if (cur->val < x)
			{
				if (great == less)
					great = cur;
				cur->next = less->next;
				less->next = cur;
				less = cur;
			}
			else
			{
				cur->next = great->next;
				great->next = cur;
				great = cur;
			}
			cur = next;
		}
		return headHead->next;
	}
};