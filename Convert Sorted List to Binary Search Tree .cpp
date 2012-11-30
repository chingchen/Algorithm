/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

class Solution {
public:
	TreeNode * sortedListToBST(ListNode* head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		Init();
		ListNode * p = head;
		int len = 0;
		while (p != NULL) 
		{
			len++;
			p= p->next;
		}
		if(len == 0)
			return NULL;
		return CreateTree(head,len);
    }

private :
	TreeNode * CreateTree(ListNode* node,int len)
	{
		if( len == 1)
		{
			TreeNode * t = new TreeNode(node->val);
			t->right = t->left = NULL;
			allNodes.push_back(t);
			return t;
		}
		else
		{
			ListNode * cur= node;
			int i = 1;
			do
			{
				node = node->next;
			}while(++i <= len/2);
			TreeNode * t = new TreeNode(node->val);

			t->left = CreateTree(cur,len/2);
			if(len-len/2-1== 0)
				t->right = NULL;
			else
				t->right = CreateTree(node->next,len-len/2-1);
			allNodes.push_back(t);
			return t;

		}
	}

    void Init()
    {
      /*  for(int i =0 ; i< allNodes.size();i++)
            delete allNodes[i];*/
        allNodes.clear();
    }

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