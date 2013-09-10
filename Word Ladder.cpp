/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dic) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( start == end )
            return 0 ;
        int level = 1;
        unordered_set<string> visited;
        queue<string> que;
        que.push(start);
	que.push("");
	visited.insert(start);
        while(!que.empty())
        {
            string cur = que.front();
	    if(cur == "")
            {
		level++;
		que.pop();
		if(!que.empty())
			que.push("");
		continue;
	    }
	    else if(cur == end)
	    {
		return level;
        }
	    else
	    {
		for(int i = 0 ; i< end.length() ;i++)
		{
			for(char c = 'a' ; c<='z';c++)
			{
				string tmp = cur;
				tmp[i] = c;
				if(dic.find(tmp) != dic.end())
				{
					if(visited.find(tmp) == visited.end())
					{
						visited.insert(tmp);
						que.push(tmp);
					}
				}
			}
		}
		que.pop();
	    }
        }
	return 0;
    }
};