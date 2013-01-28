class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		return PossibleIP(4,s);
	}

private:
	vector<string> PossibleIP(int digit, string s)
	{ 
		vector<string> ret; 
		if( digit < 1 ||
			s.length() < digit * 1 ||
			s.length() > digit * 3 			
			)
			return ret;

		if(digit == 1)
		{
			if( (s[0] > '2' && s.size() > 2)  ||
				(s[0] == '2' && s.size() > 2 && s[1] > '5')||
				(s[0] == '2' && s.size() > 2 && s[1]=='5' && s[2] >'5')
				)
				return ret;
			if(s[0] == '0')
				if(s.size()!=1)
					return ret;
			if( s.size() < 4 )
			{
				ret.push_back(s);
				return ret;
			}
			return ret;
		}

		int maxSteps = s.size() - (digit-1);
		if(maxSteps > 3)
			maxSteps = 3;
		int minSetps = s.size() -(digit-1)*3;
		if(minSetps < 1) 
			minSetps = 1;

		if(s[0]=='0')
		{
			if(maxSteps < 1 || minSetps >1)
				return ret;
			minSetps = maxSteps = 1;
		}
		for( int i = minSetps; i <= maxSteps ;i++)
		{
			if( i+1 > s.length())
				break;
			string temp = s.substr(0,i);
			if( (temp[0] > '2' && temp.size() > 2)  ||
				(temp[0] == '2' && temp.size() > 2 && temp[1] > '5')||
				(temp[0] == '2' && s.size() > 2 && temp[1]=='5' && temp[2] >'5')
				)
				continue;
			vector<string> backPart = PossibleIP(digit-1,s.substr(i));
			if( backPart.size() > 0)
			{
				for( int k = 0; k< backPart.size() ; k++)
				{
					string tmp = s.substr(0,i).append(".").append(backPart[k]);
					ret.push_back(tmp);
				}
			}
		}
		return ret;
	}
};