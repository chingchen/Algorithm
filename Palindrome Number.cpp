/*
Determine whether an integer is a palindrome. Do this without extra space.
*/
class Solution {
public:
    bool isPalindrome(int i) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		long long int x = i;
		if (x < 0)
			return false;
		int digits = -1;
		int tmp = x;
		while (tmp)
		{
			tmp = tmp / 10;
			digits += 1;
		}
		for (int i = 0; i <= digits / 2; i++)
		{
			if (GetDigit(x, i) != GetDigit(x, digits - i))
				return false;
		}
		return true;
	}

	int GetDigit(int x, int nth)
	{
		x = x % ((int)pow(10, nth + 1));
		return x / pow(10, nth);
	}
};