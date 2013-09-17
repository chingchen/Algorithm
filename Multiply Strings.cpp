/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = num1.length();
	int len2 = num2.length();
	vector<string> addStrings;
	for(int i = len2-1; i>=0 ; i--)
	{
		int carry = 0;
		vector<int> digits;
		for(int j = len1-1 ; j >= 0 ;j--)
		{
			int n2 = num2[i]-'0';
			int n1 = num1[j]-'0';
			int cur = n1*n2 + carry;
			digits.push_back(cur%10);
			carry = cur /10;									
		}
		if( carry > 0)
			digits.push_back(carry);
		int offside = len2-1 - i;
		int curLen = digits.size() + offside;
		string curResult(curLen,'0');
		for(int k = digits.size()-1; k >= 0;k--)
		{
			curResult[digits.size()-1 - k] = digits[k];
		}
		addStrings.push_back(curResult);		
	}
	int nth = 0;
	int carry = 0;
	string ret = "";
	while(true)
	{
		int curNum = 0;
		bool flag = false;
		for(int j = 0 ;j < addStrings.size();j++)
		{
			if(addStrings[j].length() - 1 >= nth )
			{
				curNum += addStrings[nth] -'0';
				flag = true;
			}								
		}
		if( flag || carry > 0)
		{
			ret.push_back(curNum%10);
			carry = curNum/10;
		}
		else
		{
			break;
		}
	}
	reverse( ret.begin(), ret.end());
	return ret;	
    }
};
