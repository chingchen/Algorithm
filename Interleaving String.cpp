/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
    vector<vector<int> > mem;
public:
    bool isInterleave(string s1, string s2, string s3)
	{
		int len2 = s2.length();
		int len1 = s1.length();
		mem.clear();
		mem.resize(len1 + 1);
		for (int i = 0; i <= len1; i++)
		{
			mem[i].resize(len2 + 1, -1);
		}
		return 	interleave(s1, s2, s3);
	}
	bool interleave(string s1, string s2, string s3) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function   
		int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
		if (len3 == 0)
			return len1 == 0 && len2 == 0;
		if (mem[len1][len2] != -1)
			return mem[len1][len2];
		if (s1.length() == 0)
		{
			return mem[len1][len2] = (s3 == s2);
		}
		if (s2.length() == 0)
		{
			return mem[len1][len2] = (s3 == s1);
		}
		bool matched = false;
		if (s3[0] == s1[0])
			matched = interleave(s1.substr(1), s2, s3.substr(1));
		if (matched)
			return mem[len1][len2] = true;
		else
		{
			if (s3[0] == s2[0])
				matched = interleave(s1, s2.substr(1), s3.substr(1));
			else
				return mem[len1][len2] = false;
		}
		return mem[len1][len2] = matched;
	}
};