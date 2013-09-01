/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   unsigned int maxD;
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if (root == NULL)
			return 0;
		stack<TreeNode*> path;
		maxD = 0;
		maxDepth(root, path);
		return maxD;
	}

	void maxDepth(TreeNode *root, stack<TreeNode*> & path) {

		path.push(root);
		if (root->left != NULL)
			maxDepth(root->left, path);
		if (root->right != NULL)
			maxDepth(root->right, path);
		if (root->right == NULL && root->left == NULL)
		{
			maxD = max(maxD, path.size());
		}

		path.pop();
	}

};