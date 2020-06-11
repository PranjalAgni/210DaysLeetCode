/*

  Sort Colors

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?

*/

// Idea is to keep pointer for zero's and two's,
// and whenever we get a zero we swap with zeroPtr
// and when we get a two we swap with twoPtr

// This is 1 pass O(N) & O(1) solution.
class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int index = 0;
        int zeroPtr = 0;
        int twoPtr = nums.size() - 1;

        while (index <= twoPtr) {
            if (nums[index] == 0) {
                nums[index] = nums[zeroPtr];
                nums[zeroPtr] = 0;
                zeroPtr += 1;
                index += 1;
            } else if (nums[index] == 2) {
                nums[index] = nums[twoPtr];
                nums[twoPtr] = 2;
                twoPtr -= 1;
            } else {
                index += 1;
            }
        }
    }
};