/*
  Best Time to Buy and Sell Stock with Cooldown


Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]

*/

// Using recursion + caching (using map) to calculate maximum profit
class Solution {
   public:
    int maxProfitUtil(int currStockIdx, int currStrategy, vector<int>& prices, map<pair<int, int>, int>& hashMap) {
        if (currStockIdx >= prices.size()) return 0;

        pair<int, int> key = make_pair(currStockIdx, currStrategy);
        if (hashMap.count(key)) return hashMap[key];

        int maxProfitAmt = 0;

        if (currStrategy == 0) {
            int buy = maxProfitUtil(currStockIdx + 1, 1, prices, hashMap) - prices[currStockIdx];
            int notBuy = maxProfitUtil(currStockIdx + 1, 0, prices, hashMap);
            maxProfitAmt = max(buy, notBuy);
        } else {
            int sell = maxProfitUtil(currStockIdx + 2, 0, prices, hashMap) + prices[currStockIdx];
            int notSell = maxProfitUtil(currStockIdx + 1, 1, prices, hashMap);
            maxProfitAmt = max(sell, notSell);
        }

        hashMap[key] = maxProfitAmt;

        return maxProfitAmt;
    }

    int maxProfit(vector<int>& prices) {
        map<pair<int, int>, int> hashMap;
        return maxProfitUtil(0, 0, prices, hashMap);
    }
};
