/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

class Solution {
public:
	void connect(TreeLinkNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		TreeLinkNode * first = root, *parent = root;
		while (first)
		{
			parent = first;
			first = GetNextFirstNode(parent);
			while (parent)
			{
				if (parent->left != NULL)
				{
					if (parent->right != NULL)
					{
						parent->left->next = parent->right;
						if (parent->right != NULL)
						{
							parent->right->next = GetNextNode(parent);
						}
					}
					else
					{
						parent->left->next = GetNextNode(parent);
					}
				}
				else
				{
					if (parent->right != NULL)
					{
						parent->right->next = GetNextNode(parent);
					}

				}
				if (parent != NULL)
					parent = parent->next;
				else
					break;
			}
		}
	}

	TreeLinkNode * GetNextFirstNode ( TreeLinkNode * parent)
	{
		while (parent != NULL )
		{
			if (parent->left == NULL && parent->right == NULL)
			{
				parent = parent->next;
			}
			else
			{
				return parent ->left == NULL ? parent ->right : parent ->left;
			}
		}
		return NULL;
	}
	TreeLinkNode * GetNextNode(TreeLinkNode * parent)
	{
		while (parent != NULL && parent->next != NULL)
		{
			TreeLinkNode * nextParent = parent->next;
			if (nextParent->left == NULL && nextParent->right == NULL)
			{
				parent = nextParent;
			}
			else
			{
				return nextParent->left == NULL ? nextParent->right : nextParent->left;
			}
		}
		return NULL;
	}
};