class Solution {
public:
	string simplifyPath(string path) 
	{
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(path.length() == 1 ||  path.length() == 0)
			return path;
		stack<string> sStack;
		for( int i =  0 ; i != string::npos ; )
		{
			int start = i ;
			if(path[i] == '/' )
			{
				if(start + 1 < path.length())
					i = path.find_first_not_of('/',start+1);
				else
					break;
				if( i == string::npos)
				{
					break;
				}
				start = i -1;
				i = path.find_first_of('/',i);

				if( start +2 < path.length() && path.substr(start+1,2).compare("..") == 0)
				{
					if(!sStack.empty())
						sStack.pop();
					continue;
				}
				if(start+1 < path.length() &&  path.substr(start+1,1).compare(".") == 0)
				{
					int hiddenEnd ;
					if( i == string::npos)
						hiddenEnd = path.length();
					else
						hiddenEnd = i;
					if(hiddenEnd - start >2)
						sStack.push(path.substr(start,hiddenEnd-start));
					continue;
				}
				if( i == string::npos)
					sStack.push(path.substr(start));
				else
					sStack.push(path.substr(start,i-start));
			}
		}

		if(sStack.empty())
			sStack.push("/");
		string ret = "";
		while(! sStack.empty())
		{
			ret = ret.insert(0,sStack.top());
			sStack.pop();
		}
		return ret;
	}
};