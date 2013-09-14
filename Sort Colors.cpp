/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/
class Solution {
public:
    void sortColors(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function     
		int redLast = -1, whiteLast = -1 , blueLast = -1;
		for(int i = 0 ; i < n ; i++)
		{
			if(A[i] == 2)
			{
				++blueLast;
				continue;
			}
			if(A[i] == 1)
			{
				A[++whiteLast] = 1;
				if(blueLast < whiteLast)
					blueLast = whiteLast;
				else
					A[++blueLast] = 2;
				continue;
			}
			if(A[i] == 0)
			{
				A[++redLast] = 0;
				if(whiteLast < redLast)
					whiteLast = redLast;
				else
					A[++whiteLast] = 1;
				if(blueLast < whiteLast)
					blueLast = whiteLast;
				else
					A[++blueLast] = 2;
			}		
		}
	}
};

/*
class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rIndex = -1, wIndex = -1, bIndex = -1;
	for( int i = 0; i< n ;i++)
	{
		switch( A[i])
		{
			case 0:
				{
					A[++rIndex] = 0;
					if( wIndex != -1)
					{
						A[++wIndex] = 1;
					}
					if( bIndex != -1)
					{
						A[++bIndex] = 2;
					}
					break;
				}
			case 1:
				{
					if(wIndex == -1)
					{
						wIndex = rIndex;
					}
					A[++wIndex] = 1;
					if( bIndex != -1)
					{
						A[++bIndex] = 2;
					}
					break;
				}
			case 2:
				{
					if( bIndex == -1)
					{
						if(wIndex == -1)
							bIndex = rIndex;
						else
							bIndex = wIndex;
					}	
					A[++bIndex] = 2;
					break;
				}			
		}
	}
    }
};
*/