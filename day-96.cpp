/*
  Hamming Distance


The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/

// Easy problem using XOR operator
class Solution {
   public:
    int hammingDistance(int x, int y) {
        int answer = 0;

        // Using XOR operator
        // If two bits are same it returns 0
        // If two bits are different it returns 1
        while (x > 0 || y > 0) {
            answer += (x % 2) ^ (y % 2);
            x = x / 2;
            y = y / 2;
        }

        return answer;
    }
};