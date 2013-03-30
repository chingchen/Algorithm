class Solution {
public:
	int minCut(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len = s.length();
		pairArray.clear();
		pairArray.resize(s.length());
		for(int i = 0;i <len ;i++)
		{
			pairArray[i].resize(len);
		}
		storSteps.clear();

		return FindMin(s,0,s.length()-1);
	}

private:
	int FindMin(const string & str,int start, int end)
	{
		if(storSteps.find(str.substr(start,end)) != storSteps.end())
		{
			return storSteps[str.substr(start,end)];
		}

		if( str.length() == 1 )
			return 0;

		int curMinCuts = str.length();

		if(IsPalindrome(str,start,end) == 1)
		{
			curMinCuts =0;
		}
		else
		{
			for( int j = start; j <= end; j++)
			{
				if(IsPalindrome(str,start,j) == 1)
				{
					int hereCuts=0;
					if(j!=end)
					{
						hereCuts = 1 + FindMin(str,j+1,end);
					}
					else
					{
						hereCuts= 0;
					}
					if(hereCuts < curMinCuts)
						curMinCuts = hereCuts;
				}
			}
		}
		return	storSteps[str.substr(start,end)] = curMinCuts;
	}

	int IsPalindrome(const string & s, int start, int end )
	{
		if(end-start<3 )
		{
			return pairArray[start][end] = (s[start]==s[end]?1:-1);
		}
		if(s[start] != s[end])
		{
			return pairArray[start][end] = -1;
		}
		else
		{
			if(pairArray[start+1][end-1] == 1)
			{
				return pairArray[start][end] = 1;
			}
			else if(pairArray[start+1][end-1] == -1)
			{
				return pairArray[start][end] = -1;
			}
			else
			{
				return pairArray[start][end]= IsPalindrome(s,start+1,end-1);
			}
		}
	}

	vector<vector<short>> pairArray;
	map<string,int>  storSteps;
};