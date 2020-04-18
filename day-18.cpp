/*
Question: Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

// O(N) & O(1) beats 85% of cpp solutions

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 1; i < grid.size(); ++i) {
            grid[i][0] += grid[i - 1][0];
        }

        for (int i = 1; i < grid[0].size(); ++i) {
            grid[0][i] += grid[0][i - 1];
        }

        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[i].size(); ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};