/*
  Number of Longest Increasing Subsequence


Given an integer array nums, return the number of longest increasing
subsequences.



Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3,
5, 7]. Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and
there are 5 subsequences' length is 1, so output 5.



*/

// DP solution to calculate maximum
class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        int N = nums.size(), lis_len = 1, res = 0;
        vector<int> len(N, 1), dp(N, 1);
        for (int i = 1; i < N; i++)
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        dp[i] = dp[j];
                    } else if (len[j] + 1 == len[i])
                        dp[i] += dp[j];
                }
                lis_len = max(lis_len, len[i]);
            }
        for (int i = 0; i < N; i++) {
            if (len[i] == lis_len) res += dp[i];
        }

        return res;
    }
};
