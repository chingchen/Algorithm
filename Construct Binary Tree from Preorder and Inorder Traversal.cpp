/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(inorder.size() == 0)
			return NULL;
		Clean();
		Build(inorder,preorder,0,preorder.size()-1,0);
		return allNodes[0];
	}

private:
	TreeNode * Build(vector<int> &inorder, vector<int> &preorder,int start ,int end,int inorderPos)
	{
		TreeNode *node = new TreeNode(preorder[inorderPos]);
		allNodes.push_back(node);
		int pos = find(inorder.begin()+start, inorder.begin()+end,preorder[inorderPos]) - inorder.begin();
		if(pos == end)
			node->right = NULL;
		else
			node ->right = Build(inorder, preorder,pos+1,end,inorderPos + pos - start +1);
		if(pos == start)
			node-> left = NULL;
		else
			node ->left = Build(inorder,preorder,start,pos-1,inorderPos+1);
		return node;
	}

	void Clean()
	{
		int len = allNodes.size();
		for(int i = 0; i < len ;i++)
			delete allNodes[i];
		allNodes.clear();
	}
	vector<TreeNode*> allNodes;
};

int main()
{
	Solution s;
	int in[]={1,2,3,4};
	int post[]={2,3,1,4};

	vector<int> inVec(in,in+sizeof(in)/sizeof(in[0]));
	vector<int > outvec(post,post+sizeof(post)/sizeof(post[0]));
	TreeNode* tree = s.buildTree(inVec,outvec);
}