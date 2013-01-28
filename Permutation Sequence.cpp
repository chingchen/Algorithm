class Solution {
public:
	string getPermutation(int n, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int ary[9]={0};
		for( int i = 1; i <= n ; i++)
			ary[i-1] = i;
		int start =1;

		for(int i = start ; i < k ; i++)
		{
			NextPermutation(ary,n);
		}
		string ret;
		for( int i = 0 ; i < n ;i++)
		{
			ret.push_back(ary[i]+'0'); 
		}
		return ret;
	}

private:
	void NextPermutation(int * s,int size)
	{
		int len = size;
		size_t hightest = len-1 ;
		for(int i = len -1; i > -1; i--)
		{
			if(s[i] < s[hightest])
			{
				sort(s+i+1,s+size);
				int* firstBig =	upper_bound(s+i+1,s+size,s[i]);
				int tmp = s[i];
				s[i]=*firstBig;
				*firstBig = tmp;
				return ;
			}
			else
			{
				if(s[i] > s[hightest])
					hightest = i;
			}
		}
	}
};