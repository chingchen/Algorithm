/*
Permutation
*/

void permute(vector<string> & res, string input)
{
	if( input.size() == 1)
		res.push_back(input);
	else
	{
		char firstChar = input[0];
		vector<string> afterRes ;
		permute(afterRes, input.substr(1));
		for(int i = 0 ;i < afterRes.size(); i++)
		{
			for( int j = 0 ; j <= afterRes[i].length(); j++)
			{
				string temp = afterRes[i];
				res.push_back(temp.insert(j,1,firstChar));
			}
		}
	}
}

void permute(string s)
{
	vector<string> ret;
	permute(ret,s);
	for( int i = 0 ; i< ret.size(); i++)
	{
		cout << ret[i].c_str() << endl;
	}
}