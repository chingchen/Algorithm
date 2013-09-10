/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

class Solution {
public:
    bool isVaildBST(TreeNode * root, int & pre)
	{
		if(root == NULL)
			return true;
		if(root -> left != NULL)
			if(! isVaildBST(root->left, pre))
				return false;
		if(pre >= root->val)
				return false;
		pre = root->val;
		if(root -> right != NULL)
			if(! isVaildBST(root ->right, pre))
				return false;
        return true;
	}     

    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
          int pre = -100000000000;
          return isVaildBST (root, pre);
    }
};