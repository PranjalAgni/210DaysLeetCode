/*
  Maximum Product Subarray


Given an integer array nums, find the contiguous subarray within an array
(containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

// Simple O(N) solution, to find the maximum subarray
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int currentMax = nums[0];
        int currentMin = nums[0];

        int finalMaxProd = nums[0];
        for (int idx = 1; idx < nums.size(); idx++) {
            if (nums[idx] < 0) swap(currentMax, currentMin);

            currentMax = max(nums[idx], currentMax * nums[idx]);
            currentMin = min(nums[idx], currentMin * nums[idx]);
            finalMaxProd = max(currentMax, finalMaxProd);
        }

        return finalMaxProd;
    }
};