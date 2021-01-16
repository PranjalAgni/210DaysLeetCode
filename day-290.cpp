/*
Kth Largest Element in an Array

Solution
Find the kth largest element in an unsorted array. Note that it is the kth
largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.


*/

// Simple O(N) solution
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        while (pq.empty() == false and k > 1) {
            pq.top();
            pq.pop();
            k--;
        }
        return pq.top();
    }
};