/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        return MatchPartial(s,p);
        
    }
    bool Match(const char *text, const char *regexp) 
{
    if( *text == '\0' && *regexp =='\0')
		return true;
    if(*regexp =='\0')
        return false;
	if(*(regexp+1) == '*')
	{
		do{
			if(Match(text,regexp+2))
				return true;
		}while (*text !='\0' && (*regexp == *text++ || *regexp == '.' ));
	}
	if( *text != '\0' && ( *regexp == *text || *regexp == '.'))
		return Match(text+1 , regexp+1);
	return false;
}

bool MatchPartial(const char* text , const char * regexp)
{

   if(Match( text, regexp))
			return true;
	return false;
}
};