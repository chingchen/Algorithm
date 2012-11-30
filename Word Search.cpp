/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where “adjacent” cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
["ABCE"],
["SFCS"],
["ADEE"]
]
word = “ABCCED”, -> returns true,
word = “SEE”, -> returns true,
word = “ABCB”, -> returns false
*/

class Solution 
{
public:
	bool exist(vector<vector<char> > &board, string word)
	{
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int width = board[0].size();
		int hight = board.size();

		memset(visited,0,sizeof(visited));

		for( int j = 0 ; j < width; j++)
			for( int i = 0; i < hight ; i++)
			{
				if( board[i][j] == word[0])
				{					
					if(Find( i, j, width,hight,word, board))
						return true;
				}
			}

			return  false;
	}

	bool Find(int i , int j , int width, int hight,  string  word, const vector<vector<char> > &board )
	{
		visited[i][j] = true;
		if( board[i][j] == word[0] && word.size()==1)
			return true;

		for( int k = -1 ;k < 2; k += 1)
			for( int m = -1; m < 2; m += 1)
			{
				if(abs(k+m)!=1)
					continue;
				if(CanVisit(i+k,j+m,width,hight))
				{
					if( board[i][j] == word[0] )
					{
						if (Find(i+k,j+m,width,hight,word.substr(1),board))
							return true;
					}
				}
			}
			visited[i][j] = false;
			return false;
	}

	bool CanVisit(int i , int j, int width, int hight)
	{
		if( i > -1 && i < hight && j > -1 && j< width)
		{
			return ! visited[i][j];
		}
		return false;
	}

private:
	bool visited[1000][1000];
	int size;
};