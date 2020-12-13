/*
Burst Balloons

Solution
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number
on it represented by array nums. You are asked to burst all the balloons. If the
you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here
left and right are adjacent indices of i. After the burst, the left and right
then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not
burst them. 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100 Example:

Input: [3,1,5,8]
Output: 167
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

*/

// Solved using dynamic programming
// TC: O(N*N*N)
class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        vector<int> num{1};
        num.insert(num.end(), nums.begin(), nums.end());
        num.push_back(1);
        int sz = num.size();
        vector<vector<int>> dp(sz, vector<int>(sz));
        for (int i = 2; i < sz; ++i) {
            for (int j = i - 1; j >= 1; --j) {
                for (int k = j - 1; k >= 0; --k) {
                    dp[k][i] = max(dp[k][i], num[k] * num[j] * num[i] +
                                                 dp[k][j] + dp[j][i]);
                }
            }
        }
        return dp[0][sz - 1];
    }
};