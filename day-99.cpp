/*
3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

// Idea is to fix a number and then two apply 2-sum approach to get the set of number which are equal to 0
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int N = nums.size();
        vector<vector<int>> answer;

        for (int i = 0; i < N - 1; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int start = i + 1;
            int end = N - 1;

            bool lcheck = false;
            bool rcheck = false;
            while (start < end) {
                int target = nums[i] + nums[start] + nums[end];

                if (target == 0) {
                    answer.push_back({nums[i], nums[start], nums[end]});
                    end -= 1;
                    start += 1;
                    lcheck = true;
                } else if (target > 0) {
                    end -= 1;
                    rcheck = true;
                } else
                    start += 1;

                if (lcheck) {
                    while (start < end && nums[start - 1] == nums[start]) start += 1;
                }

                if (rcheck) {
                    while (start < end && nums[end + 1] == nums[end]) end -= 1;
                    rcheck = false;
                }
            }
        }
        return answer;
    }
};
