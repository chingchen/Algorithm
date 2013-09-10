/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return numTrees(1,n);
    }
    int numTrees(int s, int e)
	{
		if( s > e)
			return 1;
		int trees = 0;
		for(int i = s ;i<= e;i++)
		{
			trees += numTrees(s,i-1) * numTrees(i+1,e);
		}
		return trees;
	}
};