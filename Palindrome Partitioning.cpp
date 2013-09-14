/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    int len = s.length();
	if( len == 0) return vector<vector<string> >();
	vector<string> path;
	vector<vector<string> >allPath;
        partition(s,0,len-1,path,allPath);
	return allPath;
    }
	void partition(string str, int s, int e, vector<string> &path, vector<vector<string> > &allPath)
	{
		if(s > e)
		{
			allPath.push_back(path);
			return ;
		}else
		{
			for(int i = s; i<=e;i++)
			{
				string subStr = str.substr(s, i-s +1);
				if(IsPartition(subStr))
				{
					path.push_back(subStr);
					partition(str, i+1,e,path,allPath);
					path.pop_back();
				}
			}
		}
	}

	bool IsPartition(string str)
	{
		int len = str.length();
		for(int i =0 ;i <= (len-1)/2;i++)
		{
			if(str[i] != str[len-1 -i])
				return false;
		}
		return true;
	}
};
