/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    if( head == NULL)
		return head;
        ListNode * pre = head;	
	ListNode * cur = head->next;
	pre->next = NULL;
	while(cur != NULL)
	{
		if( cur->val != pre->val)
		{
			pre->next = cur;;
			pre = cur;
		}
		
		cur = cur->next;
		pre->next = NULL;
	}
	
	return  head;
    }
};