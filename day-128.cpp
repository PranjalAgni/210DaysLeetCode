/*
  Find All Duplicates in an Array


Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

// Solved using O(N) & O(1) approach
class Solution {
   public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answers;
        for (int idx = 0; idx < nums.size(); idx++) {
            int currIdx = abs(nums[idx]) - 1;
            int currElt = nums[currIdx];
            if (currElt < 0) answers.push_back(abs(nums[idx]));
            nums[currIdx] *= -1;
        }

        return answers;
    }
};