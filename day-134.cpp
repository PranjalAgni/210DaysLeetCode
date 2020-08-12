/*
  Pascal's Triangle II


Given a non-negative index k where k ≤ 33, return the kth index row of the
Pascal's triangle.

Note that the row index starts from 0.

Example:

Input: 3
Output: [1,3,3,1]
*/

// Simple O(row * col) approach
class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<int> answer(rowIndex + 1, 1);
        for (int row = 1; row < rowIndex; row++) {
            for (int col = row; col > 0; col--) {
                answer[col] += answer[col - 1];
            }
        }

        return answer;
    }
};