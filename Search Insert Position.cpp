/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int begin = 0 , end = n -1;
        int foundIndex = -1;
        while(begin <= end)
        {
            int mid = begin + (end - begin)/2;
            if(A[mid] == target)
            {
                foundIndex = mid;
                break;
            }
            else if (A[mid] > target)
                --end;
            else
                ++begin;           
        }
        if(foundIndex == -1)
            return begin;
        else
            return foundIndex;
    }
};