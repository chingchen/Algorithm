/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ¡­

1 is read off as ¡°one 1¡å or 11.
11 is read off as ¡°two 1s¡± or 21.
21 is read off as ¡°one 2, then one 1¡å or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string
*/

class Solution {
public:
	string countAndSay(int n) 
	{
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		string from;
		int start = res.size()-1;
		if( start == -1)
		{
			res.push_back("1");
			start = 0;
		}
		if(n <= start)
			return res[n-1];		
		for( int i = start ; i < n ; i++)
		{
			from = res[res.size()-1];
			string ret;
			int len = res[i].size();
			bool last = false;
			int end =0; int j=0 ;
			for( ; end < len ;)
			{
				end = from.find_first_not_of(from[j],j);
				if( end == string::npos)
				{
					end = from.size();
				}
				char temp[10];
				sprintf(temp,"%d",end-j);
				ret.append(temp);
				ret.append(string(1,from[j]));		
				j = end;
			}
			res.push_back(ret);
		}
		return res[n-1];
	}

private :
	vector<string> res;

};