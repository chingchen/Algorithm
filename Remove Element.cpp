/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int removed = 0;
    int begin = 0, end = n-1;
	while(begin <= end)
	{
		while(begin <= end && A[begin]!= elem) begin++;
		while(begin <= end && A[end] == elem) end--;
		if(begin <= end)
			swap(A[begin],A[end]);
	}
	return begin;
    }
};