/*
Given n non-negative integers a1, a2, бн, an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start = 0 , end = height.size() -1;
        int maxarea = 0;
        while( start < end)
        {
            int minHeight = min( height[start], height[end]);
            maxarea = max( maxarea, minHeight * ( end - start));
            
            while( start < end && height[start] <= minHeight)
                start++;
            
            while( start < end && height[end] <= minHeight)
                end--;            
        }
        return maxarea;
    }
};

int main()
{
	Solution s ;
	int a[]={2,5,3,1, 6};
	vector<int> input(a,a+sizeof(a)/sizeof(a[0]));
	s.maxArea(input);
}