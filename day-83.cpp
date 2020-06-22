/*
  Single Number II


Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

// O(N) & O(1) solution beats 93.19 % of cpp submissions.

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int ones = 0;
        int twos = 0;
        int not_threes;

        for (int i = 0; i < len; i++) {
            int curr = nums[i];

            twos |= ones & curr;
            ones ^= curr;
            not_threes = ~(ones & twos);
            ones &= not_threes;
            twos &= not_threes;
        }

        return ones;
    }
};