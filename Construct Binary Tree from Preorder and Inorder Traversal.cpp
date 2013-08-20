/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    
map<int, int> hashMap;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         if( preorder.size() == 0)
            return NULL;
         hashMap.clear();
         for( int i = 0 ; i < inorder.size(); i++)
         {
             hashMap[inorder[i]] = i;
         }
         
         return buildTree(preorder, 0, inorder, 0, inorder.size()-1);
    }
    
    TreeNode * buildTree(vector<int>& preorder, int preIndex, vector<int> & inorder, int inBegin, int inEnd)
    {
        TreeNode * head = new TreeNode( preorder[preIndex]);
        
        int inIndex = hashMap[ preorder[preIndex]];       
        
        
        if( inIndex != inBegin )
        {
            head -> left = buildTree( preorder ,preIndex+1, inorder, inBegin, inIndex-1);
        }
        else
        {
            head -> left = NULL;            
        }
        
        if(inIndex != inEnd)
        {
            head->right = buildTree( preorder, preIndex + inIndex - inBegin + 1, inorder, inIndex+1, inEnd);
        }
        else
        {
            head->right = NULL;
        }
        
        return head;
    }
};