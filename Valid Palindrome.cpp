/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len = s.length();
		if (len == 0)
			return true;
		int start = 0, end = len - 1;
		while (start < end)
		{
			while (start <= end && !IsAlphanumeric(s[start]))
				start++;
			if (start >= end)
				return true;
			while (start <= end && !IsAlphanumeric(s[end]))
				end--;
			if (s[start] != s[end])
			{
				int big = max(s[start], s[end]);
				int small = min(s[start], s[end]);
				if (big - small != 32)
					return false;
			}
			start++;
			end--;
		}
		return true;
	}

	bool IsAlphanumeric(char c)
	{
		if (c >= '0' && c <= '9')
			return true;
		if (c >= 'a' && c <= 'z')
			return true;
		if (c >= 'A' && c <= 'Z')
			return true;
		return false;
	}
};