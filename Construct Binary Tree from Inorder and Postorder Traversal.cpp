/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

class Solution {

map<int,int> indexMap;

public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if( inorder.size() == 0)
		return NULL;
	indexMap.clear();
	int len = inorder.size();
	for( int i = 0 ;i < len ;i ++)
	{
		indexMap[inorder[i]] = i;
	}
         return buildTree(postorder, len-1, inorder, 0,len -1);
	}

	TreeNode * buildTree(vector<int > & postorder , int postIndex, vector<int> & inorder, int inBegin, int inEnd)
	{
		TreeNode * head = new TreeNode( postorder[postIndex]);
		int inIndex = indexMap[postorder[postIndex]];
		int distance = inEnd - inIndex;
		if( inIndex > inBegin)
		{
			head-> left = buildTree( postorder, postIndex- distance -1, inorder, inBegin,inIndex-1);
		}
		if( inIndex < inEnd)
		{
			head->right = buildTree(postorder, postIndex -1 ,inorder, inIndex+1, inEnd);
		}
		return head;
	}
};