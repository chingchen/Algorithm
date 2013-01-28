class Solution {
public:
    void sortColors(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function     
		int redLast = -1, whiteLast = -1 , blueLast = -1;
		for(int i = 0 ; i < n ; i++)
		{
			if(A[i] == 2)
			{
				++blueLast;
				continue;
			}
			if(A[i] == 1)
			{
				A[++whiteLast] = 1;
				if(blueLast < whiteLast)
					blueLast = whiteLast;
				else
					A[++blueLast] = 2;
				continue;
			}
			if(A[i] == 0)
			{
				A[++redLast] = 0;
				if(whiteLast < redLast)
					whiteLast = redLast;
				else
					A[++whiteLast] = 1;
				if(blueLast < whiteLast)
					blueLast = whiteLast;
				else
					A[++blueLast] = 2;
			}		
		}
	}
};