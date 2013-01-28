class Solution {
public:
	bool canJump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int farest =  A[0];

		for( int i = 0 ; i < n ; i++)
		{
			if( i <= farest)
			{
				if( i + A[i] >= n-1)
					return true;
				if( i + A[i] > farest)
					farest = i + A[i];
			}
			else
				return false;
		}
		return true;
	}
};