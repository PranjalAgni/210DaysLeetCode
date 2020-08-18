/*
  Numbers With Same Consecutive Differences


Return all non-negative integers of length N such that the absolute difference
between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the
number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is
valid.

You may return the answer in any order.


Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]


Note:

1 <= N <= 9
0 <= K <= 9

*/

// Simple DFS based solution
// Nice trick of getting lastDigit with % and not passing, seperate param to
// function
class Solution {
   public:
    void numsSameConsecDiffDFS(vector<int>& answer, int N, int K,
                               int currentNumber) {
        if (N == 0) {
            answer.push_back(currentNumber);
            return;
        }

        int lastDig = currentNumber % 10;

        int nextNumAdd = lastDig + K;
        int nextNumSub = lastDig - K;

        if (nextNumAdd == nextNumSub)
            numsSameConsecDiffDFS(answer, N - 1, K,
                                  currentNumber * 10 + nextNumAdd);
        else {
            if (nextNumAdd < 10)
                numsSameConsecDiffDFS(answer, N - 1, K,
                                      currentNumber * 10 + nextNumAdd);
            if (nextNumSub > -1)
                numsSameConsecDiffDFS(answer, N - 1, K,
                                      currentNumber * 10 + nextNumSub);
        }
    }

    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> answer;
        if (N == 1) answer.push_back(0);

        for (int dig = 1; dig < 10; dig++) {
            numsSameConsecDiffDFS(answer, N - 1, K, dig);
        }

        return answer;
    }
};