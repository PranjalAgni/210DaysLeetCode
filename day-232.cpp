/*
  Merge Intervals


Given an array of intervals where intervals[i] = [starti, endi], merge all
overlapping intervals, and return an array of the non-overlapping intervals that
cover all the intervals in the input.



Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104


*/

// Linear scan solution + sorting
// Time complexity = O(N * logN)

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int N = intervals.size();
        vector<vector<int>> answer;
        for (int idx = 0; idx < N; idx++) {
            vector<int> interval = intervals[idx];
            if (answer.empty() || interval[0] > answer.back()[1])
                answer.push_back(interval);
            else
                answer.back()[1] = max(answer.back()[1], interval[1]);
        }

        return answer;
    }
};