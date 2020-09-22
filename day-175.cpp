/*
  Majority Element II


Given an integer array of size n, find all elements that appear more than ⌊ n/3
⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/

// Simple O(N) & O(N) solution
class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashMap;

        int N = nums.size();
        int threshold = N / 3;

        vector<int> answer;
        for (int idx = 0; idx < nums.size(); idx++) {
            hashMap[nums[idx]] += 1;
        }

        for (auto& map : hashMap) {
            if (map.second > threshold) answer.push_back(map.first);
        }

        return answer;
    }
};