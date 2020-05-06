/*
Majority Element
Solution
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

// O(N) & O(1) solution -- I came about to know this solution from CTCI book
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int counter = 0;
        int guessMajorityElt;
        for (int i = 0; i < nums.size(); i++) {
            if (counter == 0) {
                counter += 1;
                guessMajorityElt = nums[i];
            } else if (guessMajorityElt == nums[i]) {
                counter += 1;
            } else {
                counter -= 1;
            }
        }

        return guessMajorityElt;
    }
};
