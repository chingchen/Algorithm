/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        cache.clear();
        
       return  Balanced(root);
    
    }
    
    bool Balanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if(root == NULL)
            return true;
            
        if( abs(GetHeight(root->left) - GetHeight(root->right)) > 1)
           return false;
           
        return Balanced(root->left ) && Balanced(root ->right);
    
    }
    
    map<TreeNode*,int> cache;
    
    int GetHeight( TreeNode * root)
    {
        if(root == NULL)
            return 0;
        int leftHeight, rightHeight;
        
        if( root->left != NULL)
        {
          if(cache.find(root->left) != cache.end())
            leftHeight = cache[root->left];
          else
             cache[root->left] = leftHeight = GetHeight( root->left);
        }
        else
        {
            leftHeight = 0;
        }
        
         if( root->right != NULL)
        {
          if(cache.find(root->right) != cache.end())
             rightHeight = cache[root->right];
          else
             cache[root->right] = rightHeight = GetHeight( root->right);
        }
        else
        {
            rightHeight = 0;
        }
        
        return  rightHeight - leftHeight > 0 ? rightHeight + 1: leftHeight +1;       
    }
};