/*
  Non-overlapping Intervals


Given a collection of intervals, find the minimum number of intervals you need
to remove to make the rest of the intervals non-overlapping.



Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals
non-overlapping. Example 3:

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already
non-overlapping.

*/

// Simple sorting based solution O(N * logN)
class Solution {
    struct Comp {
        bool operator()(const vector<int>& first, const vector<int>& second) {
            return (first[0] < second[0]);
        }
    };

   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return 0;
        sort(intervals.begin(), intervals.end(), Comp());

        int count = 0;
        int lastIncluded = 0;

        for (int idx = 1; idx < intervals.size(); idx++) {
            if (intervals[idx][0] < intervals[lastIncluded][1]) {
                count += 1;
                if (intervals[idx][1] < intervals[lastIncluded][1])
                    lastIncluded = idx;
            } else {
                lastIncluded = idx;
            }
        }

        return count;
    }
};