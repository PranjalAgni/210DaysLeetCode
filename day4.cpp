/*
Question: Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Examples:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

// O(N) & O(1) beats 99.88% cpp solution
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[idx++] = nums[i];
            }
        }

        for (int pending = idx; pending < nums.size(); pending++) nums[pending] = 0;
    }
};