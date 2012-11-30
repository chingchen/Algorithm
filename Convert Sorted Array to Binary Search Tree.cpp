/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		Init();
		return CreateTree(num,0,num.size()-1);

	}


private:
	TreeNode* CreateTree(vector<int> &num,int s, int e)
	{
		if( s <= e)
		{
			int m = (s+e)/2;
			TreeNode * p = new TreeNode(num[m]);
			allNodes.push_back(p);
			p->left = CreateTree(num,s,m-1);
			p->right = CreateTree(num,m+1,e);
			return p;
		}
		return NULL;
	}

	void Init()
	{
		for(int i =0 ; i< allNodes.size();i++)
			delete allNodes[i];
		allNodes.clear();
	}

	vector<TreeNode*> allNodes;

};

int main()
{
	Solution s ;

}