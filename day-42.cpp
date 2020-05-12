/*
Single Element in a Sorted Array


You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

 

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.
*/

/*
Idea: If you notice the array, all the elements before the required element have first occurence on even index (0,2,...) and all the elements after the required element have first occurence on odd index
(1,3,....)
Also notice that given array length will be always odd because there will always be a element which is single.
*/

// O(log N) & O(1) solution
class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (low == high) break;

            if (mid % 2 == 0) {
                if (nums[mid + 1] == nums[mid]) {
                    low = mid + 2;
                } else {
                    high = mid - 1;
                }
            } else {
                if (nums[mid - 1] == nums[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return nums[low];
    }
};