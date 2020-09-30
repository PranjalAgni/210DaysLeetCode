/*
First Missing Positive

Solution
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Follow up:

Your algorithm should run in O(n) time and uses constant extra space.
*/

// Solved using hashMap and single iteration
// beats 83% cpp solution

class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int N = nums.size();
        unordered_map<int, int> hashMap;

        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        for (int idx = 0; idx < N; idx++) {
            hashMap[nums[idx]] += 1;

            minVal = min(minVal, nums[idx]);
            maxVal = max(maxVal, nums[idx]);
        }

        if (minVal <= 0) minVal = 1;
        if (minVal > 1) return 1;

        for (int num = minVal; num <= maxVal; num++) {
            if (num > 0 && hashMap[num] == 0) return num;
        }

        return (maxVal < 0 ? 1 : maxVal + 1);
    }
};