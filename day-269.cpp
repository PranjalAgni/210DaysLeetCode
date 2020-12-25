/*
Diagonal Traverse

Solution
Given a matrix of M x N elements (M rows, N columns), return all elements of the
matrix in diagonal order as shown in the below image.



Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:



Note:

The total number of elements of the given matrix will not exceed 10,000.
*/

// Simple O(row * col) solution

class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        int n = matrix.size();
        int m = n ? matrix[0].size() : 0;
        int x = -1, y = 1;
        vector<int> res;
        while (res.size() < n * m) {
            if (i == n || j == m || j < 0 || i < 0) {
                swap(x, y);

                if (j == m)

                    i += 2, j--;
                else if (i == n)
                    j += 2, i--;
                else {
                    i += i < 0;
                    j += j < 0;
                }
            }
            res.push_back(matrix[i][j]);
            i += x;
            j += y;
        }
        return res;
    }
};