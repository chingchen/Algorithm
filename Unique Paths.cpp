/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?



Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/
class Solution {
public:
	int uniquePaths(int m, int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > paths(m, vector<int>(n, 0));
		return uniquePath(0, 0, m - 1, n - 1, paths);
	}
	int uniquePath(int m, int n, const int rows, const int cols, vector<vector<int> > & paths)
	{
		if (m == rows && n == cols)
			return 1;
		else
		{
			if (paths[m][n] != 0)
			{
				return paths[m][n];
			}
			else
			{
				int right = -1;
				int down = -1;
				if (m != rows)
				{
					down = uniquePath(m + 1, n, rows, cols, paths);
				}
				if (n != cols)
				{
					right = uniquePath(m, n + 1, rows, cols, paths);
				}
				int sum = 0;
				if (right != -1)
					sum += right;
				if (down != -1)
					sum += down;
				return paths[m][n] = sum;
			}
		}
	}
};