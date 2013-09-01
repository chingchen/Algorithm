/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    
    ListNode * preNode = head, * lastNode = head;
	for( int i = 1; i <= n ;i++)
		lastNode = lastNode->next;
	if(lastNode == NULL)
		return head->next;
	while(lastNode->next != NULL)
	{
		lastNode = lastNode->next;
		preNode = preNode->next;
	}
	preNode->next = preNode->next->next;
	return head;
    }
};