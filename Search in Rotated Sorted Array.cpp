/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
    int search(int A[], int start, int end, int target)
    {
		while(start <= end)
		{
			int mid = start + (end-start)/2;
			if(A[mid] == target)
				return mid;
			if(A[mid] > target)
				end--;
			if(A[mid] < target)
				start++;
		}
		return -1;
	}
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    int low = 0 , high = n-1;
    if( high == low ) 
        return A[low] == target? low:-1;
    int rotateIndex = 0;
	while(low <= high -1)
	{
		int mid = low + (high - low)/2;
		if( A[mid] > A[mid+1] && A[mid] >= A[0])
		{
			 rotateIndex  = mid;
			 break;
		}
		if( A[mid] < A[0])
			high--;
		if( A[mid] >= A[0])
			low++;
	}
	if( target <= A[n-1] && target >= A[rotateIndex+1])
	{
		return search(A, rotateIndex+1, n-1,  target);
	}
	else if ( target >= A[0] && target <=A[rotateIndex])
	{
		return search(A,0, rotateIndex, target);
	}
	else
		return -1;
    }
	
};
