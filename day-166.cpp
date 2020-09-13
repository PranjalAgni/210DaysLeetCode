/*
  Insert Interval


Given a set of non-overlapping intervals, insert a new interval into the
intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start
times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
NOTE: input types have been changed on April 15, 2019. Please reset to default
code definition to get new method signature.

*/

// Simple greedy solution, O(N) approach
class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> result;
        int idx = 0, N = intervals.size();
        while (idx < N && intervals[idx][1] < newInterval[0])
            result.push_back(intervals[idx++]);

        vector<int> inter = newInterval;
        while (idx < N && intervals[idx][0] <= newInterval[1]) {
            inter[0] = min(inter[0], intervals[idx][0]);
            inter[1] = max(inter[1], intervals[idx][1]);
            idx += 1;
        }

        result.push_back(inter);

        while (idx < N) result.push_back(intervals[idx++]);

        return result;
    }
};