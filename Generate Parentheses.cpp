/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return GetAllParenthesis(n);
    }

private:
    vector<string> GetAllParenthesis(int n)
    {
        vector<string> ret; 
        if( n == 1)
        {
            ret.push_back("()");
        }
        else if( n == 0)
        {
            ret.push_back("");
        }
        else
        {
            for( int i = 0 ;i < n ;i++ )
            {
                vector<string > first= GetAllParenthesis(i);

                vector<string> second = GetAllParenthesis(n-i-1);

                for( int i = 0 ;i < first.size() ; i++)
                {
                    for( int j = 0; j< second.size(); j++)
                    {
                        string temp = "(" + first[i] + ")" + second[j];
                        ret.push_back(temp);
                    }
                }
            }

        }

        vector<string>::iterator it = unique(ret.begin(),ret.end());
        ret.erase(it,ret.end());
        return ret;

    }
};