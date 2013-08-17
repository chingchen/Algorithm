/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/


class Solution {

public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = prices.size();
        if( len == 0 ||len == 1)
            return 0;
         
        int currentMax = 0;
        int minPrice = prices[0];
        vector<int> leftMax;
        for( int i = 0 ;i < len ;i++)
        {
             if( prices[i] < minPrice )
    		 {
				 minPrice = prices[i];
			 }
             else
             {
                 currentMax = max((prices[i] - minPrice),currentMax);                 
             }
			 leftMax.push_back(currentMax);
        }
        
        currentMax = 0;
        int maxPrice = prices[len-1];
        vector<int> rightMax(len,0);
        for ( int i = len -1 ;i > -1 ;i--)
        {
            if( prices[i] > maxPrice)
                maxPrice = prices[i];
            else
            {
                currentMax = max((maxPrice - prices[i] ),currentMax);                
            }
			rightMax[i]=( currentMax );
        }
        
        int res = 0;
        for( int i = 0 ;i < len;i++)
        {
            res = max( res, leftMax[i] + rightMax[i]);
        }
        return res;
    }
};