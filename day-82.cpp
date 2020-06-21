/*
  Dungeon Game


The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
*/

// Solved it using bottom-up DP O(rows*cols)
class Solution {
   public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();

        int cols = dungeon[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols));

        dp[rows - 1][cols - 1] = dungeon[rows - 1][cols - 1] > 0 ? 1 : 1 - dungeon[rows - 1][cols - 1];

        for (int i = rows - 2; i >= 0; i--) {
            dp[i][cols - 1] = max(dp[i + 1][cols - 1] - dungeon[i][cols - 1], 1);
        }

        for (int i = cols - 2; i >= 0; i--) {
            dp[rows - 1][i] = max(dp[rows - 1][i + 1] - dungeon[rows - 1][i], 1);
        }

        for (int i = rows - 2; i >= 0; i--) {
            for (int j = cols - 2; j >= 0; j--) {
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
            }
        }

        return dp[0][0];
    }
};