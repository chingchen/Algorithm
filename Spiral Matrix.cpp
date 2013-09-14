/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &v) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    vector<int> ret;
    if( v.size() == 0)
        return ret;
    int sRow = 0, eRow = v.size() -1;
	int sCol = 0, eCol = v[0].size() -1;
	while( sRow <= eRow && sCol <= eCol)
	{
		for(int i = sCol ; i <= eCol ; i++)
			ret.push_back( v[sRow][i]);
		sRow ++;

		for( int i = sRow ; i <= eRow ;i++)
			ret.push_back(v[i][eCol]);
		eCol --;
		
        if(sRow <= eRow)
        {
		    for(int i = eCol ;i >= sCol ;i--)
		    	ret.push_back(v[eRow][i]);
	    	eRow--;    	
        }
        
        if(sCol <= eCol)
        {
		    for(int i = eRow ; i>= sRow ; i--)
		    	ret.push_back(v[i][sCol]);
		    sCol++;	
        }			
	}
	return ret;
    
    }
};