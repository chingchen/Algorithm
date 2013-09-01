/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxSum = A[0];
        int preMax = A[0];
        for(int i = 1; i < n ; i++)
        {
            if(preMax > 0)
            {
                preMax = A[i] + preMax;
            }
            else
            {
                preMax = A[i];
            }
            maxSum = max(maxSum, preMax);
        }
        return maxSum;
    }
};