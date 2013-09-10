/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
*/
class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(matrix.size() == 0 ) 
			return false;
		columns = matrix.size();
		rows = matrix[0].size();

		int start = 0 ; 
		int end = rows*columns-1;
		while(start <= end)
		{
			int mid = (start + end) / 2;
			int midNum = matrix[mid/rows][mid%rows] ;
			if(midNum == target)
				return true;
			else if( midNum > target)
				end = mid-1;
			else
				start = mid + 1;
		}
		return false;
    }

private:
	int columns;
	int rows;
};

/*
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (matrix.size() == 0)
			return false;
		int row = matrix.size();
		int col = matrix[0].size();
		int cRow = row - 1;
		int cCol = 0;
		while (cCol < col && cRow >= 0)
		{
			int curVal = matrix[cRow][cCol];
			if (curVal == target)
			{
				return true;
			}
			else if (curVal < target)
			{
				int begin = cCol + 1, end = col - 1;
				while (begin <= end)
				{
					int mid = begin + (end - begin) / 2;
					if (matrix[cRow][mid] == target)
					{
						return true;
					}
					else if (matrix[cRow][mid] > target)
						--end;
					else
						++begin;
				}
				cCol = begin;
			}
			else
			{
				int begin = 0, end = cRow - 1;
				while (begin <= end)
				{
					int mid = begin + (end - begin) / 2;
					if (matrix[mid][cCol] == target)
					{
						return true;
					}
					else if (matrix[mid][cCol] > target)
						--end;
					else
						++begin;
				}
				cRow = end;
			}
		}
		return false;
	}
};
*/