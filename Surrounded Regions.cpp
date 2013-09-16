/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region .

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution {
    struct Pos
	{
		Pos(int i, int j) :row(i), col(j){}
		int row;
		int col;
	};

	vector<vector<bool> > visit;
	vector<Pos> curVisit;
	bool found;

public:
	void solve(vector<vector<char> > &board)
	{
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int rows = board.size();
		if (rows == 0)
			return;
		int cols = board[0].size();
        visit.clear();
		visit.resize(rows, vector<bool>(cols, false));
		found = false;
        curVisit.clear();
		for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (board[i][j] == 'X' || visit[i][j])
				continue;
			else
			{
				traverse(board, i, j);
				if (!found)
				{
					for (vector<Pos>::iterator it = curVisit.begin(); it != curVisit.end(); it++)
					{
						board[it->row][it->col] = 'X';
					}
				}
				found = false;
				curVisit.clear();
			}
		}
	}
	void traverse(vector<vector<char> > & board, int row, int col)
	{
		int rows = board.size() - 1;
		int cols = board[0].size() - 1;
		if (row == 0 || row == rows || col == 0 || col == cols)
			found = true;
		curVisit.push_back(Pos(row, col));
		visit[row][col] = true;
		for (int i = -1; i < 2; i += 2)
		for (int j = -1; j < 2; j += 2)
		{
			if (IsVaild(board, row + i, col + j) && !visit[row + i][col + j])
			{
				traverse(board, row + i, col + j);
			}
		}
	}

	bool IsVaild(vector<vector<char> > & board, int row, int col)
	{
		int rows = board.size() - 1;
		int cols = board[0].size() - 1;
		if (row <0 || row > rows || col < 0 || col > cols)
			return false;
		else if (board[row][col] == 'X')
			return false;
		else
			return true;
	}
};