/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

class Solution {
#define LEVELSEPARATOR  -1
public:
	int jump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (n == 1)
			return 0;
		if (A[0] >= n - 1)
			return 1;
		int level = -1;
		int count = -1;
		queue<int> que;
		que.push(A[0]);
		que.push(LEVELSEPARATOR);
		int lastIndex = 0;
		while (!que.empty())
		{
			int cur = que.front();
			que.pop();
			if (cur == LEVELSEPARATOR)
			{
				++level;
				que.push(LEVELSEPARATOR);
				continue;
			}
			else
				count++;
			if (cur + count >= n - 1)
				return level + 2;

			int k = lastIndex + 1;
			for (; k <= cur + count; k++)
			{
				que.push(A[k]);
			}
			if (cur + count > lastIndex)
				lastIndex = cur + count;
		}
	}
};
