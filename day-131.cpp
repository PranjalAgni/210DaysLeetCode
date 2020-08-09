/*
  Rotting Oranges


In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten
orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh
orange.  If this is impossible, return -1 instead.

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never
rotten, because rotting only happens 4-directionally. Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, th
*/

// Simple BFS approach
// First created a set for rotten oranges and counted number of fresh oranges
// position Now until freshOranges are there Iterating in rotten oranges,
// finding the neighbours and infecting them If there was no oranges infected,
// then return -1 else continue infecting and incrementing the minutes.
class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int numFreshOranges = 0;
        set<pair<int, int>> rottenOranges;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1) numFreshOranges += 1;
                if (grid[row][col] == 2) rottenOranges.insert({row, col});
            }
        }

        if (!numFreshOranges) return 0;
        int minutes = 0;
        while (numFreshOranges > 0) {
            set<pair<int, int>> infected;
            for (auto rotten : rottenOranges) {
                vector<vector<int>> directions{
                    {0, -1}, {0, 1}, {-1, 0}, {1, 0}};
                for (vector<int> dir : directions) {
                    int curr_row = rotten.first + dir[0];
                    int curr_col = rotten.second + dir[1];
                    if ((curr_row >= 0 && curr_row < rows) &&
                        (curr_col >= 0 && curr_col < cols)) {
                        if (grid[curr_row][curr_col] == 1) {
                            numFreshOranges -= 1;
                            grid[curr_row][curr_col] = 2;
                            infected.insert({curr_row, curr_col});
                        }
                    }
                }
            }
            if (infected.size() == 0) return -1;
            rottenOranges = infected;
            minutes += 1;
        }

        return minutes;
    }
};