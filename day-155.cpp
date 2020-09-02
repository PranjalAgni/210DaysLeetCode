/*
  Contains Duplicate III


Given an array of integers, find out whether there are two distinct indices i
and j in the array such that the absolute difference between nums[i] and nums[j]
is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false

*/

// Solved using sliding window and bucket in O(N) time.
class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int N = nums.size();
        if (N == 0 || k < 0 || t < 0) return false;

        unordered_map<int, int> buckets;

        for (int idx = 0; idx < N; idx++) {
            int bucket = nums[idx] / ((long)t + 1);
            if (nums[idx] < 0) bucket -= 1;

            if (buckets.find(bucket) != buckets.end())
                return true;
            else {
                buckets[bucket] = nums[idx];
                if (buckets.find(bucket - 1) != buckets.end() &&
                    (long)nums[idx] - buckets[bucket - 1] <= t)
                    return true;

                if (buckets.find(bucket + 1) != buckets.end() &&
                    (long)buckets[bucket + 1] - nums[idx] <= t)
                    return true;

                if (buckets.size() > k) {
                    int removeKey = nums[idx - k] / ((long)t + 1);

                    if (removeKey < 0) removeKey -= 1;

                    buckets.erase(removeKey);
                }
            }
        }

        return false;
    }
};