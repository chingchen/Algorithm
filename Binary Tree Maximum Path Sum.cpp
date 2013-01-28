class Solution {
public:
	int maxPathSum(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(root == NULL)
			return 0;
		max = root->val;
		GetMax(root);
		return max;
	}
private:
	int max  ;
	int GetMax( TreeNode * root)
	{
		if(root == NULL)
			return 0;
		int leftMax = GetMax(root->left);
		int rightMax = GetMax(root->right);

		int currentMax = root->val;
		if(leftMax >0)
			currentMax += leftMax;
		if(rightMax > 0)
			currentMax += rightMax;
		if(currentMax > max)
			max = currentMax;

		if(leftMax > rightMax)	
		{
			if(leftMax >0)
				return root->val + leftMax;
			else 
				return root->val;
		}
		else		
		{
			if(rightMax >0)
				return root->val + rightMax;
			else
				return root->val;	
		}
	}
};