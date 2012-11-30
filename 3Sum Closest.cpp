/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target)  {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		Init(num,target);
		Scan(num,0,target);
		return closest + target;

	}
private:
	void Scan(vector<int> &num, int cur ,int target)
	{
		if(index == 3)
		{
			if(abs(currentSum-target) < abs(closest))
			{
				closest = currentSum - target;
				if(closest == 0)
					found = true;
			}
			return ;
		}
		if(found || index >= 3 || closest > 0 && num[cur] > 0 )
			return ;
		for( int i = cur; i< num.size(); i++)
		{				
			steps[index++]= num[i];
			currentSum += num[i];
			Scan(num,i+1,target);			
			index--;
			currentSum -= num[i];
			while(i < num.size()-1 && num[i]== num[i+1])
				i++;
		}
	}
	void Init(vector<int>& num,int target)
	{		
		sort(num.begin(),num.end());
		closest = num[0]+num[1]+num[2]- target;
		currentSum = 0;
		index = 0;
		found = false;
	}
private:
	int closest;
	bool found;
	int currentSum;
	int index;
	int steps[3];
};

int main()
{
	Solution s;
	int ary[]={1,2,4};
	vector<int> input(ary,ary+sizeof(ary)/sizeof(ary[0]));
	int ret;
	ret = s.threeSumClosest(input,171);
}