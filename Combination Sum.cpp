/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 = a2 = … = ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
*/

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		sort(candidates.begin(),candidates.end());
		Init(target);
		GetSum(candidates,0);
		return ret;
	}


#define SIZE 1000    
private:
	void Init(int t)
	{
		ret.clear();
		index = 0;
		target = t;
	}
	int GetLeft()
	{
		int size = steps.size();
		unsigned sum = 0;
		for(int i = 0;i < size ; i++)
			sum += steps[i];
		return target - sum;
	}
	void GetSum(vector<int> &candidates ,int start)
	{	
		if(steps.size() > 0 )
		{
			int left = GetLeft();
			if(left == 0)
			{
				ret.push_back(steps);
				index++;
				return ;
			}
		}
		for( int i = start ; i< candidates.size(); i++)
		{
			int times = 0;
			while (GetLeft() >= candidates[i])
			{
				steps.push_back(candidates[i]);
				GetSum(candidates, i+1);
				times++;
			};
			while(times >=1)
			{
				steps.pop_back();
				times--;
			}
			while( i < candidates.size() -1 && candidates[i] == candidates[i+1]) 
				i++;			
		}
	}
private:
	vector<int> steps;
	int index;
	int target;
	vector<vector<int> > ret;
};