/*
Question: Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).
*/

// O(N) & O(1)
class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int zeroes = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                prod *= nums[i];
            else
                zeroes += 1;
        }

        vector<int> ans(nums.size(), 0);

        if (zeroes > 1) return ans;
        for (int i = 0; i < nums.size(); i++) {
            if (zeroes == 0) {
                ans[i] = prod / nums[i];
            } else {
                if (nums[i] != 0)
                    ans[i] = 0;
                else
                    ans[i] = prod;
            }
        }

        return ans;
    }
};