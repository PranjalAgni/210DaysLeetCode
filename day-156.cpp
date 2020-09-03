/*
  Repeated Substring Pattern


Given a non-empty string check if it can be constructed by taking a substring of
it and appending multiple copies of the substring together. You may assume the
given string consists of lowercase English letters only and its length will not
exceed 10000.



Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc"
twice.)

*/

// Simple approach having time complexity of O(N * K) where K is number of times
// we append the same string
class Solution {
   public:
    bool repeatedSubstringPattern(string s) {
        int N = s.size();
        if (N == 1) return false;
        int half = N / 2;
        if (N % 2 == 0) half -= 1;
        for (int idx = 0; idx <= half; idx++) {
            string current = s.substr(0, half - idx + 1);
            int times = N / current.size();
            string result = "";
            while (times-- > 0) {
                result += current;
            }

            if (s == result) return true;
        }

        return false;
    }
};