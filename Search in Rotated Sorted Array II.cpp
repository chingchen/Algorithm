/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
class Solution {
	bool search(int A[], int start, int end, int target)
	{
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (A[mid] == target)
				return true;
			if (A[mid] > target)
				end--;
			if (A[mid] < target)
				start++;
		}
		return false;
	}
public:
	bool search(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int low = 0, high = n - 1;
		if (high == low)
			return A[low] == target ? true : false;
		int rotateIndex = 0;
		--high;
		while (low <= high)
		{
			int mid = low + (high - low) / 2;
			if (A[mid] > A[mid + 1] && A[mid] >= A[0])
			{
				rotateIndex = mid;
				break;
			}				
			if (A[mid] < A[0])
				high--;
			if (A[mid] >= A[0])
				low++;
		}
		if (low > high)
		{
			return	search(A, 0, n - 1, target);
		}
		if (target <= A[n - 1] && target >= A[rotateIndex + 1])
		{
			return search(A, rotateIndex + 1, n - 1, target);
		}
		else if (target >= A[0] && target <= A[rotateIndex])
		{
			return search(A, 0, rotateIndex, target);
		}
		else
			return false;
	}
};