class Solution {
	struct Position
	{
		Position(int row, int col){r = row; c = col;}
		int r;
		int c;
		bool operator == (const Position p)const { return p.c== c && p.r == r; }
		bool operator < (const Position p )const { return p.r < r || p.c < c; }
	};
public:
	int minPathSum(vector<vector<int> > &grid) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		Init(grid);

		Position start(0,0);
		unsigned startSum = grid[0][0];
		GetMinPath(start,grid);
		return GetMinPath(start,grid);
	}

private:	
	int columns;
	int rows;
	unsigned cached[200][200];

	void Init(vector<vector<int> > &grid)
	{
		columns = grid.size();
		rows= grid[0].size();
		memset(cached,0,sizeof(cached));
	}

	bool CanMoveDown(const Position& p)
	{
		return p.r+1 < rows;
	}
	bool CanMoveRight(const Position& p)
	{
		return p.c+1 < columns;
	}

	Position MoveDown( Position p)
	{
		p.r++;
		return p;
	}
	Position MoveRight(Position p)
	{
		p.c++;
		return p;
	}
	
	unsigned GetMinPath(Position p ,const vector<vector<int> > &grid)
	{
		if(cached[p.c][p.r] != 0)
		{
			return cached[p.c][p.r];
		}
		if( p.c == columns -1 && p.r  == rows -1)
		{
			return 	cached[p.c][p.r] =  grid[p.c][p.r];		
		}

		unsigned int ret = -1;

		if( CanMoveDown(p))
		{
			Position down = MoveDown(p);
			unsigned sum1 =  grid[p.c][p.r] + GetMinPath(down,grid);
			ret = sum1;
		}
		if(CanMoveRight(p))
		{
			Position right = MoveRight(p);
			unsigned sum2 =  grid[p.c][p.r] + GetMinPath(right,grid);
			if(sum2 < ret )
				ret = sum2; 
		}
		return cached[p.c][p.r] = ret;
	}
};