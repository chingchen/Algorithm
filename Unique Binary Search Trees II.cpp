/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {

public:
	vector<TreeNode *> generateTrees(int n)
	{
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<TreeNode *> trees;
		trees = generateTrees(1, n);
		return trees;
	}

	vector<TreeNode*> generateTrees(int s, int e)
	{
		vector<TreeNode*> trees;
		if (s > e)
			trees.push_back(NULL);
		for (int k = s; k <= e; k++)
		{			
			vector<TreeNode*> leftTrees = generateTrees(s, k - 1);
			vector<TreeNode*> rightTrees = generateTrees(k + 1, e);
			for (int i = 0; i < leftTrees.size(); i++)
			for (int j = 0; j < rightTrees.size(); j++)
			{
				TreeNode * node = new TreeNode(k);
				node->left = leftTrees[i];
				node->right = rightTrees[j];
				trees.push_back(node);
			}		
		}
		return trees;
	}
};