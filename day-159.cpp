/*
  Image Overlap


Two images A and B are given, represented as binary, square matrices of the same
size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down
any number of units), and place it on top of the other image.  After, the
overlap of this translation is the number of positions that have a 1 in both
images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.
Notes:

1 <= A.length = A[0].length = B.length = B[0].length <= 30
0 <= A[i][j], B[i][j] <= 1

*/

// Sliding window by (N - 1) in every direction (top,down,right,left)
// Beats 93.98 % of cpp submissions.

class Solution {
   public:
    int shiftCount(vector<vector<int>>& A, vector<vector<int>>& B) {
        int N = A.size();
        int count = 0;

        for (int idx = 0; idx < N; idx++) {
            for (int jidx = 0; jidx < N; jidx++) {
                int temp = 0;
                for (int x = jidx; x < N; x++) {
                    for (int y = idx; y < N; y++) {
                        if (A[x][y] == 1 && B[x - jidx][y - idx] == 1)
                            temp += 1;
                    }
                }

                count = max(count, temp);
            }
        }

        return count;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        return max(shiftCount(A, B), shiftCount(B, A));
    }
};