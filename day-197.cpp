/*
  House Robber II


You are a professional robber planning to rob houses along a street. Each house
has a certain amount of money stashed. All houses at this place are arranged in
a circle. That means the first house is the neighbor of the last one. Meanwhile,
adjacent houses have a security system connected, and it will automatically
contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers nums representing the amount of money of
each house, return the maximum amount of money you can rob tonight without
alerting the police.



Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money =
2), because they are adjacent houses. Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [0]
Output: 0


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000


*/

// Simple O(N) solution
class Solution {
   public:
    int houseRobber(vector<int>& nums) {
        // dynamic programming - decide each problem by its sub-problems:
        int dp[nums.size() + 1];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        return dp[nums.size() - 1];
    }

    int rob(vector<int>& nums) {
        // edge cases:
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        // either use first house and can't use last or last and not first:
        vector<int> v1(nums.begin(), nums.end() - 1);
        vector<int> v2(nums.begin() + 1, nums.end());
        return max(houseRobber(v1), houseRobber(v2));
    }
};