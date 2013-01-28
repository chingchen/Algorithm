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
		if(left != NULL )
		{
			if(right != NULL)
			{
				if(left->val != right->val)
					return false;
				else
				{
					return	isSame(left->right,right->left) &&
						    isSame(left->left ,right->right);
				}
			}
			else
				return false;
		}
		else
		{
			if(right == NULL)
				return true;
			else
				return false;
		}

	}
};