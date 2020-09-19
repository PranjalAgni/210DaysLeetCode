/*
  Sequential Digits


An integer has sequential digits if and only if each digit in the number is one
more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that
have sequential digits.



Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]


Constraints:

10 <= low <= high <= 10^9

*/

// O(N) solution, based on length of low number and high number
class Solution {
   public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> answer;
        string sequentialDigits = "123456789";
        int lowLen = to_string(low).length();
        int highLen = to_string(high).length();

        for (int len = lowLen; len <= highLen; len++) {
            for (int idx = 0; idx <= 9 - len; idx++) {
                string currentNum = sequentialDigits.substr(idx, len);
                int num = stoi(currentNum);
                if (num < low) continue;
                if (num > high) break;
                answer.push_back(num);
            }
        }

        return answer;
    }
};