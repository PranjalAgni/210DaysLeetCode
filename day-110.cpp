/*
  Add Binary


Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/

// Simple O(N) & O(1) approach to solve the problem
class Solution {
   public:
    char doSum(int digA, int digB, int& carry) {
        if (digA == 1 && digB == 1 && carry == 1) {
            carry = 1;
            return '1';
        } else if ((digA == 1 || digB == 1) && carry == 1) {
            carry = 1;
            return '0';
        } else if (digA == 1 && digB == 1 && carry == 0) {
            carry = 1;
            return '0';
        } else if (digA == 0 && digB == 0 && carry == 0) {
            carry = 0;
            return '0';
        } else {
            carry = 0;
            return '1';
        }
    }

    string addBinary(string a, string b) {
        int lenA = a.size() - 1;
        int lenB = b.size() - 1;

        string result = "";
        int prevCarry = 0;

        while (lenA >= 0 && lenB >= 0) {
            int digA = a[lenA] - '0';
            int digB = b[lenB] - '0';
            char currSum = doSum(digA, digB, prevCarry);
            result = currSum + result;
            lenA -= 1;
            lenB -= 1;
        }

        while (lenA >= 0) {
            int digA = a[lenA] - '0';
            char currSum = doSum(digA, 0, prevCarry);
            result = currSum + result;
            lenA -= 1;
        }

        while (lenB >= 0) {
            int digB = b[lenB] - '0';
            char currSum = doSum(0, digB, prevCarry);
            result = currSum + result;
            lenB -= 1;
        }

        if (prevCarry) {
            result = '1' + result;
        }

        return result;
    }
};