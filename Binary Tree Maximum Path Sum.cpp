class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = root->val;
	maxSum(root,max);
	return max;
    }
    int maxSum(TreeNode * root,int & max)
   {
	int left = 0 ,right =0 ;
	if( root->left != NULL )
		left = maxSum(root->left,max);
	if( root->right != NULL )
		right = maxSum(root->right,max);

	int addition = root->val ;
	if( left > 0)  addition += left;
	if( right > 0) addition += right;
	if( addition  > max )
		max = addition ;
	if( left > right )
	{
		if(left > 0)
			return left + root->val;
	}
	else
	{
		if(right > 0)
			return right + root->val;
	}
	return root->val;
    }
};