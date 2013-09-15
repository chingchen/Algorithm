/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    int curA = m-1;
	int curB = n-1;
    for(int i = m + n -1 ;i >= 0 ;i--)
	{
		if(curA >= 0 && curB >= 0)
		{
			if( A[curA] > B[curB])
				A[i]= A[curA--];
			else
				A[i]= B[curB--];
			
		}
		else if ( curA >= 0)
		{
			A[i]=A[curA--];
		}
		else 
			A[i]=B[curB--];
	}
    }
};