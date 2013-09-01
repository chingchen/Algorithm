/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.
*/



class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		map<char, int> hash;
		int maxLen = 0;
		int start = 0;
		int strLen = s.length();
		for (int i = 0; i < strLen; i++)
		{
			if (hash.find(s[i]) == hash.end() || hash[s[i]] < start)
			{
				hash[s[i]] = i;
			}
			else
			{
				int repeateIndex =  hash[s[i]];
				//excludsive
				maxLen = max(i - start, maxLen);
				start = repeateIndex + 1;
				hash[s[i]] = i;
			}
		}
		//includsive
		maxLen = max(strLen - 1 - start + 1, maxLen);

		return maxLen;
	}
};