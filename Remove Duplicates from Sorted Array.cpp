/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3]
*/


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     if( n == 0)
        return 0;
    int dNums = 0;
    int preNum = A[0];
	int end = 1;
	for( int i = 1;i < n ;i++)
	{
		if(A[i] != preNum)
		{
			A[end++] = A[i];
			preNum = A[i];
		}
	}
	return end;
    }
};
