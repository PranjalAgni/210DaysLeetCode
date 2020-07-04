/*
  Ugly Number II


Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.
*/

// DP solution to generate Ugly Number
class Solution {
   public:
    int nthUglyNumber(int n) {
        if (n == 0) return 1;

        vector<int> nums;

        nums.push_back(1);

        int i = 0;
        int j = 0;
        int k = 0;

        while (nums.size() <= n) {
            int numTwo = nums[i] * 2;

            int numThree = nums[j] * 3;

            int numFive = nums[k] * 5;

            int minNum = min({numTwo, numThree, numFive});

            nums.push_back(minNum);

            if (minNum == numTwo) i += 1;
            if (minNum == numThree) j += 1;
            if (minNum == numFive) k += 1;
        }

        return nums[n - 1];
    }
};