class Solution {
public:
    int longestValidParentheses(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int max = 0;
		int currentMax = 0;
		stack<Item> pStack;
		for( int i = 0; i < s.length();i++)
		{
			if(pStack.size() > 0)
			{
				if(IsPair(pStack.top().c,s[i]))
				{
					Item tmp = pStack.top();
					if(tmp.used == false)
					{
						tmp.t += 2;
						tmp.used = true;
						pStack.pop();
					}
					else
					{
						currentMax = tmp.t;
						if(currentMax > max)
							max = currentMax;
						pStack.pop();
						continue;
					}
					while(pStack.size() > 0 && pStack.top().c =='(')
					{
						tmp.t += pStack.top().t;
						if(pStack.top().used == false)
						{
							tmp.used = false;
							pStack.pop();
							break;
						}
						pStack.pop();
					}
					pStack.push(tmp);
				}
				else
				{
					if(s[i] == ')')
					{
						pStack.pop();
					}
					pStack.push(s[i]);
				}
			}
			else
			{
				pStack.push(s[i]);
			}		
		}
		currentMax = 0;
		while( pStack.size() > 0)
		{
			Item tmp = pStack.top();
			if(tmp.t > 0)
			{
				currentMax += tmp.t;
				if(currentMax > max)
					max = currentMax;
				if( tmp.used == false)
					currentMax = 0;
			}
			else 
			{				
				currentMax = 0;
			}
			pStack.pop();
		}
		return max;
	}

private:
	struct  Item
	{
		Item(char s)
		{
			c = s;
			t= 0;
			used = false;
		}
		bool used ;
		char c;
		int t;
	};

private:
	bool IsPair(char first, char second)
	{
		if(first == '(')
		{
			if(second == ')')
				return true;
			else 
				return false;
		}
		return false;
	}
};