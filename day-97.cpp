/*
  Plus One


Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

*/

// Simple logic building question
class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int N = digits.size() - 1;

        if (digits[N] != 9) {
            digits[N] += 1;
            return digits;
        }

        list<int> sumList;
        int prevCarry = 0;

        for (int i = N; i >= 0; i--) {
            int currCarry = 0;
            int currSum = digits[i] + prevCarry;
            if (i == N) currSum += 1;
            prevCarry = 0;
            if (currSum > 9) {
                currSum = 0;
                currCarry = 1;
            }

            prevCarry = currCarry;
            sumList.push_front(currSum);
        }

        if (prevCarry == 1) sumList.push_front(1);

        vector<int> answer(sumList.begin(), sumList.end());

        return answer;
    }
};