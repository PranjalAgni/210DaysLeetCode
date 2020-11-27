/*
  Partition Equal Subset Sum


Given a non-empty array nums containing only positive integers, find if the
array can be partitioned into two subsets such that the sum of elements in both
subsets is equal.



Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100

*/

// Solved using dynamic programming
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto a : nums) sum += a;

        if (sum % 2) return false;
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for (auto a : nums) {
            for (int i = sum; i >= a; i--) {
                dp[i] = dp[i] || dp[i - a];
            }
        }
        return dp[sum];
    }
};