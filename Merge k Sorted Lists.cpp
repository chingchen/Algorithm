/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    ListNode headHead(0);
    int size = lists.size();
    ListNode * cur = NULL;
	ListNode * pre= & headHead;
	do
	{
		cur = NULL; 
		int minIndex = 0;
		for( int i = 0;i < size ; i++)
		{
			if( lists[i] == NULL)
				continue;
			if(cur == NULL)
			{			
				cur = lists[i];	
				minIndex  = i;				
			}
			else
			{
				if(lists[i]->val < cur->val)
				{
					cur = lists[i];
					minIndex  = i;
				}
			}
		}
		if(cur == NULL)
			break;
		lists[minIndex] = lists[minIndex]->next;
		pre -> next = cur;
		pre = cur;		
	}while(true);
	pre->next = NULL;
     return headHead.next;
    }   
};