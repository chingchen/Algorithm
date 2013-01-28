class Solution {
public:
	bool isPalindrome(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(s.size() ==1 || s.size() == 0)
			return true;
		unsigned start = 0 ,end = s.size() -1;
		while(start <= end)
		{
			while(s[start] > 'z' || ( s[start] >'Z' &&  s[start] < 'a') || (s[start] < 'A' && s[start] >'9') || s[start]<'0')
			{
				start ++;
				if( start >= end) 
					return true;
			}
			while(s[end] > 'z' || ( s[end] >'Z' &&  s[end] < 'a') || (s[end] < 'A' && s[end] >'9') || s[end]<'0')
			{
				end--;
				if( start > end) 
					return false;
			}

			if(start == end)
				return true;

			int d1, d2;
			if(s[start]>='a') d1 = s[start]-'a';
			else   			  d1 = s[start]-'A';
			if(s[end]>='a')   d2 = s[end]-'a';
			else			  d2 = s[end]-'A';

			if(d1!=d2)
				return false;
			start++;
			end--;
		}
		return true;
	}
};