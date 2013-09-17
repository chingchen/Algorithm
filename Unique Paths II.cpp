/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        if(m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] ==1 ||obstacleGrid[0][0] ==1 )
    	    	return 0; 
        vector<vector<int> > paths(m, vector<int>(n, -1));
		return uniquePath(0, 0, m - 1, n - 1, obstacleGrid,paths);
   	 }
	
	int uniquePath(int m, int n, const int rows, const int cols, vector<vector<int> > &obstacleGrid, vector<vector<int> > & paths)
	{
		if (m == rows && n == cols)
        {
            return 1;      		
        }
		else
		{
			if (paths[m][n] != -1)
			{
				return paths[m][n];
			}
			else
			{
				int right = -1;
				int down = -1;
				if (m != rows && obstacleGrid[m+1][n] != 1 )
				{
					down = uniquePath(m + 1, n, rows, cols,obstacleGrid, paths);
				}
				if (n != cols && obstacleGrid[m][n+1] != 1)
				{
					right = uniquePath(m, n + 1, rows, cols,obstacleGrid, paths);
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