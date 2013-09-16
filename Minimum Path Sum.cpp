/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
    vector<vector<int> > mem;
public:
	int minPathSum(vector<vector<int> > &grid) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		mem.clear();
		mem.resize(grid.size(), vector<int>(grid[0].size(), 0));
		return minPathSum(grid, 0, 0);
	}

	int minPathSum(vector<vector<int> >& grid, int m, int n)
	{
		int rows = grid.size() - 1;
		int cols = grid[0].size() - 1;
		if (m == rows && n == cols)
			return mem[m][n] = grid[m][n];
		if (mem[m][n] != 0)
			return mem[m][n];
		else
		{
			int right = -1;
			int down = -1;
			if (n == cols)
			{
				down = minPathSum(grid, m + 1, n) + grid[m][n];
			}
			else if (m == rows)
			{
				right = minPathSum(grid, m, n + 1) + grid[m][n];
			}
			else
			{
				down = minPathSum(grid, m + 1, n) + grid[m][n];
				right = minPathSum(grid, m, n + 1) + grid[m][n];
			}
			if (right == -1)
				return mem[m][n] = down;
			else if (down == -1)
				return mem[m][n] = right;
			else
				return mem[m][n] = min(down, right);
		}
	}
};