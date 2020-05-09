/*
Valid Perfect Square
Solution
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*/

// O(1) & O(1) beats 100% cpp solutions
class Solution {
   public:
    bool isPerfectSquare(int num) {
        double x = sqrt(num);
        if (x == floor(x)) return true;
        return false;
    }
};