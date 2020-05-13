/**
 Question: Write an algorithm to determine if a number is "happy".

 A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
**/

// O(N) & O(N)
class Solution {
   public:
    bool isHappy(int n) {
        map<int, int> hashMap;
        hashMap[n] = 1;
        int result = 0;

        while (result != 1 && n != 1) {
            result = 0;
            while (n != 0) {
                int digit = n % 10;
                result += (digit * digit);
                n /= 10;
            }
            n = result;
            if (hashMap[n] == 1) {
                result = -1;
                break;
            }
            hashMap[n] = 1;
        }

        if (result == -1) return false;
        return true;
    }
};