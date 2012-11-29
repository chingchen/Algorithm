
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
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