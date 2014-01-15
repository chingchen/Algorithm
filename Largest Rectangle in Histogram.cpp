/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.



Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].



The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    int size = height.size();
	stack<StackElem> s;
	if(size == 0)
		return 0;
	int curMax = 0;
    for( int i = 0 ;i < size;i++)
	{
		StackElem tmp(i,i,height[i]);
		if(s.size() > 0)
		{
			while( s.size() > 0 && s.top().val >= height[i])
			{
				StackElem e = s.top();
				e.mostRight = i-1;
				tmp.mostLeft = e.mostLeft;
				curMax = max((e.mostRight - e.mostLeft + 1) * e.val , curMax);
                s.pop();
			}
		}
		s.push(tmp);
	}
    int preRight = size -1;
	while(! s.empty())
	{
		StackElem e = s.top();
		curMax = max((preRight  - e.mostLeft + 1) * e.val , curMax);
		s.pop();        
	}
    
	return curMax;
    }

private:
	struct StackElem
	{
		int mostLeft;
		int mostRight;
		int val;
		StackElem(int left, int right, int v)
		{
			mostLeft = left;
			mostRight = right;
			val = v;
		}
	};
};