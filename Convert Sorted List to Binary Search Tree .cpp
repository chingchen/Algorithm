/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      return  sortedListToBST(head, NULL);
    }
    
    TreeNode * sortedListToBST(ListNode * start, ListNode * end)
    {
        if( start != end)
	{
            ListNode * middle = FindMiddle(start, end);
            TreeNode * head = new TreeNode( middle->val);
            if( middle != start)
                head -> left = sortedListToBST(start,middle);
            if( middle != end)
                head -> right = sortedListToBST(middle->next, end);
        }
        else
            return NULL;       
    }
    
    ListNode* FindMiddle(ListNode * start, ListNode * end)
    {
        ListNode * oneStep = start;
        ListNode * twoStep  = start;
        while( twoStep->next != end && twoStep->next->next != end)
        {
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
        }
        return oneStep;
    }
};

    vector<TreeNode*> allNodes;

public :
	void Print(TreeNode* node)
	{
		queue<TreeNode*> que;
		if( node == NULL)
			return;
		que.push(node);
		while(!que.empty())
		{
			if( que.front() == NULL)
			{
				cout << "# ";
				que.pop();
				continue;
			}
			cout << que.front()->val<<" ";
			que.push(que.front()->left);
			que.push(que.front()->right);
			que.pop();			
		}
	}
};