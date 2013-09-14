/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    vector<vector<int> > ret(n , vector<int> (n ,0));
        int lRow = 0 , hRow = n -1, lCol = 0, hCol = n-1;
	int count = 0;
	while(lRow <= hRow && lCol <= hCol)
	{
		for(int i = lCol; i<= hCol ;i++)
			ret[lRow][i] = ++count;
		lRow++;
		for(int i = lRow ;i <= hRow;i++)
			ret[i][hCol] = ++count;
		hCol--;
		if(lRow <= hRow)
		{
			for( int i = hCol ;i >= lCol ;i--)
				ret[hRow][i] = ++count;
			hRow--;
		}
		if(lCol <= hCol)
		{
			for(int i = hRow ;i>= lRow ;i--)
				ret[i][lCol]= ++count;
			lCol++;
		}
	}
	return ret;
    }
};