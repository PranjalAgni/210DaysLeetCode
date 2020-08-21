/*
  Sort Array By Parity


Given an array A of non-negative integers, return an array consisting of all the
even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.



Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.


Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000

*/

// Used two pointer approach to solve this. Beats 88.19 % of cpp submissions.
class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int evenIndex = 0;
        int oddIndex = A.size() - 1;

        while ((evenIndex < oddIndex) && oddIndex >= 0) {
            int currentElt = A[evenIndex];
            if ((currentElt & 1) == 1) {
                int lastElt = A[oddIndex];
                while ((lastElt & 1) == 1) {
                    oddIndex -= 1;
                    if (oddIndex < 0 || oddIndex < evenIndex) break;
                    lastElt = A[oddIndex];
                }

                if (oddIndex >= 0 && evenIndex < oddIndex) {
                    A[evenIndex] = lastElt;
                    A[oddIndex] = currentElt;
                    oddIndex -= 1;
                }
            }

            evenIndex += 1;
        }

        return A;
    }
};