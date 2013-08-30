/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    if(*s == NULL)
	{
		return 0;
	}
    int start = -1 , end = 0;
    int len = 0;
	while(*(end +  s) != NULL)
	{
		if(*(end+s) == ' ')
		{			
            if( end - start -1 >0)
                 len = end -start -1;
            start = end; 
		}
		end++;
	}
    if(end - start -1 == 0)
        return len;
	else
        return end - start -1;	
    }
};