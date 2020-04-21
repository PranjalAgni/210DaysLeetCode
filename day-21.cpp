/*
Question: This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

Example: 

Input: mat = [[0,0],[1,1]]
Output: 0

Input: mat = [[0,0],[0,1]]
Output: 1

Input: mat = [[0,0],[0,0]]
Output: -1

Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1
*/

// O(Rows + Cols) solution
class Solution {
   public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dims = binaryMatrix.dimensions();
        int rows = dims[0];
        int cols = dims[1];

        if (rows == 0 || cols == 0) return -1;

        int ans = -1;
        int r = 0;
        int c = cols - 1;

        while (r < rows && c >= 0) {
            int val = binaryMatrix.get(r, c);
            if (val == 0) {
                r += 1;
            } else {
                ans = c;
                if (ans == 0) return ans;
                c -= 1;
            }
        }
        return ans;
    };
};