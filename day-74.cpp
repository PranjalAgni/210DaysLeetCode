/*
  Largest Divisible Subset


Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.


Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/

class Solution {
   public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();

        if (len <= 1) return nums;
        sort(nums.begin(), nums.end());

        vector<vector<int>> answer(len, vector<int>());
        int gmax = 1;
        int index = 0;

        for (int idx = len - 1; idx >= 0; idx--) {
            answer[idx].push_back(nums[idx]);
            int fwd_idx = idx + 1;
            int curr_max = 0;
            int curr_max_idx = idx;
            while (fwd_idx < len) {
                if (nums[fwd_idx] % nums[idx] == 0 && answer[fwd_idx].size() > curr_max) {
                    curr_max = answer[fwd_idx].size();
                    curr_max_idx = fwd_idx;
                }

                fwd_idx += 1;
            }

            if (curr_max_idx != idx) {
                answer[idx].insert(answer[idx].end(), answer[curr_max_idx].begin(), answer[curr_max_idx].end());
                if (curr_max + 1 > gmax) {
                    gmax = curr_max + 1;
                    index = idx;
                }
            }
        }

        return answer[index];
    }
};