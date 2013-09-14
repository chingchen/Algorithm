/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    vector<int> ret;
        int size = L.size();
	if(size == 0)
		return ret;
	int len = L[0].length();
	map<string,int> dics;
	map<string,int> found;
	for(int i = 0 ;i < size;i++)
		dics[L[i]]++;
	for( int i = 0 ;i < S.length() - len * size;i++)
	{
		int j  = 0;
		found.clear();
		for( j = 0 ; j < size ;j++)
		{
			string c = S.substr(j*len + i, len);
			if( dics.find(class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    vector<int> ret;
        int size = L.size();
	if(size == 0)
		return ret;
	int len = L[0].length();
	map<string,int> dics;
	map<string,int> found;
	for(int i = 0 ;i < size;i++)
		dics[L[i]]++;
	for( int i = 0 ;i <= (int)S.length() - len * size;i++)
	{
		int j  = 0;
		found.clear();
		for( j = 0 ; j < size ;j++)
		{
			string c = S.substr(j*len + i, len);
			if( dics.find( c) != dics.end())
			{
				found[c]++;
				if( found[c] > dics[c])
					break;
			}
			else
				break;
		}
		if( j == size)
		{
			ret.push_back(i);
		}
	}
	return ret;
    }
};
				found[c]++;
				if( found[c] > dics[c])
					break;
			}
			else
				break;
		}
		if( j == size)
		{
			ret.push_back(i);
		}
	}
	return ret;
    }
};