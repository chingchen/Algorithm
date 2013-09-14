/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ? m ? n ? length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    if( n-m == 0 || head == NULL) return head;
    ListNode * headHead = new ListNode(0);
    headHead->next = head;
	ListNode * cur = headHead;
	for(int i = 0; i< m-1;i++)
	{
		cur = cur ->next;
	}
	reverse(cur, n-m+1);
	return headHead->next;
    }
	ListNode * reverse(ListNode * head, int n)
	{
		int i = 1 ; 
		ListNode * last = head->next;
		ListNode * cur = last ->next;
		ListNode * pre = last;
		while( i < n)
		{
			head->next = cur;
			last->next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = last->next;
			i++; 
		}
		return last;
	}
	
};