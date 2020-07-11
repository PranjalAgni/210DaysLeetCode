/*
  Subsets

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

// Recursive solution to make subsets
class Solution {
   public:
    void subsetsHelper(vector<int>& nums, int idx, vector<vector<int>>& answer) {
        if (idx == nums.size() - 1) {
            answer.push_back({nums[idx]});
            answer.push_back({});
        } else {
            subsetsHelper(nums, idx + 1, answer);
            int N = answer.size();
            for (int i = 0; i < N; i++) {
                vector<int> curr = answer[i];
                curr.push_back(nums[idx]);
                answer.push_back(curr);
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        if (!nums.size()) return {{}};

        vector<vector<int>> answer;

        subsetsHelper(nums, 0, answer);

        return answer;
    }
};