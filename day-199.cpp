/*
  Search a 2D Matrix


Write an efficient algorithm that searches for a value in an m x n matrix. This
matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous
row.


Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
Output: false
Example 3:

Input: matrix = [], target = 0
Output: false


Constraints:

m == matrix.length
n == matrix[i].length
0 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

*/

// Simple approach using binary search on both rows and cols
// Time Complexity O(rows + cols)

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) return false;

        int row = 0;
        int cols = matrix[0].size() - 1;

        while (row < rows && cols >= 0) {
            if (matrix[row][cols] == target)
                return true;
            else if (target < matrix[row][cols])
                cols -= 1;
            else
                row += 1;
        }

        return false;
    }
};