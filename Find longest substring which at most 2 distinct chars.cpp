#include <iostream>
#include <string>
using namespace std;


string LongestSubStrWith2RepeatedChar(string input)
{
	char firstChar = input[0];
	int firstCharMostLeft = 0;
	char secondChar = input[0];
	int secondCharMostLeft = 0;

	int start = 0 ;
	string maxStr = "";
	int length = input.length();
	if(length == 1) return input;

	for(int i = 1 ; i< length ; i++)
	{
		if(input[i] != firstChar && input[i] != secondChar)
		{
			if( i - start > maxStr.length())
			{
				maxStr = input.substr(start,i-start);
			}

			if(firstChar == input[i-1])
			{
				start = firstCharMostLeft;
				secondChar = input[i];
				secondCharMostLeft = i;
			}
			if(secondChar == input[i-1])
			{
				start = secondCharMostLeft;
				firstChar = input[i];
				firstCharMostLeft = i;
			}
		}
		else
		{
			if(input[i] != input[i-1])
			{
				if(input[i] == firstChar)
				{
					firstCharMostLeft = i;
				}
				else
				{
					secondCharMostLeft = i;
				}
			}
			if( i == length-1)
				if( i - start > maxStr.length())
				{
					maxStr = input.substr(start,i-start + 1);
				}
		}
	}

	return maxStr;
}



int main()
{
	string input= "aaabbbcccccaaaabbbbcccccddssass";
	string ret = LongestSubStrWith2RepeatedChar(input);
	cout << ret;
}