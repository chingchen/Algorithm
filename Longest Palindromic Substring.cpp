/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
    bool rec[1001][1001];
public:
	string longestPalindrome(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len = s.length();
		if (len == 0)
			return "";
		memset(rec, 0, sizeof(rec));
		int start = 0, end = 0;

		for (int i = 0; i < len; i++)
		{
			if (i + 1 < len)
			{
				if (s[i + 1] == s[i])
				{
					rec[i][i + 1] = true;
					start = i;
					end = i + 1;
				}
				else
					rec[i][i + 1] = false;

			}
			rec[i][i] = true;
		}
		for (int i = 3; i <= len; i++)
		{
			for (int j = 0; j <= len - i; j++)
			{
				if (s[j] == s[j + i - 1] && rec[j + 1][j + i - 1 - 1] == true)
				{
					if (i > end - start + 1)
					{
						start = j;
						end = j + i - 1;						
					}
					rec[j][j + i - 1] = true;
				}
			}
		}
		return s.substr(start, end - start + 1);
	}
};