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