/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
*/

class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		Init();
		sort(S.begin(),S.end());
		SubSet(S,0,S.size());

		return ret;
	}


private:
	vector<int> steps[10000];
	vector<int> step;
	int current;
	vector<vector<int> > ret;

	void Init()
	{
		current = 0;
		ret.clear();
		for( int i = 0; i< 1000;i++)
			steps[i].clear();
	}

	void SubSet(vector<int> &S ,int s, int end)
	{
		if(s == end)
		{				
			steps[current] = step;
			ret.push_back(steps[current]);
			current++;
			return ;
		}
		vector<int>::iterator p =  upper_bound(S.begin()+s, S.end(),S[s]);
		int times = p - S.begin() - s ;
		for( int i = 0 ; i < times ;i++)
		{
			step.push_back(S[s]);
			SubSet(S, p-S.begin(), end);
		}
		while(times-- >= 1)
		{
			step.pop_back();
		}
		SubSet(S,p-S.begin(),end);
	}
};