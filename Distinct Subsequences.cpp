/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of 
the characters without disturbing the relative positions of the remaining characters.
(ie, ¡°ACE¡± is a subsequence of ¡°ABCDE¡± while ¡°AEC¡± is not).

Here is an example:
S = ¡°rabbbit¡±, T = ¡°rabbit¡±
*/

class Solution 
{

    map<string,map<string,int> > cache;

public:
   
	int numDistinct(string S, string T) 
	{

		cache.clear();
		return distinct(S,T);
	}

	int distinct(string s, string t)
	{
		int res = 0;
		if(cache.find(s) != cache.end() && cache[s].find(t) != cache[s].end())
		{
			return cache[s][t];
		}
		if(t.length() == 0 )
			return 1;
		if(s.length() ==  0)
			return 0;
		if(s[0] == t[0])
		{
			res +=  distinct(s.substr(1),t.substr(1));
			
		}
		size_t  pos = s.find(t[0],1);
		if( pos != string::npos)
		{
			res += distinct(s.substr(pos), t);
		}		
		
		return cache[s][t] = res;		
	}
};