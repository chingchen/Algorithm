class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		return GetCombinations(digits);        
    }
private:
	vector<string> GetCombinations(string digits )
	{
		vector<string> ret; 
		if(digits.length() == 0)
		{
			ret.push_back("");
			return ret;
		}

		if(digits.length() == 1 )
		{
			string currentPossbile= GetString(digits[0]);
			for( int i = 0 ; i < currentPossbile.length(); i++)
			{
				string tmp = "-";
				tmp[0] = currentPossbile[i];			
				ret.push_back(tmp);
			}			
			return ret;
		}
		else
		{
			vector<string>  subs = GetCombinations(digits.substr(1));
			string currentPossbile =   GetString(digits[0]);
			for( int i = 0 ;i < currentPossbile.length(); i ++)
			{
				string tmp = "-";
				tmp[0] = currentPossbile[i];				
				for( int k = 0; k < subs.size(); k++)
				{
					string res = tmp;
					res.append(subs[k]);
					ret.push_back(res);
				}
			}
		}
		return ret;
	}

	string GetString(char c)
	{
		if(c=='7')
			return "pqrs";
		if(c=='8')
			return "tuv";
		if(c =='9')
			return "wxyz";
		
		int index = c-'2';
		char start = 'a' + index * 3;
		string ret ;
		for(int i = 0;i < 3; i++)
			ret.push_back(start+i);
		return ret;
	}
};