/*
  Power of Four


Given an integer (signed 32 bits), write a function to check whether it is a
power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?


*/

// O(1) & O(1) solution beats 100% of cpp solutions
class Solution {
   public:
    bool isPowerOfFour(int num) {
        if (num == 0) return false;
        double expo = log(num) / log(4);
        if (ceil(expo) == floor(expo)) return true;
        return false;
    }
};