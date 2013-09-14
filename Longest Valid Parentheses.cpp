/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

class Solution {
public:
	int longestValidParentheses(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int maxLen = 0;
		int len = s.length();
		if (len == 0) return 0;
		stack<int> st;
		vector<int> rec(len, 0);
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '(')
			{
				st.push(i);
			}
			else
			{
				if (!st.empty())
				{
					rec[i] = st.top() + 1;
					int tmp = rec[i] - 2;
					if (tmp >= 0 && rec[tmp] > 0)
						rec[i] = rec[tmp];
					maxLen = max(maxLen, i - rec[i] + 2);
					st.pop();

				}
			}
		}
		return maxLen;
	}
};