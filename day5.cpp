/*
Question: Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
*/

// O(N) & O(1) beats 97.60% of cpp submissions
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                max += prices[i] - prices[i - 1];
            }
        }

        return max;
    }
};

/*Solution for if we had asked only to buy and sell 1 stock*/

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int min = INT_MAX; // min value found till now
//         int maxProfit = 0; // max profit we made till now

//         for (int i = 0; i < prices.size(); i++) {
//             if (prices[i] < min) {
//                 min = prices[i]; // if pr[i] is lt min update min
//             } else {
//                 maxProfit = max(maxProfit, prices[i] - min); // if pr[i] is gte min then calculate max
//             }
//         }

//         return maxProfit;
//     }
// };