/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
vector<int> cache;
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if( n > cache.capacity())
            cache.resize(n+1,0);
	return climbWays(n);
    }
    int climbWays(int n)
    {
	if( n < 1)
		return 0;
	if( n ==1)
		return 1;
	if( n == 2)
		return 2;
	if( cache[n] != 0)
		return cache[n];
	int one = 0, two =0;
	if( cache[n-1] ==0)
		cache[n-1] = one = climbWays(n -1);
	else
		one = cache[n-1];
	if( cache[n-2] ==0)
		cache[n-2] = two = climbWays(n -2);
	else
		two = cache[n-2];
	return one + two;
    }
};