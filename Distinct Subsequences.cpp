/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of 
the characters without disturbing the relative positions of the remaining characters.
(ie, ¡°ACE¡± is a subsequence of ¡°ABCDE¡± while ¡°AEC¡± is not).

Here is an example:
S = ¡°rabbbit¡±, T = ¡°rabbit¡±
*/

class Solution {
public:
	int numDistinct(string S, string T) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		return FindNum(S,T);

	}

private:
	map<string ,map<string,int> > record;
	int  FindNum(string & s, string & t)
	{
		if(record.find(t) != record.end() && record[t].find(s) != record[t].end())
			return record[t][s];

		int ret = 0;
		for( size_t i = 0 ; i < s.size();)
		{
			size_t pos ;
			if(( pos = s.find(t[0],i)) != string::npos)
			{
				if(t.size() == 1)
					ret += 1;
				else
				{
					if(pos == s.size())
					{
						if(record.find(t) == record.end())
						{
							map<string,int> m;
							m[s] = ret;
							record[t] = m;
						}
						else
							record[t][s]= ret;
						return ret;
					}
					string s1= s.substr(pos+1);
					string t1= t.substr(1);
					ret += FindNum(s1,t1);
				}
				i = pos+1;
			}
			else
			{
				if(record.find(t) == record.end())
				{
					map<string,int> m;
					m[s] = ret;
					record[t] = m;
				}
				else
					record[t][s]= ret;
				return ret;
			}

		}
		if(record.find(t) == record.end())
		{
			map<string,int> m;
			m[s] = ret;
			record[t] = m;
		}
		else
			record[t][s]= ret;
		return ret;
	}
};