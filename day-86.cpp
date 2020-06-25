/*  
Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

// O(N) solution based on idea of using index as elements
// Example: [1,3,4,2,2]
// treat array elements as index of array
// when you first time visit the element make it negative
// And the second time that -ve element will be converted to +ve
// Fact is only duplicate element will be turned +ve others all will be -ve

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int idx = nums[i];
            if (nums[abs(idx)] < 0) return abs(idx);
            nums[abs(idx)] *= -1;
        }

        return -1;
    }
};