//From top to bottom ,preorder traversal

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

       return sumNumbers(root,0);
    }
    int sumNumbers(TreeNode * root ,int parent)
    {
  if(root == NULL)
		return 0;
	int current = parent * 10 + root->val;
	if(root->right == NULL && root->left == NULL)
		return current ;

	int left = 0, right = 0;	
	if(root->left != NULL)
		left = sumNumbers(root->left, current);
	if(root->right != NULL)
		right = sumNumbers(root->right,current);	

	return left + right;
	
    }
};
