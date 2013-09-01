/*Given a binary tree, flatten it to a linked list in-place.

For example,
Given

1
/ \
2 5
/ \ \
3 4 6
The flattened tree should look like:
1
\
 2
   \
	 3
	  \
		4
		\
		 5
	      \
			6
Hints:
If you notice carefully in the flattened tree, each node¡¯s right child points to the next node of a pre-order traversal.
*/

class Solution
{
public:
	void flatten(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (root != NULL)
		{
			flatten(root->right);
			flatten(root->left);
			TreeNode * left = root->left;
			while (left != NULL && left->right != NULL)
				left = left->right;
			if (left != NULL)
			{
				left->right = root->right;
				root->right = root->left;
				root->left = NULL;
			}
		}
	}
};
