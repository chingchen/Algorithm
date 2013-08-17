/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
*/

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    vector<vector<int> > res;
	if( root == NULL ) return res;
	queue<TreeNode*> nodes;
	nodes.push(root);
	nodes.push(NULL);
	vector<int> level;
	while(!nodes.empty())
	{
	   TreeNode * cur = nodes.front();
		 if(cur == NULL)
		{
			if(level.size() == 0)
				break;
		 	res.push_back(level);
			level.clear();
			nodes.push(NULL);
        
		}	
		else
		{
			level.push_back(cur->val);
			if(cur->left != NULL) nodes.push(cur->left);
			if(cur->right != NULL) nodes.push(cur->right);
		}
		nodes.pop();
	}   
	return res;     
    }
};