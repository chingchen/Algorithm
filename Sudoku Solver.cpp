class Solution {
public:
	void solveSudoku(vector<vector<char> > &board) 
	{
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		Position start(0,0,board);
		Solve(board,start);
	}
private:	
	struct Position
	{
		Position(int c, int r, const vector<vector<char> > &board )
		{
			col = c;
			row = r;
			cols = board.size();
			rows = board[0].size();
		}

		Position(int c, int r)
		{
			col = c;
			row = r;
		}

		int col;
		int row;
		int rows;
		int cols;

		bool IsEnd()
		{
			return row == rows ;
		}

		bool MoveNext()
		{
			if(col == cols-1)
			{
				//we reach the end of board
				if( row == rows )
					return false;
				else
				{
					col = 0;
					row = row+1;
                                        //we reach the end of board
					if(row == rows)
						return false;
					return true;
				}
			}
			else
			{
				col += 1; 
				return true;
			}
		}
	};

	bool Solve(vector<vector<char> > &board ,Position p )
	{
		while( board[p.col][p.row] != '.')
		{
			if(!p.MoveNext())
				//finsh the search
				return true;
		}
		vector<int> allNums = GetAvailable(board,p.row,p.col);
		int availLen = allNums.size();
		//if the available number is 0 ,mean this search is not right
		if(availLen == 0)
			return false;
		else
		{
			for(int i = 0 ; i < availLen; i ++)
			{
				board[p.col][p.row] = allNums[i] + '0';

				Position temp =  p;
				temp.MoveNext();

				if( temp.IsEnd())
					return true;
				if(Solve(board,temp))
					return true;
				else
					//reset the search ,if sub search is not right
					board[p.col][p.row] = '.';
			}
			return false;
		}
	}

	vector<int> GetAvailable(const vector<vector<char> > &board, int row, int col)
	{
		vector<int> ret;
		bool allNums[9] = {0};
		int allNumsLen = sizeof(allNums)/sizeof(allNums[0]);
		for(int i = 0 ; i < allNumsLen ; i++)
			allNums[i] = true;
		int cols = board.size();
		for( int i = 0 ; i< cols; i++)
		{
			if(board[i][row] != '.')
			{
				int index = board[i][row]-'1';
				allNums[index] = false;
			}
		}
		int rows = board[0].size();
		for( int i = 0 ; i< rows ; i++)
		{
			if(board[col][i] != '.')
			{
				int index =  board[col][i]-'1';
				allNums[index] = false;
			}
		}

		int chunkCol = col/3;
		int chunkRow = row/3;
		for( int i = 0 ; i< 3; i ++)
		{
			for( int j = 0 ; j< 3; j++)
			{
				if(board[j + chunkCol*3][i + chunkRow*3] !='.')
				{
					int index = board[j + chunkCol*3][i + chunkRow*3] - '1';
					allNums[index] = false;
				}
			}
		}

		for( int i = 0 ; i < allNumsLen ;i++)
			if(allNums[i])
				ret.push_back(i+1);
		return ret;
	}
};