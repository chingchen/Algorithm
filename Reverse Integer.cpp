class Solution {
public:
	int reverse(int x)
	{
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		bool flag = false;
		if(x <0)
		{
			flag = true;
			x = -x;
		}
		if(x < 10)
			return x;
		int first = 0;
		stack<short> stk;
		do{
			first = x%10;
			x = x/10;
		}while(first == 0);

		stk.push(first);
		while( x )
		{
			stk.push(x%10);
			x = x/10;
		}
		int ret = 0;
		int i = 0;
		while(!stk.empty())
		{
			ret += pow(10,i) * stk.top();
			stk.pop();
			i++;
		}
		if( flag) 
			ret = -ret;
		return ret;
	}
};