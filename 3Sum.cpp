/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a = b = c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		Init(num);
		Scan(num,0,0);
		return allNumbs;

	}
#define SIZE 1000
private:
	void Scan(vector<int> &num, int cur ,int left)
	{
		if(steps.size() == 3 && left == 0)
		{
			numbs[index]= steps;
			allNumbs.push_back(numbs[index]);
			index++;
			return ;
		}
		for( int i = cur; i< num.size(); i++)
		{
			if(steps.size()>=3 || left < num[cur])
				return;
			steps.push_back(num[i]);
			Scan(num,i+1,left - num[i]);
			steps.pop_back();
			while(i < num.size()-1 && num[i]== num[i+1])
				i++;
		}
	}

	void Init(vector<int>& num)
	{
		index = 0;
		steps.clear();
		allNumbs.clear();
		for(int i = 0; i <SIZE ;i++)
			numbs[i].clear();
		sort(num.begin(),num.end());
	}
private:
	vector<int> steps;
	vector<int> numbs[SIZE];
	int index;
	vector<vector<int> > allNumbs;

};

int main()
{
	Solution s;
	int ary[]={-1 ,0 ,1 ,2, -1, -4 };
	vector<int> input(ary,ary+sizeof(ary)/sizeof(ary[0]));
	vector<vector<int> > ret;
	ret = s.threeSum(input);
}