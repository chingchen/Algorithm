struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *partition(ListNode *head, int x) 
	{
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		if(head == NULL )
			return head;
		ListNode * first = head;
		ListNode * pre = head;
		ListNode * curr= head;
		int firstIndex = 0;
		while(curr != NULL)
		{
			if(curr->val >= x)
			{
				break;
			}
			pre = curr;
			first = curr;	
			firstIndex++;
			curr = curr -> next;
		}
		while(curr != NULL)
		{
			if(curr->val < x)
			{
				pre->next = curr->next;

				if(firstIndex == 0)
				{
					curr->next= head;
					head = curr;
					firstIndex++;
				}
				else
				{
					curr->next = first->next;
					first->next = curr;
				}
				first = curr;
				curr = pre->next;
			}
			else
			{
				pre = curr;
				curr = curr ->next;
			}
		}
		return head;
	}
};