/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

class Solution {
public:
    string simplifyPath(string path) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		stack<string> paths;
		paths.push("/");
		int start = 0;
		int len = path.length();
		while (start != string::npos)
		{
			if (start + 1 == len)
				break;
			int end = path.find("/", start + 1);
			string op = path.substr(start + 1, end - start - 1);
			if (op == "..")
			{
				if (paths.size() != 1)
					paths.pop();
				if (paths.size() != 1)
					paths.pop();
			}
			else if (op == ".")
				;

			else if (op.length() > 0)
			{
				if (paths.top() != "/")
					paths.push("/");
				paths.push(op);
			}
			start = end;
		}
		string ret;
		while (!paths.empty())
		{
			ret.insert(0, paths.top());
			paths.pop();
		}

		return ret;
	}
};