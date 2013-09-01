/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

class Solution {

    unsigned int minD;

public:
	int minDepth(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (root == NULL)
			return 0;
		stack<TreeNode*> path;
		minD = -1;
		minDepth(root, path);
		return minD;
	}

	void minDepth(TreeNode *root, stack<TreeNode*> & path) {

		path.push(root);
		if (root->left != NULL)
			minDepth(root->left, path);
		if (root->right != NULL)
			minDepth(root->right, path);
		if (root->right == NULL && root->left == NULL)
		{
			minD = min(minD, path.size());
		}

		path.pop();
	}

};