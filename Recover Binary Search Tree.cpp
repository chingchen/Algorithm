/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode * w1 ,* w2,*last;
public:
    void recoverTree(TreeNode *root)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        w1 = NULL;
        w2 = NULL;
    last = NULL;
        TreeNode * start = NULL;
        traverse(root, start);
        if( w1 != NULL || w2 != NULL)
        {
            if(w2 == NULL)
            {
               w2 = last;
            }
            int val = w1->val;
            w1->val = w2->val;
            w2->val = val;
            
        }
    }
     void traverse(TreeNode *root , TreeNode * & pre) 
     {
        if(root->left != NULL)
            traverse(root->left, pre);
        if(pre != NULL)
        {
            if( pre->val > root->val)
            {
                if( w1 == NULL && w2 == NULL)
                {
                    w1 = pre;
                    last = root;
                }
                else
                {
                   w2 = root; 
                }
            }
        }
        pre = root;
        if(root->right != NULL)
             traverse(root->right, pre);
     }
};