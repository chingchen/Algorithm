class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) 
	{
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		for(int i = 0 ; i < 9; i++)
			for(int j = 0 ; j < 9 ;j++)
			{
				if(board[i][j] == '.')
				{
					vector<int> allNums = GetAvailable(board,i,j);
					if(allNums.size() == 0)
						return false;
				}
			}

			//return Solve(board,start);
			return true;
	}
private:	
	
	vector<int> GetAvailable(const vector<vector<char> > &board, int row, int col)
	{
		vector<int> ret;

		bool allNums[9] = {0};
		int allNumsLen = sizeof(allNums)/sizeof(allNums[0]);
		for(int i = 0 ; i < allNumsLen ; i++)
			allNums[i] = true;

		bool records[9] = {0};
		int recordsLen = sizeof(allNums)/sizeof(allNums[0]);
		for(int i = 0 ; i < recordsLen ; i++)
			records[i] = true;

		int cols = board.size();
		for( int i = 0 ; i< cols; i++)
		{
			if(board[i][row] != '.')
			{
				int index = board[i][row]-'1';
				if(records[index] == false)
				{
					return ret;
				}
				allNums[index] = false;
				records[index] = false;
			}
		}

		for(int i = 0 ; i < recordsLen ; i++)
			records[i] = true;

		int rows = board[0].size();
		for( int i = 0 ; i< rows ; i++)
		{
			if(board[col][i] != '.')
			{
				int index =  board[col][i]-'1';
				if(records[index] == false)
				{
					return ret;
				}
				allNums[index] = false;
				records[index] = false;
			}
		}

		for(int i = 0 ; i < recordsLen ; i++)
			records[i] = true;

		int chunkCol = col/3;
		int chunkRow = row/3;
		for( int i = 0 ; i< 3; i ++)
		{
			for( int j = 0 ; j< 3; j++)
			{
				if(board[j + chunkCol*3][i + chunkRow*3] !='.')
				{
					int index = board[j + chunkCol*3][i + chunkRow*3] - '1';
					if(records[index] == false)
					{
						return ret;
					}
					allNums[index] = false;
					records[index] = false;
				}
			}
		}

		for( int i = 0 ; i < allNumsLen ;i++)
			if(allNums[i])
				ret.push_back(i+1);
		return ret;
	}
};