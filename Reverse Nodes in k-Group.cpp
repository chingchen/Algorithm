/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if( head == NULL || k == 1) return head;
        ListNode * headHead = new ListNode(0);
	headHead->next = head;
	int i = 0;
	ListNode * cur = head, *last = headHead;
	while(cur != NULL)
	{
		i++;
		if( i % k)
		{
			last = Reverse(last,cur->next);
		}
		cur = cur->next;
		
	}
	return headHead->next;
    	}
	ListNode* Reverse(ListNode * headHead, ListNode * end)
	{
		ListNode * last = headHead->next;
		ListNode * cur = headHead->next->next;
		ListNode * pre = last;
		while( cur != end)
		{
			headHead->next = cur;
			last->next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = last->next;
		}
		return last;
	}
};