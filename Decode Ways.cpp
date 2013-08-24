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
map<string, int> caches;
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if( s.length() < 1)
		return 0;
	if(caches.find(s) != caches.end())
	{
		return caches[s];
	}
	if(s[0] == '0')
		return caches[s]= 0;

	if(s.length() > 1)
	{
		if( s[0] == '1' || ( s[0] == '2' && s[1] < '7'))
		{
			int sum1 =  numDecodings(s.substr(1));
			int sum2 = 1;
			if( s.length() > 2)
			{
				sum2 = numDecodings(s.substr(2));
			}
			return sum1 + sum2;
		}
		else
		{
			return caches[s] = numDecodings(s.substr(1));
		}
	}
	return caches[s] = 1;        
    }
};