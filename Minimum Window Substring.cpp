/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

class Solution {
public:
    string minWindow(string S, string T) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int tHash[257] = { 0 };
		int sHash[257] = { 0 };
		int sLen = S.length();
		int tLen = T.length();
		for (int i = 0; i < tLen; i++)
		{
			tHash[T[i]] += 1;
		}
		int finds = 0;
		int end = 0;
		for (; end < sLen; end++)
		{
			if (tHash[S[end]] != 0)
			{
				sHash[S[end]]++;
				if (sHash[S[end]] <= tHash[S[end]])
					finds++;
			}
			if (finds == tLen)
				break;
		}
		if (finds != tLen)
			return "";
		int minWindow = end + 1;
		int minStart = 0;
		int minEnd = end;
		int start = 1;
		while (start <= end)
		{
			if (tHash[S[start - 1]] != 0)
			{
				sHash[S[start - 1]] --;
				if (sHash[S[start - 1]] < tHash[S[start - 1]])
					finds--;
			}
			if (finds != tLen)
			while (++end < sLen)
			{
				sHash[S[end]] ++;
				if (S[end] == S[start - 1])
				{
					finds++;
					break;
				}			
			}
			if (end == sLen && finds != tLen)
				break;
			if (end - start + 1 < minWindow)
			{
				minWindow = end - start + 1;
				minStart = start;
				minEnd = end;
			}
			start++;
		}
		string res = S.substr(minStart, minEnd - minStart + 1);
		return res;
	}
};
