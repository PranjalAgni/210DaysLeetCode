/*
Power of Two

Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false

*/

// Simple log approach
class Solution {
   public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        double x = log2(n);
        if (floor(x) == ceil(x)) return true;
        return false;
    }
};
