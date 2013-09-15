/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sRow = 0 , eRow= matrix.size() - 1;
	int sCol = 0 , eCol = matrix[0].size() - 1;
	while( sRow <= eRow && sCol <= eCol)
	{
		for(int i = sCol ; i < eCol; i++)
		{
			swap(matrix[sRow][i], matrix[sRow + i - sCol][eCol]);
		}
		for(int i = eCol;i > sCol ;i--)
		{
			swap(matrix[sRow][sCol + eCol -i], matrix[eRow][i]);
		}
		for(int i = eRow;i> sRow ;i--)
		{
			swap(matrix[sRow][sCol + eRow -i ] , matrix[i][sCol]));
		}
		++sRow;
		--eRow;
		++sCol;
		--eCol;
	}
    }
};