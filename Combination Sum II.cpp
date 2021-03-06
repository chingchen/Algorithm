/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, � , ak) must be in non-descending order. (ie, a1 = a2 = � = ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
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
		for(int i = 0 ; i< SIZE ;i++)
			allSteps[i].clear();
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
				allSteps[index] = steps;
				ret.push_back(allSteps[index]);
				index++;
				return ;
			}
		}
		for( int i = start ; i< candidates.size(); i++)
		{
			if(GetLeft() < candidates[i])
				return;
			steps.push_back(candidates[i]);
			GetSum(candidates, i+1);
			steps.pop_back();
			while( i < candidates.size() -1 && candidates[i] == candidates[i+1]) 
				i++;			
		}
	}
private:
	vector<int> steps;
	vector<int> allSteps[SIZE];
	int index;
	int target;
	vector<vector<int> > ret;
};

