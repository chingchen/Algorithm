/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
class Solution {
    
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    stack<char> st;
        int len = s.length();
        for(int i = 0 ;i < len; i++)
        {
            char cur = s[i];
            char c  ='\0';
            if( cur == ']' || cur == '}' || cur == ')')
	    {
		if(cur == ']')
			c='[';
		if(cur ==')')
			c='(';
		if(cur=='}')
			c='{';
		if(st.empty() || st.top() != c)
			return false;
        else
            st.pop();
         }
             else
		st.push(cur);
        }
	return st.empty();
    }
};