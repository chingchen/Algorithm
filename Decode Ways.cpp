/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

¡®A¡¯ -> 1
¡®B¡¯ -> 2
¡­
¡®Z¡¯ -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message ¡°12¡å, it could be decoded as ¡°AB¡± (1 2) or ¡°L¡± (12).

The number of ways decoding ¡°12¡å is 2.
*/

class Solution {
public:
	int numDecodings(string s)
	{
		if(s.size() == 0)
			return 0;
		else
			return numDecoding(s);
	}
private:
	int numDecoding(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(s.size() == 0)
			return 1;
		if(record.find(s) != record.end())
			return record[s];
		if( CanDecod(s,1))
		{
			int one = numDecoding(s.substr(1));
			int two = 0;
			if( CanDecod(s,2))
				two = numDecoding(s.substr(2));
			return record[s] = one + two;
		}  
		else 
			return 0 ;
	}
private:
	bool CanDecod(const string & s , int num)
	{
		if(s.size() == 0 || num > s.size())
			return false;
		int n = atoi(s.substr(0,num).c_str());
		if ( n >26 || n <1 )
			return false;
		else
			return true;
	}
	map<string,int> record;
};