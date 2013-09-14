/*
Given a number represented as an array of digits, plus one to the number.
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int carry = 0 ;
    int size = digits.size() - 1;
	if( digits[size] + 1 > 9 )
	{
		carry = 1;		
	}
	digits[size] = digits[size] + 1 - carry * 10;
	--size;
	while( carry != 0 || size >= 0 )
	{
		if(size== -1)
        {
			digits.insert(digits.begin(),carry);
            carry = 0;	
        }
		else
		{
            
			if( digits[size] + carry > 9 )
			{				
                digits[size] = (digits[size] + carry) %10;
                carry = 1;	
			}
            else
            {
                digits[size] += carry;
                carry = 0;                
            }
		
		}
		--size;
	} 
	return digits;
    }
};