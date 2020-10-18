/*
  Best Time to Buy and Sell Stock IV


You are given an integer array prices where prices[i] is the price of a given
stock on the ith day.

Design an algorithm to find the maximum profit. You may complete at most k
transactions.

Notice that you may not engage in multiple transactions simultaneously (i.e.,
you must sell the stock before you buy again).



Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit =
4-2 = 2. Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit =
6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit =
3-0 = 3.


Constraints:

0 <= k <= 109
0 <= prices.length <= 104
0 <= prices[i] <= 1000

*/

// Solved using DP
class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (!k || len < 2) return 0;
        k = min(k * 2, len - len % 2);
        int dp[k];
        for (int i = 0; i < k; i++) dp[i] = i % 2 ? 0 : INT_MAX;
        for (int currPrice : prices) {
            dp[0] = min(dp[0], currPrice);
            for (int i = 1; i < k; i++) {
                dp[i] = i % 2 ? max(dp[i], currPrice - dp[i - 1])
                              : min(dp[i], currPrice - dp[i - 1]);
            }
        }
        return dp[k - 1];
    }
};