/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    map<string,string> dics;
    bool found = false;
    set<string> target;
    vector<string> ret;
    int len = strs.size();
	for(int i = 0 ;i< len;i++)
	{
		string tmp = strs[i];
		sort(tmp.begin(), tmp.end());
		if(dics.find(tmp) == dics.end())
			dics[tmp]= strs[i];
		else
		{
            found = true;
            target.insert(tmp);
			ret.push_back(strs[i]);
		}
	}
    if(found)
    for(set<string> ::iterator  it = target.begin() ;it != target.end();it++)
        ret.push_back(dics[*it]);
	return ret;
    }
};\