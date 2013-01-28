class Solution {
public:
	int jump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		div = 1000000000;;
		queue<int> que ;
		que.push(A[0]);
		que.push(div);
		int level = 0 ,i = 0 ,last = 0;
		while(que.size()!=0)
		{
			if(que.front() == div)
			{
				level++;
				que.pop();
				if(que.size() == 0&& que.front() == div)
					break;
				que.push(div);
			}
			else
			{
				if(i + que.front() >= n-1)
				{
					if( i == n-1)
						return level;
					return  level+1;
				}	
				for(int  k = last+1 ; k <= que.front() + i && k < n; k++)
				{
					que.push(A[k]);
				}
				if( que.front() + i > last)
					last = que.front() + i ;
				que.pop();
				i++;
			}
		}
		return level +1;
	}
private:
	int div;
};