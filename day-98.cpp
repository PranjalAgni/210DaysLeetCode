/*
  Island Perimeter


You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:



*/

class Solution {
   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        if (cols == 0) return 0;

        int land = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 0) continue;

                land += 4;

                vector<pair<int, int>> dirs = {{row, col - 1}, {row - 1, col}};

                for (pair<int, int> d : dirs) {
                    if ((d.first >= 0 && d.first < rows) && (d.second >= 0 && d.second < cols) && grid[d.first][d.second] == 1) {
                        land -= 2;
                    }
                }
            }
        }

        return land;
    }
};