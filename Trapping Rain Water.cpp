/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.



The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/
class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( n < 3 ) return 0;
	vector<int> leftHeight(n);
	vector<int> rightHeight(n);
	int maxHeight = 0;
	for(int i = 0 ;i <n ;i++)
	{
		leftHeight[i] = maxHeight;
		maxHeight = max(maxHeight, A[i]);
			
	}
	maxHeight = 0;
	for(int i = n - 1;i >= 0 ;i--)
	{
		rightHeight[i] = maxHeight;
		maxHeight = max(maxHeight, A[i]);
	}
	int ret = 0;
	for(int i = 0 ;i < n ;i++)
	{
		int h = min(leftHeight[i], rightHeight[i]);
		if( h > A[i] )
			ret += h - A[i];
	}
	return ret;
    }
};