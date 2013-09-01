/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
*/


class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int size = triangle.size();
		vector<int> sum[2];
		sum[0].resize(triangle[size - 1].size());
		sum[1].resize(triangle[size - 1].size());
		int p = 0;
		sum[p][0] = triangle[0][0];
		int cur = 0;
		for (int i = 1; i < size; i++)
		{
			int len = triangle[i].size();
			for (int k = 0; k < len; k++)
			{
				cur = (p + 1) % 2;
				if (k == 0)
					sum[cur][k] = sum[p][0] + triangle[i][k];
				else if (k == len - 1)
					sum[cur][k] = sum[p][len - 1 - 1] + triangle[i][k];
				else
				{
					sum[cur][k] = min(sum[p][k - 1], sum[p][k]) + triangle[i][k];
				}
			}
			p = cur;
		}
		int minTotal = sum[p][0];
		for (int i = 0; i < triangle[size - 1].size(); i++)
		{
			minTotal = min(minTotal, sum[cur][i]);
		}
		return minTotal;
	}
};