/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.


*/

class Solution {
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
    vector<int> path;
	solveNQueens(n, 0, path, ret);
	return ret;
    }

	void solveNQueens(int n, int row, vector<int> & path, int & ret)
	{
		if (row == n)
		{
			ret++;
			return ;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (Vaild(row, i, path))
				{
					path.push_back(i);
					solveNQueens(n, row + 1, path, ret);
					path.pop_back();
				}
			}
		}

	}

	bool Vaild(int row, int col, const vector<int> & path)
	{
		int len = path.size();
		for (int i = 0; i < len; i++)
		{
			if (abs(col - path[i]) == 0 || abs(row - i) == abs(col - path[i]))
				return false;
		}
		return true;
	}
};