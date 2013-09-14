/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    vector<vector<int> > ret;
       if( numRows == 0 ) return ret;
    vector<int> firstRow(1,1);
	ret.push_back(firstRow);
    for(int i = 1 ;i < numRows;i++)
	{
		vector<int> row;
		for(int j = 0 ;j <= i;j++)
		{			
			if(j == 0 || j == i)
			{
				row.push_back(1);
			}
			else
			{
				row.push_back(ret[i-1 ][j-1] + ret[i-1 ][j]);
			}
		}
		ret.push_back(row);
	}
	return ret;
    }
};