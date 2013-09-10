/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

class Solution {
    stack<TreeNode *> steps;
	vector<vector<int> > paths;
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		// start typing your c/c++ solution below
		// do not write int main() function

		while (!steps.empty())
			steps.pop();
		paths.clear();
		if (root == NULL)
			return paths;
		GetPathSum(root, sum);
		return paths;
	}
	void GetPathSum(TreeNode *root, int sum)
	{
		steps.push(root);
		if (root->left == NULL && root->right == NULL)
		{
			if (sum == root->val)
			{
				int len = steps.size();
				vector<int> path(len, 0);
				stack<TreeNode *> tmp(steps);
				while (!tmp.empty())
				{
					path[--len] = tmp.top()->val;
					tmp.pop();
				}
				paths.push_back(path);
			}
		}
		else
		{
			if (root->left != NULL)
				GetPathSum(root->left, sum - root->val);
			if (root->right != NULL)
				GetPathSum(root->right, sum - root->val);
		}
		steps.pop();
	}
};
