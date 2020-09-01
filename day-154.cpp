/*
  Largest Time for Given Digits


Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from
00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return
an empty string.



Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""


Note:

A.length == 4
0 <= A[i] <= 9
*/

// Simple O(64) solution, using bruteforce to generate all the possible
// solutions and returning thr largest one
class Solution {
   public:
    string largestTimeFromDigits(vector<int>& A) {
        string answer = "";
        for (int idx = 0; idx < A.size(); idx++) {
            for (int jdx = 0; jdx < A.size(); jdx++) {
                for (int kdx = 0; kdx < A.size(); kdx++) {
                    if (idx == jdx || jdx == kdx || kdx == idx) continue;
                    string hours = to_string(A[idx]) + to_string(A[jdx]);
                    string minutes =
                        to_string(A[kdx]) + to_string(A[6 - idx - jdx - kdx]);
                    string currTime = hours + ":" + minutes;
                    if (hours < "24" && minutes < "60" && currTime > answer)
                        answer = currTime;
                }
            }
        }

        return answer;
    }
};