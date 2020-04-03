/*
Question: Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
*/

// O(N) & O(1) beat 99.8% cpp solutions
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum = max(sum + nums[i], nums[i]);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};