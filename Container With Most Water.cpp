/*
Given n non-negative integers a1, a2, бн, an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		int right = height.size()-1;
		int left = 0;
		int ret = 0;
		while( left < right)
		{
			if( height[right] > height[left])
			{
				int cur = left;
				if(height[left] * (right-left) > ret )
					ret = height[left] * (right-left);
				while( ++left < right &&  height[cur] >  height[left]);
			}
			else
			{
				int cur = right;
				if(height[right] * (right-left) > ret )
					ret = height[right] * (right-left);
				while( left < --right && height[cur] > height[right]);
			}
		}

		return ret;
    }
};

int main()
{
	Solution s ;
	int a[]={2,5,3,1, 6};
	vector<int> input(a,a+sizeof(a)/sizeof(a[0]));
	s.maxArea(input);
}