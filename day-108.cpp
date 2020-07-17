/*
  Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.

*/

// Used unordered_map + max-heap to solve the problem
class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;

        for (int elt : nums) {
            hashMap[elt] += 1;
        }

        priority_queue<pair<int, int>> que;

        vector<int> answer(k);

        for (auto& map : hashMap) {
            que.push({map.second, map.first});
        }

        for (int i = 0; i < k; i++) {
            answer[i] = que.top().second;
            que.pop();
        }

        return answer;
    }
};