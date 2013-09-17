/*
The n-queens puzzle is the problem of placing n queens on an n?n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {

public:
    vector<vector<string> > solveNQueens(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<string> > ret;
		vector<int> path;
		solveNQueens(n, 0, path, ret);
		return ret;
	}

	void solveNQueens(int n, int row, vector<int> & path, vector<vector<string> > & ret)
	{
		if (row == n)
		{
			vector<string> tmp;
			for (int i = 0; i < n; i++)
			{
				string str(n, '.');
				str[path[i]] = 'Q';
				tmp.push_back(str);
			}
			ret.push_back(tmp);
			return;
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