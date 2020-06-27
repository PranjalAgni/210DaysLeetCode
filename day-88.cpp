/*
  Perfect Squares


Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

// Simple DP solution
class Solution {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);

        for (int num = 1; num <= n; num++) {
            int minVal = num;

            int y = 1;
            int sq = 1;

            while (sq <= num) {
                minVal = min(minVal, 1 + dp[num - sq]);
                y += 1;
                sq = y * y;
            }

            dp[num] = minVal;
        }

        return dp[n];
    }
};