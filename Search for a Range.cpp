/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> ret;
		int start = 0, end = n - 1;
		int mid;
		while (start <= end)
		{
			mid = (start + end) / 2;
			if (A[mid] == target)
				break;
			else if (A[mid] > target)
				--end;
			else
				++start;
		}
		if (start <= end)
		{
			start = 0;
			int high = mid;
			int low;
			while (start <= high)
			{
				int tmp = (start + high) / 2;
				if (tmp != 0)
				{
					if (A[tmp] == target && A[tmp - 1] < target)
					{
						low = tmp;
						break;
					}
					else if (A[tmp] < target)
						++start;
					else
					{
						--high;
					}
				}
				else
				{
					if (A[0] == target)
						low = 0;
					else
						low = 1;
					break;
				}
			}

			start = mid;
			high = n - 1;
			int up;
			while (start <= high)
			{
				int tmp = (start + high) / 2;
				if (tmp != n - 1)
				{
					if (A[tmp] == target && A[tmp + 1] > target)
					{
						up = tmp;
						break;
					}
					else if (A[tmp] > target)						
					    --high;
					else
					{
						++start;
					}
				}
				else
				{
					if (A[n - 1] == target)
						up = n - 1;
					else
						low = n - 2;
					break;
				}
			}

			ret.push_back(low);
			ret.push_back(up);

		}
		else
		{
			ret.push_back(-1);
			ret.push_back(-1);
		}
		return ret;
	}
};