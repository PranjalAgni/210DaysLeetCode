/*
Question: Maximal Square
Solution
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();

        if (cols == 0) return 0;

        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int height = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 || j == 0) {
                    if (matrix[i][j] == '1') {
                        dp[i][j] = 1;
                        height = max(height, dp[i][j]);
                    }
                } else {
                    if (matrix[i][j] == '1') {
                        dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                        height = max(height, dp[i][j]);
                    }
                }
            }
        }

        return height * height;
    }
};