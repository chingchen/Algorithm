/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(root == NULL)
			return true;
		else
			return isSame(root->left, root->right);
	}

private:
	bool isSame(TreeNode * left , TreeNode * right)
	{
		if(left == NULL )
			return right == NULL;
		if(right == NULL)
			return left == NULL;
	
		if(left->val != right->val)
			return false;
		else
		{
			return	isSame(left->right,right->left) &&
					isSame(left->left ,right->right);
		}
	}
};