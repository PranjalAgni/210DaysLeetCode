/*
Spiral Matrix II

Solution
Given a positive integer n, generate an n x n matrix filled with elements from 1
to n2 in spiral order.



Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]


Constraints:

1 <= n <= 20
*/

// Simple O(N * N) solution
class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));

        int level = ceil(n / 2), count = 1;

        for (int l = 0; l <= level; ++l) {
            for (int a = l; a < n - l; ++a) result[l][a] = count++;

            for (int b = l + 1; b < n - l; ++b) result[b][n - l - 1] = count++;

            for (int c = l + 1; c < n - l; ++c)
                result[n - l - 1][n - c - 1] = count++;

            for (int d = l + 1; d < n - l - 1; ++d)
                result[n - d - 1][l] = count++;
        }

        return result;
    }
};