class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(height.size()== 0)
		{
			return 0;
		}
		stack<Number> s;
		int max = -1;
		int fareast = 0;
		for(int i = 0; i < height.size();i++)
		{
			fareast = i ;
			int temp = height[i];
			if(s.size() > 0)
			{
				if( s.top().value > temp)
				{					 
					int topIndex = s.top().index;
					while (s.size() > 0 && s.top().value > temp )
					{						
						int current= s.top().value * (topIndex- s.top().farest + 1);
						max = (current > max)? current : max;
						fareast = s.top().farest;
						s.pop();
					}
				}
			}
			s.push(Number(temp,i,fareast));
		}
		if(s.size()>0)
		{
			int topIndex = s.top().index;
			while (s.size() > 0 )
			{ 
				int current= s.top().value * (topIndex- s.top().farest + 1);
				max = (current > max)? current : max;
				s.pop();
			}
		}
		return max;
	}
private:
	struct  Number
	{
		Number(int i ,int j,int k):value(i),index(j),farest(k){}
		int value;
		int index;
		int farest;
	};
};