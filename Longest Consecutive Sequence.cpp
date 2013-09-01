/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    set<int> hash;
	int maxLen = 0;
    	for( int i = 0 ;i < num.size() ;i++)
	{
		hash.insert(num[i]);
	}
	for( int i = 0 ;i < num.size(); i++)
	{
		int low = num[i];
		int count = 0;
		while(hash.find(low )!= hash.end())
		{
			count ++;
			hash.erase(low);
			low--;
		}
		int high = num[i]+1;
		while(hash.find(high) != hash.end())
		{
			count++;
			hash.erase(high);
			high++;
		}
		maxLen = max(maxLen , count);
	}
	return maxLen;
    }
};