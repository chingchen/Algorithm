class Solution 
{
public:
	void recoverTree(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		biggerNum = smallerNum = NULL;
		TreeNode temp(-10000000);
		TreeNode * tmpNode = &temp;
		inorderTraverse(root,tmpNode);

		int tmp = smallerNum->val;
		smallerNum->val= biggerNum->val;
		biggerNum->val = tmp;
	}
private:
	TreeNode* biggerNum;
	TreeNode* smallerNum;

	void inorderTraverse(TreeNode * root,TreeNode * & pre)
	{
		if(root != NULL)
		{
			inorderTraverse(root->left,pre);
			if(pre->val > root->val)
			{
				smallerNum = root;
				if(biggerNum == NULL)
					biggerNum = pre;
			}
			inorderTraverse(root->right,root);
			pre = root;
		}
	}
};