/*
  Permutations II


Given a collection of numbers, nums, that might contain duplicates, return all
possible unique permutations in any order.



Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> curr;
        unordered_map<int, int> counter;
        for (auto x : nums) ++counter[x];
        generatePermutations(counter, curr, output, size(nums));
        return output;
    }

   private:
    void generatePermutations(unordered_map<int, int>& counter,
                              vector<int>& curr, vector<vector<int>>& output,
                              int n) {
        if (size(curr) == n) {
            output.emplace_back(curr);
            return;
        }
        for (auto [key, value] : counter) {
            if (value == 0) continue;
            curr.emplace_back(key);
            --counter[key];
            generatePermutations(counter, curr, output, n);
            curr.pop_back();
            ++counter[key];
        }
    }
};