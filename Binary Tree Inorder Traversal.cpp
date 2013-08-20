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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    vector<int> trace;
    if( root == NULL) return trace;
	stack<TreeNode*> hNodes;
	hNodes.push(root);
	TreeNode * cur = hNodes.top();
	while( cur->left != NULL)
	{
		hNodes.push(cur->left);
		cur = cur->left;
	}
	while( ! hNodes.empty())
	{
		cur = hNodes.top();
		trace.push_back(cur->val);
		hNode.pop();
		if( cur-> right != NULL)
		{
			hNodes.push(cur->right);
			cur = cur->right;
			while( cur->left != NULL)
			{
				hNodes.push(cur->left);
				cur = cur->left;
			}
		}
		
	}
	return trace;
    }
};