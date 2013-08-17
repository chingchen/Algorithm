/*Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".*/

class Solution {
public:
	string addBinary(string a, string b) 
	{
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		string res="";
		int carry = 0;
		int lenA = a.length(), lenB = b.length();
		while( lenA > 0 || lenB > 0 ||  carry > 0)
		{
			--lenA ;
			--lenB ;
			int aBit , bBit ;
			if(lenA < 0 )
			{
				aBit = 0;
			}else
			{
				aBit = a[lenA] - '0';
			}

			if(lenB < 0 ){
				bBit = 0;
			}else{
				bBit = b[lenB] - '0';
			}

			if(aBit + bBit + carry > 1)
			{				
				res.push_back( aBit + bBit + carry -2 + '0');
				carry = 1;
			}
			else
			{				
				res.push_back( aBit + bBit + carry + '0');
				carry = 0;
			}
		}
		int lenRes = res.length()-1;
		for(int i = 0 ;i <= lenRes/2 ;i++)
		{
			swap(res[i] ,res[lenRes - i ]);
		}
		return res;
	} 
};