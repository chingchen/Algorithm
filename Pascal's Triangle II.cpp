/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    vector<int> rows[2];
    rows[0].resize(rowIndex+1 , 0);
    rows[1].resize(rowIndex+1,0);
    int cur = 0 ;
	rows[cur][0]=1;
	for(int i = 1 ;i <rowIndex + 1;i++)
	{
        cur = (cur+1)%2;
		for( int j = 0 ; j <= i ;j++)
		{
			if( j == 0 || j == i)
			{
				rows[cur][j] = 1;
			}
			else
			{
				rows[cur][j] = rows[(cur+1)%2][j-1] + rows[(cur+1)%2][j];
			}
		}
	}
	return rows[cur];
    }
};