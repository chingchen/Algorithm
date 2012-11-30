/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = prices.size();
        if(size == 0)
         return 0;
        int min= prices[0], max = 0;
        for(int i = 1 ; i < size ; i++)
        {
            if( prices[i] < prices[i-1])
            {             
             if( prices[i-1]- min > 0)
                max += prices[i-1]- min;
              min = prices[i];
             
            }
            else if( i == size -1)
             max += prices[i]-min;
        }
        return max;
    }
};